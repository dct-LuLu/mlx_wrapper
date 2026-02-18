/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 03:28:32 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:16:52 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static inline ssize_t	add_key_hook(t_mlx *mlx_data, t_key_event *key_event)
{
	static ssize_t	event_idx = 0;

	key_event->event_idx = event_idx;
	if (vector_add(mlx_data->key_input.key_events, (void *)key_event, 1) == -1)
		return (neg_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	event_idx++;
	return (key_event->event_idx);
}

ssize_t	add_status_key_hook(t_mlx *mlx_data, bool (*is_key)(int),
		bool toggle, bool *status)
{
	const t_key_event	key_event = (t_key_event)
	{
		.is_key = is_key,
		.toggle = toggle,
		.status = status
	};
	
	return (add_key_hook(mlx_data, (t_key_event *)&key_event));
}

ssize_t	add_status_skey_hook(t_mlx *mlx_data, int keycode,
		bool toggle, bool *status)
{
	const t_key_event	key_event = (t_key_event)
	{
		.keycode = keycode,
		.toggle = toggle,
		.status = status
	};

	return (add_key_hook(mlx_data, (t_key_event *)&key_event));
}

ssize_t	add_func_key_hook(t_mlx *mlx_data, bool (*is_key)(int),
		void (*action)(void *, t_mlx *), void *arg)
{
	const t_key_event	key_event = (t_key_event)
	{
		.is_key = is_key,
		.action = action,
		.arg = arg
	};

	return (add_key_hook(mlx_data, (t_key_event *)&key_event));
}

ssize_t	add_func_skey_hook(t_mlx *mlx_data, int keycode,
		void (*action)(void *, t_mlx *), void *arg)
{
	const t_key_event	key_event = (t_key_event)
	{
		.keycode = keycode,
		.action = action,
		.arg = arg
	};

	return (add_key_hook(mlx_data, (t_key_event *)&key_event));
}
