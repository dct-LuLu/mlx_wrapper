/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:08:29 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/11 20:24:52 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static int	key_press(int keycode, t_mlx *mlx_data)
{
	t_key_event	*key_event;
	size_t		i;

	mlx_data->key_input.keycode = keycode;
	i = 0;
	while (i < mlx_data->key_input.key_events->num_elements)
	{
		key_event = get_vector_value(mlx_data->key_input.key_events, i);
		if (key_event->is_key(keycode))
		{
			if (key_event->action)
				key_event->action(key_event->arg, mlx_data);
			else if (key_event->status)
			{
				if (key_event->toggle)
					*(key_event->status) = !*(key_event->status);
				else
					*(key_event->status) = true;
			}
		}
		i++;
	}
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
		if (!(key_event->toggle) && key_event->is_key(keycode)
				&& key_event->status)
			*(key_event->status) = false;
		i++;
	}
	return (0);
}

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

static void	ft_mlx_fullscreen_toggle(void *v, t_mlx *mlx_data)
{
	(void)v;
	if (RESIZEABLE)
	{
		mlx_data->fullscreen = !mlx_data->fullscreen;
		mlx_ext_fullscreen(mlx_data->mlx, mlx_data->win, mlx_data->fullscreen);
	}
}

static void	mlx_exit(void *v, t_mlx *mlx_data)
{
	(void)v;
	mlx_loop_end(mlx_data->mlx);
}

static bool	is_f11_key(int keycode)
{
	return (keycode == XK_F11);
}

static int	setup_special_key_events(t_mlx *mlx_data)
{
	if (add_status_key_hook(mlx_data, is_ctrl_key, false,
			&(mlx_data->key_input.ctrl)) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_KEY), FL, LN, FC));
	if (add_status_key_hook(mlx_data, is_shift_key, false,
			&(mlx_data->key_input.shift)) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_KEY), FL, LN, FC));
	if (add_status_key_hook(mlx_data, is_caps_key, true,
			&(mlx_data->key_input.caps)) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_KEY), FL, LN, FC));
	if (add_func_key_hook(mlx_data, is_escape_key, mlx_exit, NULL) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_KEY), FL, LN, FC));
	if (add_func_key_hook(mlx_data, is_f11_key, ft_mlx_fullscreen_toggle, NULL) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_KEY), FL, LN, FC));
	return (0);
}

int	setup_key_input(t_mlx *mlx_data)
{
	mlx_data->key_input.key_events = ft_calloc(1, sizeof(t_vector));
	if (!mlx_data->key_input.key_events)
		return (-1);
	vector_init(mlx_data->key_input.key_events, sizeof(t_key_event));
	mlx_hook(mlx_data->win, KeyPress, KeyPressMask, key_press, mlx_data);
	mlx_hook(mlx_data->win, KeyRelease, KeyReleaseMask, key_release, mlx_data);
	mlx_hook(mlx_data->win, DestroyNotify, StructureNotifyMask,
			mlx_loop_end, mlx_data->mlx);
	if (setup_special_key_events(mlx_data) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_SKEYF), FL, LN, FC));
	return (0);
}
