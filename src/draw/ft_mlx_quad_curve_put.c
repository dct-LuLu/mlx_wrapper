/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_quad_curve_put.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:19:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/22 08:49:26 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include "libft.h"

#define MAX_STEP	0.05f
#define MIN_STEP	0.001f

#define START	0
#define CTRL	1
#define END		2

void	ft_mlx_quad_curve_put(t_img_data *img, const t_vec2i *pts,
			const t_rgb_int color)
{
	//const float	curve_length = quad_curve_length(
	//		pts[START], pts[CTRL], pts[END]);
	float		t;
	float		step;
	t_vec2i		current;
	t_vec2i		previous;

	int curvature = abs(pts[START].x - 2 * pts[CTRL].x + pts[END].x)
    				+ abs(pts[START].y - 2 * pts[CTRL].y + pts[END].y);
	step = 1.0f / ((float)curvature + 1.0f);
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

void	ft_mlx_quad_curve_aput(t_img_data *img, const t_vec2i *pts,
			const t_rgba_int color)
{
    typedef struct s_quad { t_vec2 p0, p1, p2; } t_quad;
    t_quad stack[64];
    int stack_top = 0;

	printf("border: %d %d %d\n", pts[START].x, pts[CTRL].x, pts[END].x);
    // push initial curve
    stack[stack_top++] = (t_quad)
    {
    	vec2(pts[START].x, pts[START].y),
    	vec2(pts[CTRL].x,  pts[CTRL].y),
        vec2(pts[END].x,   pts[END].y)
    };

    while (stack_top > 0)
    {
        t_quad q = stack[--stack_top];

        // Compute midpoints
        t_vec2 m0 = vec2((q.p0.x + q.p1.x) * 0.5f, (q.p0.y + q.p1.y) * 0.5f);
        t_vec2 m1 = vec2((q.p1.x + q.p2.x) * 0.5f, (q.p1.y + q.p2.y) * 0.5f);
        t_vec2 mid = vec2((m0.x + m1.x) * 0.5f, (m0.y + m1.y) * 0.5f);

        // Flatness check: distance from control to line between endpoints
        float dx = q.p2.x - q.p0.x;
        float dy = q.p2.y - q.p0.y;
        float d = fabsf((q.p1.x - q.p2.x) * dy - (q.p1.y - q.p2.y) * dx);

        if (d < 0.5f) // curve flat enough (within one pixel deviation)
        {
            ft_mlx_line_aput(img,
            	vec2i((int)roundf(q.p0.x), (int)roundf(q.p0.y)),
                vec2i((int)roundf(q.p2.x), (int)roundf(q.p2.y)),
                color);
        }
        else
        {
            // Subdivide into two halves for further flattening
            if (stack_top < 62) {
                stack[stack_top++] = (t_quad){ mid, m1, q.p2 };
                stack[stack_top++] = (t_quad){ q.p0, m0, mid };
            }
        }
    }
}


void	ft_mlx_quarter_curve_aput(t_img_data *img, const t_vec2i *pts, const t_vec2i in,
			const t_rgba_int color)
{
    typedef struct s_quad { t_vec2 p0, p1, p2; } t_quad;
    t_quad stack[64];
    int stack_top = 0;

	printf("fill: %d %d %d\n", pts[START].x, pts[CTRL].x, pts[END].x);
    // push initial curve
    stack[stack_top++] = (t_quad)
    {
    	vec2(pts[START].x, pts[START].y),
    	vec2(pts[CTRL].x,  pts[CTRL].y),
        vec2(pts[END].x,   pts[END].y)
    };

    while (stack_top > 0)
    {
        t_quad q = stack[--stack_top];

        // Compute midpoints
        t_vec2 m0 = vec2((q.p0.x + q.p1.x) * 0.5f, (q.p0.y + q.p1.y) * 0.5f);
        t_vec2 m1 = vec2((q.p1.x + q.p2.x) * 0.5f, (q.p1.y + q.p2.y) * 0.5f);
        t_vec2 mid = vec2((m0.x + m1.x) * 0.5f, (m0.y + m1.y) * 0.5f);

        // Flatness check: distance from control to line between endpoints
        float dx = q.p2.x - q.p0.x;
        float dy = q.p2.y - q.p0.y;
        float d = fabsf((q.p1.x - q.p2.x) * dy - (q.p1.y - q.p2.y) * dx);

        if (d < 0.5f) // curve flat enough (within one pixel deviation)
        {
            ft_mlx_line_aputf(img,
            	(t_vec2i[2]){
            	vec2i((int)roundf(q.p0.x), (int)roundf(q.p0.y)),
                vec2i((int)roundf(q.p2.x), (int)roundf(q.p2.y))},
                in.x, color);
        }
        else
        {
            // Subdivide into two halves for further flattening
            if (stack_top < 62) {
                stack[stack_top++] = (t_quad){ mid, m1, q.p2 };
                stack[stack_top++] = (t_quad){ q.p0, m0, mid };
            }
        }
    }
    ft_mlx_hline_aput(img, (int[2]){pts[END].x, in.x}, pts[END].y, color);
}
