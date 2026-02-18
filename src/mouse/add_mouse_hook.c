/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:34:34 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:09:26 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

ssize_t	add_func_button_hook(t_mlx *mlx_data, t_mbuttons keycode,
		void (*action)(t_vec2i, t_maction, void *, t_mlx *), void *arg)
{
	static ssize_t			event_idx = 0;
	const t_button_event	button_event = (t_button_event)
	{
		.keycode = keycode,
		.action = action,
		.arg = arg,
		.event_idx = event_idx
	};

	if (keycode == MNULL)
		return (neg_error(pack_err(MLXW_ID, MLXW_E_WMEVENT), FL, LN, FC));
	if (vector_add(mlx_data->mouse_input.button_events,
			(void *)&button_event, 1) == -1)
		return (neg_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	event_idx++;
	return (button_event.event_idx);
}

ssize_t	add_func_move_hook(t_mlx *mlx_data,
		void (*action)(void *, t_mlx *), void *arg)
{
	static ssize_t		event_idx = 0;
	const t_move_event	move_event = (t_move_event)
	{
		.action = action,
		.arg = arg,
		.event_idx = event_idx
	};

	if (vector_add(mlx_data->mouse_input.move_events,
			(void *)&move_event, 1) == -1)
		return (neg_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	event_idx++;
	return (move_event.event_idx);
}
