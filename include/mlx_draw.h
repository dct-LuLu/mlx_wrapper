/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:08:55 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/09 00:24:10 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DRAW_H
# define MLX_DRAW_H
# include "vectors.h"
# include "libft.h"

typedef struct s_img_data	t_img_data;

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

#endif//MLX_DRAW_H
