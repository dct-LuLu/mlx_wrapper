/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:08:29 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/28 07:16:57 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static void	key_action(t_mlx *mlx_data)
{
	t_key_event	*key_event;
	size_t		i;

	i = 0;
	while (i < mlx_data->key_input.key_events->num_elements)
	{
		key_event = get_vector_value(mlx_data->key_input.key_events, i);
		if (*(key_event->status) && key_event->action)
			key_event->action(key_event->arg, mlx_data);
		i++;
	}
}

static int	key_press(int keycode, t_mlx *mlx_data)
{
	t_key_event	*key_event;
	size_t		i;

	if (is_escape_key(keycode))
		mlx_loop_end(mlx_data->mlx);
	if (RESIZEABLE && (keycode == XK_F11))
	{
		mlx_data->fullscreen = !mlx_data->fullscreen;
		mlx_ext_fullscreen(mlx_data->mlx, mlx_data->win, mlx_data->fullscreen);
	}
	mlx_data->key_input.keycode = keycode;
	i = 0;
	while (i < mlx_data->key_input.key_events->num_elements)
	{
		key_event = get_vector_value(mlx_data->key_input.key_events, i);
		if (key_event->is_key(keycode))
		{
			if (key_event->toggle)
				*(key_event->status) = !*(key_event->status);
			else
				*(key_event->status) = true;
		}
		i++;
	}
	key_action(mlx_data);
	return (0);
}

static int	key_release(int keycode, t_mlx *mlx_data)
{
	t_key_event	*key_event;
	size_t		i;

	mlx_data->key_input.keycode = XK_VoidSymbol;
	i = 0;
	while (i < mlx_data->key_input.key_events->num_elements)
	{
		key_event = get_vector_value(mlx_data->key_input.key_events, i);
		if (!(key_event->toggle) && key_event->is_key(keycode))
			*(key_event->status) = false;
		i++;
	}
	key_action(mlx_data);
	return (0);
}

static void	setup_special_key_events(t_mlx *mlx_data)
{
	t_key_event	special_key_events[3];

	special_key_events[0] = (t_key_event)
	{
		.is_key = is_ctrl_key,
		.action = NULL,
		.arg = NULL,
		.toggle = false,
		.status = &(mlx_data->key_input.ctrl)
	};
	special_key_events[1] = (t_key_event)
	{
		.is_key = is_shift_key,
		.action = NULL,
		.arg = NULL,
		.toggle = false,
		.status = &(mlx_data->key_input.shift)
	};
	special_key_events[2] = (t_key_event)
	{
		.is_key = is_caps_key,
		.action = NULL,
		.arg = NULL,
		.toggle = true,
		.status = &(mlx_data->key_input.caps)
	};
	vector_add(mlx_data->key_input.key_events, special_key_events, 3);
}

int	setup_key_input(t_mlx *mlx_data)
{
	mlx_data->key_input.key_events = ft_calloc(1, sizeof(t_vector));
	if (!mlx_data->key_input.key_events)
		return (-1);
	vector_init(mlx_data->key_input.key_events, sizeof(t_key_event));
	mlx_hook(mlx_data->win, KeyPress, KeyPressMask, key_press, mlx_data);
	mlx_hook(mlx_data->win, KeyRelease, KeyReleaseMask, key_release, mlx_data);
	mlx_hook(mlx_data->win, DestroyNotify, StructureNotifyMask, mlx_loop_end, mlx_data->mlx);
	setup_special_key_events(mlx_data);
	return (0);
}
