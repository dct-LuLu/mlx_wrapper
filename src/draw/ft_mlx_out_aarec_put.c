/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_out_aarec_put.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:13:33 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/21 23:38:54 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

/*
	Function that draw a 1px Axis Aligned rectangle
*/
void	ft_mlx_out_aarec_put(t_img_data *img, const t_vec2i pos_a,
		const t_vec2i pos_b, const t_rgb_int color)
{
	const int	xpt[2] = {pos_a.x, pos_b.x};
	const int	ypt[2] = {pos_a.y, pos_b.y};

	ft_mlx_vline_put(img, ypt, pos_a.x, color);
	ft_mlx_vline_put(img, ypt, pos_b.x, color);
	ft_mlx_hline_put(img, xpt, pos_a.y, color);
	ft_mlx_hline_put(img, xpt, pos_b.y, color);
}

/*
	Function that draw a 1px Axis Aligned rectangle
	Handles opacity without corner overlapping
*/
void	ft_mlx_out_aarec_aput(t_img_data *img, const t_vec2i pos_a,
		const t_vec2i pos_b, const t_rgba_int color)
{
	const int	xpt[2] = {min(pos_a.x, pos_b.x) + 1, max(pos_a.x, pos_b.x) - 1};
	const int	ypt[2] = {pos_a.y, pos_b.y};

	ft_mlx_vline_aput(img, ypt, pos_a.x, color);
	ft_mlx_vline_aput(img, ypt, pos_b.x, color);
	ft_mlx_hline_aput(img, xpt, pos_a.y, color);
	ft_mlx_hline_aput(img, xpt, pos_b.y, color);
}
