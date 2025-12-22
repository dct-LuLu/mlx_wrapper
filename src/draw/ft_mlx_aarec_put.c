/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_aarec_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:54:03 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/22 01:25:41 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

#define MIN 0
#define VAL 1
#define MAX 2

void	ft_mlx_aarec_put(t_img_data *img, const t_vec2i a,
			const t_vec2i b, t_rgb_int c)
{
	int	y[3];
	int	x[3];

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
			if ((x[VAL] >= 0) && (x[VAL] < img->width)
				&& (y[VAL] >= 0) && (y[VAL] < img->height))
				img->addr[(y[VAL] * img->width) + x[VAL]] = c.rgb;
			x[VAL]++;
		}
		y[VAL]++;
	}
}

/*
	Function that batch put a rectangle from coordinates a to b, handles
	transparency
*/
void	ft_mlx_aarec_aput(t_img_data *img, const t_vec2i a,
			const t_vec2i b, t_rgba_int c)
{
	int	y[3];
	int	x[3];

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
			if ((x[VAL] >= 0) && (x[VAL] < img->width)
				&& (y[VAL] >= 0) && (y[VAL] < img->height))
				img->addr[(y[VAL] * img->width) + x[VAL]] = ft_blend_raw_colors(
						img->addr[(y[VAL] * img->width) + x[VAL]], c).rgba;
			x[VAL]++;
		}
		y[VAL]++;
	}
}
