/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:24:53 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 20:26:10 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

#define START 0
#define END 1

static inline void	ft_mlx_span(uint32_t *p,
		int width, const int color)
{
	int	rem;
	int	n;

	n = width >> 3;
	while (n--)
	{
		p[0] = color;
		p[1] = color;
		p[2] = color;
		p[3] = color;
		p[4] = color;
		p[5] = color;
		p[6] = color;
		p[7] = color;
		p += 8;
	}
	rem = width & 7;
	while (rem--)
	{
		*p++ = color;
	}
}

void	ft_mlx_hline(t_img_data *img, const int xpt[2],
			const int y, const int color)
{
	int		start_x;
	int		end_x;
	int		width;
	uint8_t	*row;

	if (!img || !img->addr || img->line_len <= 0 || img->byte_depth <= 0)
		return ;
	if (y < 0 || y >= img->height)
		return ;
	start_x = xpt[!(xpt[START] < xpt[END])];
	end_x = xpt[(xpt[START] < xpt[END])];
	if (start_x < 0)
		start_x = 0;
	if (end_x >= img->width)
		end_x = img->width - 1;
	width = end_x - start_x + 1;
	if (width <= 0)
		return ;
	row = (uint8_t *)img->addr
		+ (size_t)y * (size_t)img->line_len
		+ (size_t)start_x * (size_t)img->byte_depth;
	ft_mlx_span((uint32_t *)row, width, color);
}
