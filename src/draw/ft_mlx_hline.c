/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:24:53 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 03:02:23 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

#define START 0
#define END 1

void ft_mlx_hline(t_img_data *img, const int xpt[2], const int y, const int color)
{
    int start_x, end_x, width;
    uint8_t *row;

    if (!img || !img->addr || img->line_len <= 0 || img->byte_depth <= 0)
        return;
    if (y < 0 || y >= img->height)
        return;

    start_x = xpt[!(xpt[START] < xpt[END])];
    end_x   = xpt[(xpt[START] < xpt[END])];
    if (start_x < 0) start_x = 0;
    if (end_x >= img->width) end_x = img->width - 1;

    width = end_x - start_x + 1;
    if (width <= 0)
        return;

    row = (uint8_t *)img->addr
        + (size_t)y * (size_t)img->line_len
        + (size_t)start_x * (size_t)img->byte_depth;

    uint32_t c = (uint32_t)color;
    uint32_t *p32 = (uint32_t *)row;

    int n = width >> 3;      // blocks of 8 pixels
    while (n--)
    {
        p32[0] = c; p32[1] = c; p32[2] = c; p32[3] = c;
        p32[4] = c; p32[5] = c; p32[6] = c; p32[7] = c;
        p32 += 8;
    }
    int rem = width & 7;
    while (rem--) { *p32++ = c; }
}
