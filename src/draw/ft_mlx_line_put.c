/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_line_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:17:29 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/22 08:47:48 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include <math.h>

/*

static inline void	bresenham_h(t_img_data *img, t_vec2i a, t_vec2i b, t_rgb_int color)
{
	int	dx;
	int	dy;
	int	dir;
    int	err;

	dx = b.x - a.x;
	dy = b.y - a.y;
	dir = 1;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	err = 2 * dy - dx;
	while (a.x <= b.x)
	{
		++a.x;
		ft_mlx_safe_pixel_put(img, a, color);
		if (err >= 0)
		{
			a.y += dir;
			err -= 2 * dx;
		}
		err += 2 * dy;
	}
}

static inline void	bresenham_v(t_img_data *img, t_vec2i a, t_vec2i b, t_rgb_int color)
{
	int	dx;
	int	dy;
	int	dir;
    int	err;

	dx = b.x - a.x;
	dy = b.y - a.y;
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	err = 2 * dx - dy;
	while (a.y <= b.y)
	{
		++a.y;
		ft_mlx_safe_pixel_put(img, a, color);
		if (err >= 0)
		{
			a.x += dir;
			err -= 2 * dy;
		}
		err += 2 * dx;
	}
}
*/

/*
	Function that draws a line from point a to point b using a color.
*/
/*
void	ft_mlx_line_put(t_img_data *img, t_vec2i point_a, t_vec2i point_b, t_rgb_int color)
{
	if (abs(point_b.y - point_a.y)
		<= abs(point_b.x - point_a.x))
	{
		if (point_b.x < point_a.x)
			bresenham_h(img, point_b, point_a, color);
		else
			bresenham_h(img, point_a, point_b, color);
	}
	else
	{
		if (point_b.y < point_a.y)
			bresenham_v(img, point_b, point_a, color);
		else
			bresenham_v(img, point_a, point_b, color);
	}
}*/


/*
typedef struct s_line

{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_line;
*/



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
			const t_rgb_int color)
{
	t_line	line;

	line = get_line_data(a, b);
	while (true)
	{
		if ((a.x >= 0) && (a.x < img->width)
				&& (a.y >= 0) && (a.y < img->height))
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

void	ft_mlx_line_aput(t_img_data *img, t_vec2i a, t_vec2i b,
			const t_rgba_int color)
{
	t_line	line;

	line = get_line_data(a, b);
	while (true)
	{
		if ((a.x >= 0) && (a.x < img->width)
				&& (a.y >= 0) && (a.y < img->height))
			ft_mlx_pixel_aput(img, a, color);
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

#define A 0
#define B 1

void	ft_mlx_line_aputf(t_img_data *img, t_vec2i p[2], int x,
			const t_rgba_int color)
{
	t_line	line;
	static int	last = 0;

	line = get_line_data(p[A], p[B]);
	while (true)
	{
		if ((p[A].x == p[B].x) && (p[A].y == p[B].y))
			break ;
		line.e2 = line.err * 2;
		if (line.e2 <= line.dx)
		{
			if (p[A].y == p[B].y)
				break ;
			if (last != p[A].y)
				ft_mlx_hline_aput(img, (int[2]){x, p[A].x}, p[A].y, color);
			last = p[A].y;
			incr_line(&p[A].y, &line.err, line.dx, line.sy);
		}
		if (line.e2 >= line.dy)
		{
			if (p[A].x == p[B].x)
				break ;
			incr_line(&p[A].x, &line.err, line.dy, line.sx);
		}
	}
}
