/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_mouse_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:54:10 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:11:42 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	remove_button_hook(t_mlx *mlx_data, ssize_t event_idx)
{
	t_button_event	*button_event;
	size_t			i;

	i = 0;
	while (i < mlx_data->mouse_input.button_events->num_elements)
	{
		button_event = get_vector_value(mlx_data->mouse_input.button_events, i);
		if (button_event->event_idx == event_idx)
		{
			remove_vector_elem(mlx_data->mouse_input.button_events, i);
			return (0);
		}
		i++;
	}
	return (-1);
}

int	remove_move_hook(t_mlx *mlx_data, ssize_t event_idx)
{
	t_move_event	*move_event;
	size_t			i;

	i = 0;
	while (i < mlx_data->mouse_input.move_events->num_elements)
	{
		move_event = get_vector_value(mlx_data->mouse_input.move_events, i);
		if (move_event->event_idx == event_idx)
		{
			remove_vector_elem(mlx_data->mouse_input.move_events, i);
			return (0);
		}
		i++;
	}
	return (-1);
}

