/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_center_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:36:38 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/09 01:50:03 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_center_window(t_mlx *mlx_data)
{
	const int	center_x = (MAX_WIDTH / 2) - (WIDTH / 2);
	const int	center_y = (MAX_HEIGHT / 2) - (HEIGHT / 2);

	XMoveWindow(mlx_data->mlx->display, mlx_data->win->window,
			center_x, center_y);
}
