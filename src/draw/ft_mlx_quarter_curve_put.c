/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_quarter_curve_put.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:59:57 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 20:24:38 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

#define START	0
#define CTRL	1
#define END		2
#define IN 		3

static inline void	fill_line_quarter(t_img_data *img, t_quad q, int in_x,
			const t_rgba_int color)
{
	fill_line_until(img, (t_vec2i[2])
	{
		vec2i((int)roundf(q.p0.x), (int)roundf(q.p0.y)),
		vec2i((int)roundf(q.p2.x), (int)roundf(q.p2.y))
	},
		in_x, color);
}

void	ft_mlx_quarter_curve_aput(t_img_data *img, const t_vec2i *pts,
			const t_rgba_int color)
{
	t_quad	stack[QUAD_STACK_SIZE];
	t_quad	q;
	int		stack_top;
	t_vec2	m[3];

	stack_top = 0;
	stack[stack_top++] = (t_quad)
	{
		vec2(pts[START].x, pts[START].y),
		vec2(pts[CTRL].x, pts[CTRL].y),
		vec2(pts[END].x, pts[END].y)
	};
	while (stack_top > 0)
	{
		q = stack[--stack_top];
		if (get_curve_flatness(q, &m[0], &m[1], &m[2]) < 0.5f)
			fill_line_quarter(img, q, pts[IN].x, color);
		else if (stack_top < (QUAD_STACK_SIZE - 2))
		{
			stack[stack_top++] = (t_quad){m[2], m[1], q.p2};
			stack[stack_top++] = (t_quad){q.p0, m[0], m[2]};
		}
	}
	ft_mlx_hline_aput(img, (int [2]){pts[END].x, pts[IN].x}, pts[END].y, color);
}
