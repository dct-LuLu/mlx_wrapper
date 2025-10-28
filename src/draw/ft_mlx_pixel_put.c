/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:19:11 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/22 00:39:09 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_pixel_put(t_img_data *img, const t_vec2i pos,
			const t_rgb_int color)
{
	img->addr[pos.y * WIDTH + pos.x] = color.rgb;
}

void	ft_mlx_safe_pixel_put(t_img_data *img, const t_vec2i pos,
			const t_rgb_int color)
{
	if ((pos.x >= 0) && (pos.x < WIDTH) && (pos.y >= 0) && (pos.y < HEIGHT))
		img->addr[pos.y * WIDTH + pos.x] = color.rgb;
}

void	ft_mlx_pixel_aput(t_img_data *img, const t_vec2i pos,
			const t_rgba_int color)
{
	static t_vec2i	prev = (t_vec2i){{0, 0}};
	const size_t	mem_pos = pos.y * WIDTH + pos.x;

	if ((pos.x == prev.x) && (pos.y == prev.y))
		return ;
	img->addr[mem_pos] = ft_blend_raw_colors(img->addr[mem_pos], color).rgb;
	prev = pos;
}

void	ft_mlx_safe_pixel_aput(t_img_data *img, const t_vec2i pos,
			const t_rgba_int color)
{
	static t_vec2i	prev = (t_vec2i){{0, 0}};
	const size_t	mem_pos = pos.y * WIDTH + pos.x;

	if ((pos.x == prev.x) && (pos.y == prev.y))
		return ;
	if ((pos.x >= 0) && (pos.x < WIDTH) && (pos.y >= 0) && (pos.y < HEIGHT))
		img->addr[mem_pos] = ft_blend_raw_colors(img->addr[mem_pos], color).rgb;
	prev = pos;
}
