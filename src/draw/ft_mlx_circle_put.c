/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_circle_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:10:43 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/29 03:13:24 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_circle_put(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgb_int color)
{
	int	x;
	int	y;
	int	distance;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			distance = (x * x) + (y * y);
			if (distance <= (radius * radius))
				ft_mlx_pixel_put(img, vec2i(center.x + x, center.y + y),
					color);
			x++;
		}
		y++;
	}
}

void	ft_mlx_circle_aput(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgba_int color)
{
	int	x;
	int	y;
	int	distance;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			distance = (x * x) + (y * y);
			if (distance <= (radius * radius))
				ft_mlx_pixel_aput(img, vec2i(center.x + x, center.y + y),
					color);
			x++;
		}
		y++;
	}
}

void	ft_mlx_safe_circle_put(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgb_int color)
{
	int	x;
	int	y;
	int	distance;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			distance = (x * x) + (y * y);
			if (distance <= (radius * radius))
				ft_mlx_safe_pixel_put(img, vec2i(center.x + x, center.y + y),
					color);
			x++;
		}
		y++;
	}
}

void	ft_mlx_safe_circle_aput(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgba_int color)
{
	int	x;
	int	y;
	int	distance;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			distance = (x * x) + (y * y);
			if (distance <= (radius * radius))
				ft_mlx_safe_pixel_aput(img, vec2i(center.x + x, center.y + y),
					color);
			x++;
		}
		y++;
	}
}
