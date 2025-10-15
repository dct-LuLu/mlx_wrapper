/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_aarec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:13:33 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 02:21:25 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_aarec(t_img_data *img, const t_vec2i pos_a,
		const t_vec2i pos_b, const int color)
{
	const t_vec2i	pos_c = vec2i(pos_b.x, pos_a.y);
	const t_vec2i	pos_d = vec2i(pos_a.x, pos_b.y);

	//horizontal
	ft_mlx_line_put(img, pos_a, pos_c, color);
	ft_mlx_line_put(img, pos_b, pos_d, color);

	//vertical
	ft_mlx_line_put(img, pos_c, pos_b, color);
	ft_mlx_line_put(img, pos_a, pos_d, color);
}
