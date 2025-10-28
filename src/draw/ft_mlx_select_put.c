/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_select_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:32:41 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/21 00:27:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static inline void	horz_select(t_img_data *img, t_vec2i x, const int y,
		const t_rgb_int color)
{
	int	incr;
	int	dot;

	incr = 10;
	dot = 5;
	if (x.data[0] > x.data[1])
	{
		incr = -incr;
		dot = -dot;
	}
	while (true)
	{
		if ((incr > 0) && (x.data[0] > x.data[1]))
			return ;
		else if ((incr < 0) && (x.data[0] <= x.data[1]))
			return ;
		if ((incr > 0) && ((x.data[0] + dot) > x.data[1]))
			dot = x.data[1] - x.data[0];
		else if ((incr < 0) && ((x.data[0] + dot) <= x.data[1]))
			dot = -(x.data[0] - x.data[1]);
		ft_mlx_hline_put(img, (int[2]){x.data[0], x.data[0] + dot}, y, color);
		x.data[0] += incr;
	}
}

static inline void	vert_select(t_img_data *img, t_vec2i y, const int x,
		const t_rgb_int color)
{
	int	incr;
	int	dot;

	incr = 10;
	dot = 5;
	if (y.data[0] > y.data[1])
	{
		incr = -incr;
		dot = -dot;
	}
	while (true)
	{
		if ((incr > 0) && (y.data[0] > y.data[1]))
			return ;
		else if ((incr < 0) && (y.data[0] <= y.data[1]))
			return ;
		if ((incr > 0) && ((y.data[0] + dot) > y.data[1]))
			dot = y.data[1] - y.data[0];
		else if ((incr < 0) && ((y.data[0] + dot) <= y.data[1]))
			dot = -(y.data[0] - y.data[1]);
		ft_mlx_vline_put(img, (int[2]){y.data[0], y.data[0] + dot}, x, color);
		y.data[0] += incr;
	}
}

#define SELECT_ALPHA 0x2F

void	ft_mlx_select_put(t_img_data *img, const t_vec2i a, const t_vec2i b,
		const t_rgb_int color)
{
	t_vec2i	top;
	t_vec2i	bot;
	t_vec2i	lef;
	t_vec2i	rig;

	top = vec2i(a.x, b.x);
	bot = vec2i(b.x, a.x);
	lef = vec2i(a.y, b.y);
	rig = vec2i(b.y, a.y);
	if ((a.x == b.x) && (a.y == b.y))
		return ;
	ft_mlx_aarec_aput(img, a, b, rgba_int(color.r, color.g, color.b, SELECT_ALPHA));
	horz_select(img, top, a.y, color);
	horz_select(img, bot, b.y, color);
	vert_select(img, lef, b.x, color);
	vert_select(img, rig, a.x, color);
}
