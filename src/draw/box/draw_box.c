/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:53:18 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/28 00:29:04 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

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
	fill_box(img, box);
	draw_border(img, box);
}
