#include "mlx_wrapper.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

typedef struct s_loop_wrap
{
	int		(*loop)();
	void	*data;
	t_mlx	*mlx;	
}	t_loop_wrap;

static void	print_perfs(t_mlx *mlx)
{
	if (!DEBUG)
		printf("\033[H\033[J");
	printf("[FRAME %zu]\nFrame time:\t%zu μs\n", mlx->generation, mlx->frame_time);
	printf("Average:\t%zu μs\n\n", (mlx->total_time / mlx->generation));
	printf("Delta time:\t%f s\n\n", mlx->delta_time);
}

static void	compute_fps(t_mlx *mlx)
{
	static size_t	fps_counter = 0;
	static size_t	fps_total = 0;

	fps_counter++;
	fps_total += mlx->frame_time;
	if (fps_total >= 1000000)
	{
		mlx->fps = fps_counter * 1000000 / fps_total;
		fps_total = 0;
		fps_counter = 0;
	}
}

static int	loop_wrapper(t_loop_wrap *loop_data)
{
	static struct timeval	start;
	static struct timeval	stop;

	gettimeofday(&start, NULL);
	loop_data->loop(loop_data->data);
	gettimeofday(&stop, NULL);

	loop_data->mlx->frame_time = (stop.tv_sec - start.tv_sec) * 1000000
		+ stop.tv_usec - start.tv_usec;
	loop_data->mlx->delta_time = loop_data->mlx->frame_time / 1000000.0f;
	loop_data->mlx->total_time += loop_data->mlx->frame_time;
	loop_data->mlx->generation++;
	compute_fps(loop_data->mlx);
	if (PERF)
		print_perfs(loop_data->mlx);
	return (0);
}

/*
	Function to set and start the loop, will in between compute
	additional data like frame_time, fps and delta_time
*/
void start_mlx_loop(t_mlx *mlx, int (*loop)(), void *data)
{
	static t_loop_wrap	loop_wrap;

	loop_wrap.mlx = mlx;
	loop_wrap.loop = loop;
	loop_wrap.data = data;
	mlx_loop_hook(loop_wrap.mlx->mlx, loop_wrapper, &loop_wrap);
	mlx_loop(loop_wrap.mlx->mlx);
}
