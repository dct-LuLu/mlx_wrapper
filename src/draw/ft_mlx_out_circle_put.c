/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_out_circle_put.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:06:40 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/27 04:53:19 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_out_circle_put(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgb_int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = radius;
	d = 3 - (2 * radius);
	while (y >= x)
	{
		ft_mlx_safe_pixel_put(img, vec2i(center.x + x, center.y + y), color);
		ft_mlx_safe_pixel_put(img, vec2i(center.x - x, center.y + y), color);
		ft_mlx_safe_pixel_put(img, vec2i(center.x + x, center.y - y), color);
		ft_mlx_safe_pixel_put(img, vec2i(center.x - x, center.y - y), color);
		ft_mlx_safe_pixel_put(img, vec2i(center.x + y, center.y + x), color);
		ft_mlx_safe_pixel_put(img, vec2i(center.x - y, center.y + x), color);
		ft_mlx_safe_pixel_put(img, vec2i(center.x + y, center.y - x), color);
		ft_mlx_safe_pixel_put(img, vec2i(center.x - y, center.y - x), color);
		x++;
		if (d > 0)
			y--;
		d += (4 * (x - (y * (d > 0)))) + 6 + (4 * (d > 0));
	}
}

void	ft_mlx_out_circle_aput(t_img_data *img, const t_vec2i center,
			const int radius, const t_rgba_int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = radius;
	d = 3 - (2 * radius);
	while (y >= x)
	{
		ft_mlx_safe_pixel_aput(img, vec2i(center.x + x, center.y + y), color);
		ft_mlx_safe_pixel_aput(img, vec2i(center.x - x, center.y + y), color);
		ft_mlx_safe_pixel_aput(img, vec2i(center.x + x, center.y - y), color);
		ft_mlx_safe_pixel_aput(img, vec2i(center.x - x, center.y - y), color);
		ft_mlx_safe_pixel_aput(img, vec2i(center.x + y, center.y + x), color);
		ft_mlx_safe_pixel_aput(img, vec2i(center.x - y, center.y + x), color);
		ft_mlx_safe_pixel_aput(img, vec2i(center.x + y, center.y - x), color);
		ft_mlx_safe_pixel_aput(img, vec2i(center.x - y, center.y - x), color);
		x++;
		if (d > 0)
			y--;
		d += (4 * (x - (y * (d > 0)))) + 6 + (4 * (d > 0));
	}
}
