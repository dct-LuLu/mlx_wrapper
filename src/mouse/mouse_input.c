/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:26:12 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/14 21:28:41 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static int mouse_event(int x, int y, int click, t_mlx *mlx_data)
{
    
}

int	setup_mouse_input(t_mlx *mlx_data)
{
    mlx_hook(mlx_data->win, MotionNotify,
                PointerMotionMask, mouse_move, mlx_data);
}
