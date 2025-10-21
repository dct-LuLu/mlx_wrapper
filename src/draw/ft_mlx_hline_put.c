/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hline_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:24:53 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/21 00:22:17 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

#define START 0
#define END 1

static inline void	ft_mlx_spanh(uint32_t *p,
		int width, const t_rgb_int color)
{
	int	rem;
	int	n;

	n = width >> 3;
	while (n--)
	{
		p[0] = color.rgb;
		p[1] = color.rgb;
		p[2] = color.rgb;
		p[3] = color.rgb;
		p[4] = color.rgb;
		p[5] = color.rgb;
		p[6] = color.rgb;
		p[7] = color.rgb;
		p += 8;
	}
	rem = width & 7;
	while (rem--)
	{
		*p++ = color.rgb;
	}
}

void	ft_mlx_hline_put(t_img_data *img, const int xpt[2],
			const int y, const t_rgb_int color)
{
	int		start_x;
	int		end_x;
	int		width;
	uint8_t	*row;

	if ((y < 0) || (y >= img->height))
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
	ft_mlx_spanh((uint32_t *)row, width, color);
}

static inline void	ft_mlx_aspanh(uint32_t *p,
		int width, const t_rgba_int color)
{
	int	rem;
	int	n;

	n = width >> 3;
	while (n--)
	{
		p[0] = ft_blend_raw_colors(p[0], color).rgb;
		p[1] = ft_blend_raw_colors(p[1], color).rgb;
		p[2] = ft_blend_raw_colors(p[2], color).rgb;
		p[3] = ft_blend_raw_colors(p[3], color).rgb;
		p[4] = ft_blend_raw_colors(p[4], color).rgb;
		p[5] = ft_blend_raw_colors(p[5], color).rgb;
		p[6] = ft_blend_raw_colors(p[6], color).rgb;
		p[7] = ft_blend_raw_colors(p[7], color).rgb;
		p += 8;
	}
	rem = width & 7;
	while (rem--)
	{
		*p = ft_blend_raw_colors(*p, color).rgb;
		p++;
	}
}

void	ft_mlx_hline_aput(t_img_data *img, const int xpt[2],
			const int y, const t_rgba_int color)
{
	int		start_x;
	int		end_x;
	int		width;
	uint8_t	*row;

	if ((y < 0) || (y >= img->height))
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
	ft_mlx_aspanh((uint32_t *)row, width, color);
}
