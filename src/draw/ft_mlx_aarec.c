/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_aarec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:13:33 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 02:58:54 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_aarec(t_img_data *img, const t_vec2i pos_a,
		const t_vec2i pos_b, const int color)
{
	const int	xpt[2] = {pos_a.x, pos_b.x};
	const int	ypt[2] = {pos_a.y, pos_b.y};

	ft_mlx_vline(img, ypt, pos_a.x, color);
	ft_mlx_vline(img, ypt, pos_b.x, color);
	ft_mlx_hline(img, xpt, pos_a.y, color);
	ft_mlx_hline(img, xpt, pos_b.y, color);
}
