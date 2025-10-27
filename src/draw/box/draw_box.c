/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:53:18 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/27 11:15:07 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

/*
static inline void	debug_corner(t_img_data *img, const t_vec2i corner[3], int color)
{
	ft_mlx_safe_circle_aput(img, corner[0], 3, rgba_int(255, 50, color, 128));
	ft_mlx_safe_circle_aput(img, corner[1], 7, rgba_int(255, 80, color, 128));
	ft_mlx_safe_circle_aput(img, corner[2], 3, rgba_int(255, 50, color, 128));
}

static inline void	debug_box(t_img_data *img, t_box box)
{
	ft_mlx_safe_circle_aput(img, box._rt, 5, rgba_int(255, 125, 255, 128));
	ft_mlx_safe_circle_aput(img, box._lt, 5, rgba_int(255, 125, 255, 128));
	ft_mlx_safe_circle_aput(img, box._rb, 5, rgba_int(255, 125, 255, 128));
	ft_mlx_safe_circle_aput(img, box._lb, 5, rgba_int(255, 125, 255, 128));
	debug_corner(img, box._lt_corner, 255);
	debug_corner(img, box._rt_corner, 128);
	debug_corner(img, box._rb_corner, 100);
	debug_corner(img, box._lb_corner, 25);
}
*/

static inline void	fill_corner(t_img_data *img, t_box box, t_corner corner)
{
	if (DEBUG)
	{
		ft_mlx_quarter_curve_aput(img, corner._mem, rgba_int(125, 255, 255, 128));
		ft_mlx_aarec_aput(img, corner.xrec[0], corner.xrec[1], rgba_int(0, 255, 255, 128));
		ft_mlx_aarec_aput(img, corner.mrec[0], corner.mrec[1], rgba_int(255, 255, 255, 128));
	}
	else
	{
		ft_mlx_quarter_curve_aput(img, corner._mem, box.color);
		ft_mlx_aarec_aput(img, corner.xrec[0], corner.xrec[1], box.color);
		ft_mlx_aarec_aput(img, corner.mrec[0], corner.mrec[1], box.color);
	}
}

static inline void	fill_box(t_img_data *img, t_box box)
{
	if ((box.radius.style == NO_RADIUS) || (box.radius._mem == 0))
		ft_mlx_aarec_aput(img, box._lt.corner, box._rb.corner, box.color);
	else if (box.radius._mem != 0)
	{
		/*
		if (box.radius != 100)
		{
			ft_mlx_aarec_aput(img, vec2i(box._lt_corner[0].x + 1, box._lt_corner[0].y), vec2i(box._rb_corner[0].x - 1, box._rb_corner[0].y), box.color);
			ft_mlx_aarec_aput(img, vec2i(box._lt_corner[2].x, box._lt_corner[2].y + 1), vec2i(box._lb_in.x, box._lb_in.y - 1), box.color);
			ft_mlx_aarec_aput(img, vec2i(box._rt_in.x, box._rt_in.y + 1), vec2i(box._rb_corner[2].x, box._rb_corner[2].y - 1), box.color);
		}
		ft_mlx_quarter_curve_aput(img, box.radius.lt._val, box.color);
		ft_mlx_quarter_curve_aput(img, box.radius.rt._val, box.color);
		ft_mlx_quarter_curve_aput(img, box.radius.lb._val, box.color);
		ft_mlx_quarter_curve_aput(img, box.radius.rb._val, box.color);
		*/
		fill_corner(img, box, box._lt);
		fill_corner(img, box, box._rt);
		fill_corner(img, box, box._lb);
		fill_corner(img, box, box._rb);
	}
}

void	draw_box(t_img_data *img, t_box box)
{
	if ((box.size.x == 0) && (box.size.y == 0))
		return ;
	draw_border(img, box);
	fill_box(img, box);
	//if (DEBUG)
	//	debug_box(img, box);
}
