/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_vline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:26:18 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 03:04:04 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

#define START 0
#define END 1

void ft_mlx_vline(t_img_data *img, const int ypt[2],
		const int x, const int color)
{
    int start_y, end_y, height;
    uint8_t *p;

    if (!img || !img->addr || img->line_len <= 0 || img->byte_depth <= 0)
        return;
    if (x < 0 || x >= img->width)
        return;

    start_y = ypt[!(ypt[START] < ypt[END])];
    end_y = ypt[(ypt[START] < ypt[END])];
    if (start_y < 0)
    	start_y = 0;
    if (end_y >= img->height)
    	end_y = img->height - 1;

    height = end_y - start_y + 1;
    if (height <= 0)
        return;

    p = (uint8_t *)img->addr
      + (size_t)start_y * (size_t)img->line_len
      + (size_t)x * (size_t)img->byte_depth;

    uint32_t c = (uint32_t)color;
    int n = height >> 2;     // blocks of 4 pixels
    while (n--)
    {
        *(uint32_t *)(p) = c; p += img->line_len;
        *(uint32_t *)(p) = c; p += img->line_len;
        *(uint32_t *)(p) = c; p += img->line_len;
        *(uint32_t *)(p) = c; p += img->line_len;
    }
    int rem = height & 3;
    while (rem--) 
    {
    	*(uint32_t *)(p) = c; p += img->line_len;
    }
}
