/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_line_aput.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 03:01:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/21 03:02:11 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include <math.h>

static inline void	bresenham_ha(t_img_data *img, t_vec2i a, t_vec2i b, t_rgba_int color)
{
	int	dx;
	int	dy;
	int	dir;
    int	err;

	dx = b.x - a.x;
	dy = b.y - a.y;
	dir = 1;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	err = 2 * dy - dx;
	while (a.x <= b.x)
	{
		++a.x;
		ft_mlx_safe_pixel_aput(img, a, color);
		if (err >= 0)
		{
			a.y += dir;
			err -= 2 * dx;
		}
		err += 2 * dy;
	}
}

static inline void	bresenham_va(t_img_data *img, t_vec2i a, t_vec2i b, t_rgba_int color)
{
	int	dx;
	int	dy;
	int	dir;
    int	err;

	dx = b.x - a.x;
	dy = b.y - a.y;
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	err = 2 * dx - dy;
	while (a.y <= b.y)
	{
		++a.y;
		ft_mlx_safe_pixel_aput(img, a, color);
		if (err >= 0)
		{
			a.x += dir;
			err -= 2 * dy;
		}
		err += 2 * dx;
	}
}

/*
	Function that draws a line from point a to point b using a color.
*/
void	ft_mlx_line_aput(t_img_data *img, t_vec2i point_a, t_vec2i point_b, t_rgba_int color)
{
	if (abs(point_b.y - point_a.y)
		<= abs(point_b.x - point_a.x))
	{
		if (point_b.x < point_a.x)
			bresenham_ha(img, point_b, point_a, color);
		else
			bresenham_ha(img, point_a, point_b, color);
	}
	else
	{
		if (point_b.y < point_a.y)
			bresenham_va(img, point_b, point_a, color);
		else
			bresenham_va(img, point_a, point_b, color);
	}
}
