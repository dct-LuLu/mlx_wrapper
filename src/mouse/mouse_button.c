/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:26:12 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 20:34:55 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static inline int	button_press(t_mbuttons keycode,
		int x, int y, t_mlx *mlx_data)
{
	t_button_event	*button_event;
	size_t			i;

	i = 0;
	while (i < mlx_data->mouse_input.button_events->num_elements)
	{
		button_event = get_vector_value(mlx_data->mouse_input.button_events, i);
		if (button_event->keycode == keycode)
		{
			if (button_event->action)
				button_event->action(vec2i(x, y), MPRESS,
					button_event->arg, mlx_data);
			else if (button_event->status)
				*(button_event->status) = true;
		}
		i++;
	}
	return (0);
}

static inline int	button_release(t_mbuttons keycode,
		int x, int y, t_mlx *mlx_data)
{
	t_button_event	*button_event;
	size_t			i;

	i = 0;
	while (i < mlx_data->mouse_input.button_events->num_elements)
	{
		button_event = get_vector_value(mlx_data->mouse_input.button_events, i);
		if (button_event->keycode == keycode)
		{
			if (button_event->action)
				button_event->action(vec2i(x, y), MRELEASE,
					button_event->arg, mlx_data);
			else if (button_event->status)
				*(button_event->status) = false;
		}
		i++;
	}
	return (0);
}

int	setup_mouse_button(t_mlx *mlx_data)
{
	mlx_data->mouse_input.button_events = ft_calloc(1, sizeof(t_vector));
	if (!mlx_data->mouse_input.button_events)
		return (-1);
	vector_init(mlx_data->mouse_input.button_events, sizeof(t_button_event));
	mlx_hook(mlx_data->win, ButtonPress,
		ButtonPressMask, button_press, mlx_data);
	mlx_hook(mlx_data->win, ButtonRelease,
		ButtonReleaseMask, button_release, mlx_data);
	return (0);
}
