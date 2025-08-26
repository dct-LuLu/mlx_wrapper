/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:17 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/26 19:40:23 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H
# include "libft.h"
# include "vectors.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <mlx_int.h>

# ifndef DEBUG
#  define DEBUG 0
# endif//DEBUG

# ifndef WIDTH
#  define WIDTH 500
# endif//WIDTH

# ifndef HEIGHT
#  define HEIGHT 500
# endif//HEIGHT

# ifndef PERF
#  define PERF 0
# endif//PERF

# ifndef FULLSCREEN
#  define FULLSCREEN 0
# endif//FULLSCREEN

# ifndef WINDOWLESS
#  define WINDOWLESS 0
# endif//WINDOWLESS

# ifndef RESIZEABLE
#  define RESIZEABLE 0
# endif//RESIZEABLE

# define BACKGROUND 0x0F0000000

typedef struct s_img_data
{
	t_img			*img;
	int				*addr;
	int				byte_depth;
	int				line_len;
	int				endian;
	int				width;
	int				height;//to change
}					t_img_data;

/*		 Future implementation
typedef struct s_win
{
	t_win_list		*win;
	t_img_daa		img;
	t_vec2i			origin;
	t_vec2i			size;
	t_vec2i			half_size;
	bool			fullscreen;
}					t_win;
*/

typedef struct s_mlx
{
	t_xvar			*mlx;
//	t_win			*wins;
	t_win_list		*win;
	t_img_data		img;
	t_vec2i			origin;
	t_vec2i			size;
	t_vec2i			half_size; //enforce 2 multiple for size
	bool			fullscreen;
	size_t			frame_time;
	float			delta_time;
	size_t			total_time;
	size_t			generation;
	size_t			fps;
}					t_mlx;

t_mlx	*init_mlx(const int width, const int height, char *title);

void	kill_mlx(t_mlx *mlx);

void 	start_mlx_loop(t_mlx *mlx, int (*loop)(), void *data);

//drawing functions
void	ft_mlx_pixel_put(t_img_data *img, const t_vec2i pos,
			const int color);

void	ft_mlx_safe_pixel_put(t_img_data *img, const t_vec2i pos,
			const int color);

typedef struct s_line
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_line;

void	ft_mlx_line_put(t_img_data *img, t_vec2i a, t_vec2i b,
			const int color);

void	ft_mlx_horizontal_line(t_img_data *img, const int xpt[2],
			const int y, const int color);

void	ft_mlx_batch_put(t_img_data *img, const t_vec2i pos,
			const t_vec2i size, const int color);

void	ft_mlx_circle_put(t_img_data *img, const t_vec2i center,
			const int radius, const int color);

void	ft_mlx_draw_quadratic_curve(t_img_data *img,
			const t_vec2i *pts, const int color);

typedef struct MotifWmHints
{
	unsigned long	flags;
	unsigned long	functions;
	unsigned long	decorations;
	long			input_mode;
	unsigned long	status;
}					t_MotifWmHints;

int		mlx_ext_fullscreen(t_xvar *xvar, t_win_list *win, int fullscreen);

void	ft_disable_decorations(Display *d, Window w);

#endif // MLX_WRAPPER_H
