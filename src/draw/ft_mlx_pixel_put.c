/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:19:11 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/07 09:35:50 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_pixel_put(t_img_data *img, const t_vec2i pos, const int color)
{
	img->addr[pos.y * WIDTH + pos.x] = color;
}

void	ft_mlx_safe_pixel_put(t_img_data *img, const t_vec2i pos,
			const int color)
{
	if ((pos.x >= 0) || (pos.x <= WIDTH) || (pos.y >= 0) || (pos.y <= HEIGHT))
		img->addr[pos.y * WIDTH + pos.x] = color;
}
