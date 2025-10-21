/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:53:18 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/21 08:12:14 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

/*
int	get_rpx(t_vec2i size, uint8_t radius)
{
	int	min_side;
	int	rps;

	min_side = size.x;
	if (size.y < min_side)
		min_side = size.y;
	rps = (radius * min_side) / 100;
	return (rpx);
}

float	get_perimeter(t_vec2i size, int rps)
{
	float	p;

	p = (2 * (size.x - 2 * rpx)) + (2 * (size.y - 2 * rpx));
	if (rpx > 0)
		p += 2 * PI * rpx;
	return (p);
}
*/

static inline void	draw_solid_border(t_img_data *img, t_box box)
{
	if (box.radius == 0)
		ft_mlx_out_aarec_aput(img, box._lt, box._rb, box.border.color);
	else
	{
		if (box.radius != 100)
		{
			t_vec2i	x_quartile = vec2i(box._lt.x + box._quartile_size.x,
				box._rt.x - box._quartile_size.x);
			t_vec2i	y_quartile = vec2i(box._lt.y + box._quartile_size.y,
				box._rb.y - box._quartile_size.y);
			ft_mlx_hline_aput(img, x_quartile.data, box._lt.y, box.border.color);
			ft_mlx_hline_aput(img, x_quartile.data, box._lb.y, box.border.color);
			ft_mlx_vline_aput(img, y_quartile.data, box._lt.x, box.border.color);
			ft_mlx_vline_aput(img, y_quartile.data, box._rt.x, box.border.color);
		}
		ft_mlx_quad_curve_aput(img, box._lt_corner, box.border.color);
		ft_mlx_quad_curve_aput(img, box._rt_corner, box.border.color);
		ft_mlx_quad_curve_aput(img, box._lb_corner, box.border.color);
		ft_mlx_quad_curve_aput(img, box._rb_corner, box.border.color);
	}
}

static inline void	draw_dashed_border(t_img_data *img, t_box box)
{
	(void)img;
	(void)box;
	/*
	int			r;
	float		p;
	float		step;
	float		len;
	float		t;

	r = get_rpx(size, o.radius);
	p = get_perimeter(size, r);
	len = p / 80.0f; // 40 dashes (approx)
	step = len * 2;
	t = 0;
	c = o.color;
	while (t < p)
	{
		t += step;
	}
	*/
}

static inline void	draw_border(t_img_data *img, t_box box)
{
	if ((box.border.style == NONE) || (box.border.size == 0))
		return ;
	else if (box.border.style == SOLID)
		draw_solid_border(img, box);
	else if (box.border.style == DASHED)
		draw_dashed_border(img, box);
}

static inline t_vec2i	get_anchor_pos(t_anchor anchor, t_vec2i pos, t_vec2i size)
{
	int	x;
	int	y;

	if ((anchor == CENTER) || (anchor == TOP) || (anchor == BOTTOM))
		x = pos.x - (size.x / 2);
	if ((anchor == CENTER) || (anchor == LEFT) || (anchor == RIGHT))
		y = pos.y - (size.y / 2);
	if ((anchor == LEFT) || (anchor == LT) || (anchor == LB))
		x = pos.x;
	if ((anchor == RIGHT) || (anchor == RT) || (anchor == RB))
		x = pos.x - size.x;
	if ((anchor == TOP) || (anchor == LT) || (anchor == RT))
		y = pos.y;
	if ((anchor == BOTTOM) || (anchor == LB) || (anchor == RB))
		y = pos.y - size.y;
	return (vec2i(x, y));
}

static inline void	set_box_corner(t_vec2i (*corner_data)[3], const t_vec2i corner,
		const uint32_t x_quartile, const uint32_t y_quartile)
{
	const t_vec2i	tmp[3] =
	{
		vec2i(x_quartile, corner.y),
		corner,
		vec2i(corner.x, y_quartile)
	};

	ft_memcpy(*corner_data, tmp, sizeof(tmp));
}

static inline void	precompute_box_border(t_box *box)
{
	box->_quartile_size = vec2_scale(vec2_itof(box->size), ((float)box->radius / 100.0f) / 2);
	printf("x%f y%f\n", box->_quartile_size.x, box->_quartile_size.y);
	printf("x%d y%d\n", box->size.x, box->size.y);
	box->_x_quartile = vec2((float)box->_lt.x + box->_quartile_size.x,
			(float)box->_rt.x - box->_quartile_size.x);
	box->_y_quartile = vec2((float)box->_lt.y + box->_quartile_size.y,
			(float)box->_rb.y - box->_quartile_size.y);
	set_box_corner(&box->_lt_corner, box->_lt, box->_x_quartile.data[0], box->_y_quartile.data[0]);
	set_box_corner(&box->_rt_corner, box->_rt, box->_x_quartile.data[1], box->_y_quartile.data[0]);
	set_box_corner(&box->_lb_corner, box->_lb, box->_x_quartile.data[0], box->_y_quartile.data[1]);
	set_box_corner(&box->_rb_corner, box->_rb, box->_x_quartile.data[1], box->_y_quartile.data[1]);
}

int	precompute_box(t_box *box)
{
	/*
	if (radius > 100)
		error;
	else if ((pos->x < 0) || (pos->y < 0))
		error;
	else if ((size->x < 0) || (size->y < 0))
		error;
	*/
	box->_lt = get_anchor_pos(box->anchor, box->pos, box->size);
	box->_rt = vec2i(box->_lt.x + box->size.x, box->_lt.y);
	box->_lb = vec2i(box->_lt.x, box->_lt.y + box->size.y);
	box->_rb = vec2i_add(box->_lt, box->size);
	box->_half_size = vec2_div_scalar(vec2_itof(box->size), 2);
	if (box->radius != 0)
		precompute_box_border(box);
	return (0);
}

static inline void	debug_corner(t_img_data *img, const t_vec2i corner[3])
{
	ft_mlx_circle_aput(img, corner[0], 3, rgba_int(255, 50, 255, 128));
	ft_mlx_circle_aput(img, corner[1], 7, rgba_int(255, 80, 255, 128));
	ft_mlx_circle_aput(img, corner[2], 3, rgba_int(255, 50, 255, 128));
}

static inline void	debug_box(t_img_data *img, t_box box)
{
	ft_mlx_circle_aput(img, box._rt, 5, rgba_int(255, 125, 255, 128));
	ft_mlx_circle_aput(img, box._lt, 5, rgba_int(255, 125, 255, 128));
	ft_mlx_circle_aput(img, box._rb, 5, rgba_int(255, 125, 255, 128));
	ft_mlx_circle_aput(img, box._lb, 5, rgba_int(255, 125, 255, 128));
	debug_corner(img, box._lt_corner);
	debug_corner(img, box._rt_corner);
	debug_corner(img, box._rb_corner);
	debug_corner(img, box._lb_corner);
}

void	draw_box(t_img_data *img, t_box box)
{
	if (box.size.x == 0 && box.size.y == 0)
		return ;
	draw_border(img, box);
	if (DEBUG)
		debug_box(img, box);
}
