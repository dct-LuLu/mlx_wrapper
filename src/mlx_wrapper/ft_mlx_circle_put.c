/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:10:43 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/07 08:25:53 by jaubry--         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include "vectors.h"

void	ft_mlx_circle_put(t_img_data *img, const t_vec2i center,
			const int radius, const int color)
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
