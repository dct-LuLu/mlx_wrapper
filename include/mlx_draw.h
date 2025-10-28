/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:08:55 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/27 10:54:53 by jaubry--         ###   ########.fr       */
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
void	ft_mlx_safe_circle_aput(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgba_int color);

void	ft_mlx_quad_curve_put(t_img_data *img, const t_vec2i *pts,
			const t_rgb_int color);
void	ft_mlx_quad_curve_aput(t_img_data *img, const t_vec2i *pts,
			const t_rgba_int color);
void	ft_mlx_quarter_curve_aput(t_img_data *img, const t_vec2i *pts,
			const t_rgba_int color);

// Special draw functions

void	ft_mlx_select_put(t_img_data *img, const t_vec2i a, const t_vec2i b,
			const t_rgb_int color);

typedef enum e_border_style
{
	NO_BORDER = 0,
	SOLID,
	DASHED
}	t_border_style;

typedef struct s_border
{
	uint8_t			size;// px
	t_rgba_int		color;
	t_border_style	style;
}					t_border;

typedef enum e_anchor
{
	CENTER,
	LT,
	TOP,
	RT,
	RIGHT,
	RB,
	BOTTOM,
	LB,
	LEFT
}	t_anchor;

typedef enum e_radius_style
{
	NO_RADIUS = 0,
	FULL_PERCENT,
	FULL_PX,
	LOCAL_PERCENT,
	LOCAL_PX
}	t_radius_style;

typedef struct s_radius
{
	t_radius_style	style;
	union
	{
		uint32_t	_mem;
		struct
		{
			uint8_t	lt;
			uint8_t	rt;
			uint8_t	lb;
			uint8_t	rb;
		};
		uint8_t	full;
	};
}	t_radius;

typedef struct s_corner
{
	union
	{
		struct
		{
			t_vec2i	horz;
			t_vec2i	corner;
			t_vec2i	vert;
			t_vec2i	in;
		};
		t_vec2i		_mem[4];
		t_vec2i		_mem3[3];
	};
	t_vec2i	xrec[2];
	t_vec2i	mrec[2];
}	t_corner;

typedef struct s_box
{
	t_vec2i		pos;
	t_anchor	anchor;
	t_vec2i		size;
	t_rgba_int	color;
	t_radius	radius;
	t_border	border;

	// program defined
	t_vec2		_half_size;
	t_vec2i		_mid;
	t_corner	_lt;
	t_corner	_rt;
	t_corner	_lb;
	t_corner	_rb;
}				t_box;

void	precompute_box_radius(t_box *box);
int		precompute_box(t_box *box);
void	draw_border(t_img_data *img, t_box box);
void	draw_box(t_img_data *img, t_box box);

#endif//MLX_DRAW_H
