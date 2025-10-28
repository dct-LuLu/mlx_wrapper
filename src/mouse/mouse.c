/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:52:27 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 01:31:33 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	setup_mouse_movement(t_mlx *mlx_data);
int	setup_mouse_button(t_mlx *mlx_data);

int	setup_mouse_input(t_mlx *mlx_data)
{
	if (setup_mouse_button(mlx_data) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_BUTTONHF), FL, LN, FC));
	if (setup_mouse_movement(mlx_data) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_MOTIONHF), FL, LN, FC));
	return (0);
}
