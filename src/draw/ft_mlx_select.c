/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:32:41 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/16 00:53:08 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static inline void	horz_select(t_img_data *img, int x[2], const int y,
		const int color)
{
	int	incr;
	int	dot;

	incr = 10;
	dot = 5;
	if (x[0] > x[1])
	{
		incr = -incr;
		dot = -dot;
	}
	while (true)
	{
		if ((incr > 0) && (x[0] > x[1]))
			return ;
		else if ((incr < 0) && (x[0] <= x[1]))
			return ;
		if ((incr > 0) && (x[0] + dot > x[1]))
			dot = x[1] - x[0];
		else if ((incr < 0) && (x[0] + dot <= x[1]))
			dot = -(x[0] - x[1]);
		ft_mlx_hline(img, (int[2]){x[0], x[0] + dot}, y, color);
		x[0] += incr;
	}
}

static inline void	vert_select(t_img_data *img, int y[2], const int x,
		const int color)
{
	int	incr;
	int	dot;

	incr = 10;
	dot = 5;
	if (y[0] > y[1])
	{
		incr = -incr;
		dot = -dot;
	}
	while (true)
	{
		if ((incr > 0) && (y[0] > y[1]))
			return ;
		else if ((incr < 0) && (y[0] <= y[1]))
			return ;
		if ((incr > 0) && (y[0] + dot > y[1]))
			dot = y[1] - y[0];
		else if ((incr < 0) && (y[0] + dot <= y[1]))
			dot = -(y[0] - y[1]);
		ft_mlx_vline(img, (int[2]){y[0], y[0] + dot}, x, color);
		y[0] += incr;
	}
}

static inline int	ft_blend_colors(int dst, int src)
{
	int	a;
	int	r;
	int	g;
	int	b;
	int	da;
	int	dr;
	int	dg;
	int	db;

	a = (src >> 24) & 0xFF;
	r = (src >> 16) & 0xFF;
	g = (src >> 8) & 0xFF;
	b = src & 0xFF;
	da = 255 - a;
	dr = ((r * a) + (((dst >> 16) & 0xFF) * da)) / 255;
	dg = ((g * a) + (((dst >> 8) & 0xFF) * da)) / 255;
	db = ((b * a) + ((dst & 0xFF) * da)) / 255;
	return ((0xFF << 24) | (dr << 16) | (dg << 8) | db);
}

#define MIN 0
#define VAL 1
#define MAX 2

static inline void	ft_mlx_batch_puta(t_img_data *img, t_vec2i a, t_vec2i b,
		int c)
{
	int	y[3];
	int	x[3];
	int	dst_c;

	x[MIN] = min(a.x, b.x);
	x[MAX] = max(a.x, b.x);
	y[MIN] = min(a.y, b.y);
	y[MAX] = max(a.y, b.y);
	y[VAL] = y[MIN];
	while (y[VAL] <= y[MAX])
	{
		x[VAL] = x[MIN];
		while (x[VAL] <= x[MAX])
		{
			if (x[VAL] >= 0 && x[VAL] < WIDTH && y[VAL] >= 0 && y[VAL] < HEIGHT)
			{
				dst_c = img->addr[y[VAL] * WIDTH + x[VAL]];
				img->addr[y[VAL] * WIDTH + x[VAL]] = ft_blend_colors(dst_c, c);
			}
			x[VAL]++;
		}
		y[VAL]++;
	}
}

#define SELECT_ALPHA 0x2F

void	ft_mlx_select(t_img_data *img, const t_vec2i a, const t_vec2i b,
		const int color)
{
	if (a.x == b.x && a.y == b.y)
		return ;
	ft_mlx_batch_puta(img, a, b, (SELECT_ALPHA << 24) | color);
	horz_select(img, (int[2]){a.x, b.x}, a.y, color);
	horz_select(img, (int[2]){b.x, a.x}, b.y, color);
	vert_select(img, (int[2]){a.y, b.y}, b.x, color);
	vert_select(img, (int[2]){b.y, a.y}, a.x, color);
}
