/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:17 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/11 07:06:06 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <mlx_int.h>
# include "xcerrcal.h"
# include "mlxw_xcerrcal.h"
# include "mlx_draw.h"
# include "mlx_key_input.h"
# include "mlx_mouse_input.h"
# include "libft.h"
# include "vectors.h"

# ifndef DEBUG
#  define DEBUG 0
# endif//DEBUG

# ifndef WIDTH
#  define WIDTH 500
# endif//WIDTH

# ifndef HEIGHT
#  define HEIGHT 500
# endif//HEIGHT

# ifndef MAX_WIDTH
#  define MAX_WIDTH 500
# endif//MAX_WIDTH

# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 500
# endif//MAX_HEIGHT

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
	char			*name;
	t_img			*img;
	union
	{
		unsigned char	*pixel;	
		int				*addr;
	};
	int				byte_depth;
	int				line_len;
	int				width;
	int				height;
}					t_img_data;

typedef struct s_img_data t_texture;

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
	t_key_input		key_input;
	t_mouse_input	mouse_input;
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

void	ft_mlx_center_window(t_mlx *mlx_data);

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
