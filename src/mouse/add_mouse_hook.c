/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:34:34 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 20:36:16 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	add_func_button_hook(t_mlx *mlx_data, t_mbuttons keycode,
		void (*action)(t_vec2i, t_maction, void *, t_mlx *), void *arg)
{
	const t_button_event	button_event = (t_button_event)
	{
		.keycode = keycode,
		.action = action,
		.arg = arg
	};

	if (keycode == MNULL)
		return (error(pack_err(MLXW_ID, MLXW_E_WMEVENT), FL, LN, FC));
	if (vector_add(mlx_data->mouse_input.button_events,
			(void *)&button_event, 1) == -1)
		return (error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	return (0);
}

int	add_func_move_hook(t_mlx *mlx_data,
		void (*action)(void *, t_mlx *), void *arg)
{
	const t_move_event	move_event = (t_move_event)
	{
		.action = action,
		.arg = arg
	};

	if (vector_add(mlx_data->mouse_input.move_events,
			(void *)&move_event, 1) == -1)
		return (error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	return (0);
}
