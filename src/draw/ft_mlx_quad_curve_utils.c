/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_quad_curve_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:06:51 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 20:22:33 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

float	get_curve_flatness(t_quad q, t_vec2 *m0, t_vec2 *m1, t_vec2 *mid)
{
	float	dx;
	float	dy;
	float	d;

	*m0 = vec2((q.p0.x + q.p1.x) * 0.5f, (q.p0.y + q.p1.y) * 0.5f);
	*m1 = vec2((q.p1.x + q.p2.x) * 0.5f, (q.p1.y + q.p2.y) * 0.5f);
	*mid = vec2((m0->x + m1->x) * 0.5f, (m0->y + m1->y) * 0.5f);
	dx = q.p2.x - q.p0.x;
	dy = q.p2.y - q.p0.y;
	d = fabsf((q.p1.x - q.p2.x) * dy - (q.p1.y - q.p2.y) * dx);
	return (d);
}
