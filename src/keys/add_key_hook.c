/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 03:28:32 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/21 03:28:47 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	add_status_key_hook(t_mlx *mlx_data, bool (*is_key)(int),
		bool toggle, bool *status)
{
	const t_key_event	key_event = (t_key_event)
	{
		.is_key = is_key,
		.toggle = toggle,
		.status = status
	};
	if (vector_add(mlx_data->key_input.key_events, (void *)&key_event, 1) == -1)
		return (error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	return (0);
}

int	add_status_skey_hook(t_mlx *mlx_data, int keycode,
		bool toggle, bool *status)
{
	const t_key_event	key_event = (t_key_event)
	{
		.keycode = keycode,
		.toggle = toggle,
		.status = status
	};
	if (vector_add(mlx_data->key_input.key_events, (void *)&key_event, 1) == -1)
		return (error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	return (0);
}

int	add_func_key_hook(t_mlx *mlx_data, bool (*is_key)(int),
		void (*action)(void *, t_mlx *), void *arg)
{
	const t_key_event	key_event = (t_key_event)
	{
		.is_key = is_key,
		.action = action,
		.arg = arg
	};
	if (vector_add(mlx_data->key_input.key_events, (void *)&key_event, 1) == -1)
		return (error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	return (0);
}

int	add_func_skey_hook(t_mlx *mlx_data, int keycode,
		void (*action)(void *, t_mlx *), void *arg)
{
	const t_key_event	key_event = (t_key_event)
	{
		.keycode = keycode,
		.action = action,
		.arg = arg
	};
	if (vector_add(mlx_data->key_input.key_events, (void *)&key_event, 1) == -1)
		return (error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	return (0);
}
