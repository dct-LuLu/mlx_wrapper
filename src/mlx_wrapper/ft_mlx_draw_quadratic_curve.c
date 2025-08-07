/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_quadratic_curve.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:19:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/07 09:09:54 by jaubry--         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include "libft.h"

#define MAX_STEP	0.1f
#define MIN_STEP	0.01f

#define START	0
#define CTRL	1
#define END		2

void	ft_mlx_draw_quadratic_curve(t_img_data *img, const t_vec2i *pts,
			const int color)
{
	const float	curve_length = quad_curve_length(pts[START], pts[CTRL], pts[END]);
	float	t;
	float	step;
	t_vec2i	current;
	t_vec2i	previous;

	step = 2.0f / (curve_length + 1.0f);
	if (step > MAX_STEP)
		step = MAX_STEP;
	if (step < MIN_STEP)
		step = MIN_STEP;
	previous = pts[START];
	t = step;
	while (t <= 1.0f)
	{
		current = quad_bezier_pt(pts[START], pts[CTRL], pts[END], t);
		ft_mlx_line_put(img, previous, current, color);
		previous = current;
		t += step;
	}
	ft_mlx_line_put(img, previous, pts[END], color);
}
