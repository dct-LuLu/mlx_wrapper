/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:17 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/07 10:19:26 by jaubry--         ###   ########lyon.fr   */
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

# ifndef WIDTH
#  define WIDTH 500
# endif
# ifndef HEIGHT
#  define HEIGHT 500
# endif

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

typedef struct s_mlx
{
	t_xvar			*mlx;
	t_win_list		*win;
	t_img_data		img;
	t_vec2i			origin;
	t_vec2i			size;
}					t_mlx;

t_mlx	*init_mlx(const int width, const int height, char *title);

void	kill_img(t_xvar *mlx, t_img_data *img);

//drawing functions
void		ft_mlx_pixel_put(t_img_data *img, const t_vec2i pos,
				const int color);

void		ft_mlx_safe_pixel_put(t_img_data *img, const t_vec2i pos,
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

void		ft_mlx_line_put(t_img_data *img, t_vec2i a, t_vec2i b,
				const int color);

void		ft_mlx_horizontal_line(t_img_data *img, const int xpt[2],
				const int y, const int color);

void		ft_mlx_batch_put(t_img_data *img, const t_vec2i pos,
			const t_vec2i size, const int color);

void		ft_mlx_circle_put(t_img_data *img, const t_vec2i center,
				const int radius, const int color);

void		ft_mlx_draw_quadratic_curve(t_img_data *img,
				const t_vec2i *pts, const int color);


#endif // MLX_WRAPPER_H
