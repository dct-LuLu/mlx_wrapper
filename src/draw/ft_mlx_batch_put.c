/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_batch_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:06:14 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/20 22:23:11 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_batch_put(t_img_data *img, const t_vec2i pos,
			const t_vec2i size, const t_rgb_int color)
{
	int				x;
	int				y;
	int				offset;
	unsigned int	*pixels;
	size_t			i;

	offset = ((pos.y * img->line_len) + (pos.x * img->channels));
	pixels = (unsigned int *)(img->addr + offset);
	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			i = x + y * img->width;
			pixels[i] = color.rgb;
			y++;
		}
		x++;
	}
}

void	ft_mlx_batch_aput(t_img_data *img, const t_vec2i pos,
			const t_vec2i size, const t_rgba_int color)
{
	int				x;
	int				y;
	int				offset;
	unsigned int	*pixels;
	size_t			i;

	offset = ((pos.y * img->line_len) + (pos.x * img->channels));
	pixels = (unsigned int *)(img->addr + offset);
	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			i = x + y * img->width;
			pixels[i] = ft_blend_raw_colors(pixels[i], color).rgb;
			y++;
		}
		x++;
	}
}
