/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_vline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:26:18 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 20:28:21 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

#define START 0
#define END 1

static inline void	ft_mlx_span(t_img_data *img, uint8_t *p,
		int height, const int color)
{
	int	n;
	int	rem;

	n = height >> 2;
	while (n--)
	{
		*(uint32_t *)(p) = color;
		p += img->line_len;
		*(uint32_t *)(p) = color;
		p += img->line_len;
		*(uint32_t *)(p) = color;
		p += img->line_len;
		*(uint32_t *)(p) = color;
		p += img->line_len;
	}
	rem = height & 3;
	while (rem--)
	{
		*(uint32_t *)(p) = color;
		p += img->line_len;
	}
}

void	ft_mlx_vline(t_img_data *img, const int ypt[2],
			const int x, const int color)
{
	int		start_y;
	int		end_y;
	int		height;
	uint8_t	*p;

	if ((x < 0) || (x >= img->width))
		return ;
	start_y = ypt[!(ypt[START] < ypt[END])];
	end_y = ypt[(ypt[START] < ypt[END])];
	if (start_y < 0)
		start_y = 0;
	if (end_y >= img->height)
		end_y = img->height - 1;
	height = end_y - start_y + 1;
	if (height <= 0)
		return ;
	p = (uint8_t *)img->addr
		+ (size_t)start_y * (size_t)img->line_len
		+ (size_t)x * (size_t)img->byte_depth;
	ft_mlx_span(img, p, height, color);
}
