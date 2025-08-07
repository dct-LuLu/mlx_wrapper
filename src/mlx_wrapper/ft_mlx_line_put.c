/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_line_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:17:29 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/07 09:35:39 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include <math.h>

#define START 0
#define END 1

/*
	Function that initializes the necessary data for the line drawing function
*/
static inline t_line	get_line_data(const t_vec2i a, const t_vec2i b)
{
	t_line	line;

	line.dx = abs(b.x - a.x);
	line.dy = -abs(b.y - a.y);
	line.sx = (b.x > a.x) - (b.x < a.x);
	line.sy = (b.y > a.y) - (b.y < a.y);
	line.err = line.dx + line.dy;
	return (line);
}

/*
	Function for line_put logic, to increment the current pixel draw pos.
*/
static inline void	incr_line(int *pos, int *err, const int d, const int s)
{
	*err += d;
	*pos += s;
}

/*
	Function that draws a line from point a to point b using a color.
*/
void	ft_mlx_line_put(t_img_data *img, t_vec2i a, t_vec2i b,
			const int color)
{
	t_line	line;

	line = get_line_data(a, b);
	while (true)
	{
		if ((a.x >= 0) && (a.x <= img->width) && (a.y >= 0)
			&& (a.y <= img->height))
			ft_mlx_pixel_put(img, a, color);
		if ((a.x == b.x) && (a.y == b.y))
			break ;
		line.e2 = line.err * 2;
		if (line.e2 >= line.dy)
		{
			if (a.x == b.x)
				break ;
			incr_line(&a.x, &line.err, line.dy, line.sx);
		}
		if (line.e2 <= line.dx)
		{
			if (a.y == b.y)
				break ;
			incr_line(&a.y, &line.err, line.dx, line.sy);
		}
	}
}

void	ft_mlx_horizontal_line(t_img_data *img, const int xpt[2], const int y,
			const int color)
{
	int				start_x;
	int				end_x;
	int				width;
	unsigned int	*pixel_row;
	unsigned int	*end_ptr;

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
	pixel_row = (unsigned int *)(img->addr + (y * img->line_len) + (start_x
				* img->byte_depth));
	end_ptr = pixel_row + width;
	while (pixel_row < end_ptr)
	{
		*pixel_row = (unsigned int)color;
		pixel_row++;
	}
}
