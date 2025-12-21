/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:08:55 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/20 23:04:16 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DRAW_H
# define MLX_DRAW_H
# include "vectors.h"
# include "colors.h"
# include "libft.h"

typedef struct s_img_data	t_img_data;

// Pixel draw functions

void	ft_mlx_pixel_put(t_img_data *img, const t_vec2i pos,
			const t_rgb_int color);
void	ft_mlx_pixel_aput(t_img_data *img, const t_vec2i pos,
			const t_rgba_int color);

void	ft_mlx_safe_pixel_put(t_img_data *img, const t_vec2i pos,
			const t_rgb_int color);
void	ft_mlx_safe_pixel_aput(t_img_data *img, const t_vec2i pos,
			const t_rgba_int color);

// Line draw functions

void	ft_mlx_hline_put(t_img_data *img, const int xpt[2],
			const int y, const t_rgb_int color);
void	ft_mlx_hline_aput(t_img_data *img, const int xpt[2],
			const int y, const t_rgba_int color);

void	ft_mlx_vline_put(t_img_data *img, const int ypt[2],
			const int x, const t_rgb_int color);
void	ft_mlx_vline_aput(t_img_data *img, const int ypt[2],
			const int x, const t_rgba_int color);

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}		t_line;

void	ft_mlx_line_put(t_img_data *img, t_vec2i a, t_vec2i b,
			const t_rgb_int color);
void	ft_mlx_line_aput(t_img_data *img, t_vec2i a, t_vec2i b,
			const t_rgba_int color);
void	ft_mlx_line_aputf(t_img_data *img, t_vec2i p[2],
			int x, t_rgba_int color);

// Rec draw functions

// deprecated ?
void	ft_mlx_batch_put(t_img_data *img, const t_vec2i pos,
			const t_vec2i size, const t_rgb_int color);
void	ft_mlx_batch_aput(t_img_data *img, const t_vec2i pos,
			const t_vec2i size, const t_rgba_int color);

void	ft_mlx_out_aarec_put(t_img_data *img, const t_vec2i pos_a,
			const t_vec2i pos_b, const t_rgb_int color);
void	ft_mlx_out_aarec_aput(t_img_data *img, const t_vec2i pos_a,
			const t_vec2i pos_b, const t_rgba_int color);

void	ft_mlx_aarec_put(t_img_data *img, const t_vec2i pos_a,
			const t_vec2i pos_b, const t_rgb_int color);
void	ft_mlx_aarec_aput(t_img_data *img, const t_vec2i pos_a,
			const t_vec2i pos_b, const t_rgba_int color);

// Curves draw functions

void	ft_mlx_out_circle_put(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgb_int color);
void	ft_mlx_out_circle_aput(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgba_int color);

void	ft_mlx_circle_put(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgb_int color);
void	ft_mlx_circle_aput(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgba_int color);
void	ft_mlx_safe_circle_put(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgb_int color);
void	ft_mlx_safe_circle_aput(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgba_int color);

void	ft_mlx_quad_curve_put(t_img_data *img, const t_vec2i *pts,
			const t_rgb_int color);
void	ft_mlx_quad_curve_aput(t_img_data *img, const t_vec2i *pts,
			const t_rgba_int color);
void	ft_mlx_quarter_curve_aput(t_img_data *img, const t_vec2i *pts,
			const t_rgba_int color);

// Images draw functions

void	ft_mlx_img_put(t_img_data *mlx_img, const t_vec2i pos,
			t_img_data *img);

void	ft_mlx_img_aput(t_img_data *mlx_img, const t_vec2i pos,
			t_img_data *img);

void	ft_mlx_safe_img_put(t_img_data *mlx_img, const t_vec2i pos,
			t_img_data *img);

void	ft_mlx_safe_img_aput(t_img_data *mlx_img, const t_vec2i pos,
			t_img_data *img);

// Special draw functions

void	ft_mlx_select_put(t_img_data *img, const t_vec2i a, const t_vec2i b,
			const t_rgb_int color);

#endif//MLX_DRAW_H
