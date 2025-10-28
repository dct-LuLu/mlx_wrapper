/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_border.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:12:48 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/27 10:51:09 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	draw_border(t_img_data *img, t_box box)
{
	if ((box.border.style != SOLID) || (box.border.size == 0))
		return ;
	if (box.radius._mem == 0)
		ft_mlx_out_aarec_aput(img, box._lt.corner, box._rb.corner, box.border.color);
	else
	{
		if (box.radius.full != 100)
		{
			ft_mlx_hline_aput(img, vec2i(box._lt.horz.x, box._rt.horz.x).data, box._lt.corner.y, box.border.color);
			ft_mlx_hline_aput(img, vec2i(box._lb.horz.x, box._rb.horz.x).data, box._lb.corner.y, box.border.color);
			ft_mlx_vline_aput(img, vec2i(box._lt.vert.y, box._lb.vert.y).data, box._lt.corner.x, box.border.color);
			ft_mlx_vline_aput(img, vec2i(box._rt.vert.y, box._rb.vert.y).data, box._rt.corner.x, box.border.color);
		}
		ft_mlx_quad_curve_aput(img, box._lt._mem, box.border.color);
		ft_mlx_quad_curve_aput(img, box._rt._mem, box.border.color);
		ft_mlx_quad_curve_aput(img, box._lb._mem, box.border.color);
		ft_mlx_quad_curve_aput(img, box._rb._mem, box.border.color);
	}
}
