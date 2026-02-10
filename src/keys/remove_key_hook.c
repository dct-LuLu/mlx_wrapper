/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_key_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:52:02 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 10:45:45 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	remove_key_hook_by_func(t_mlx *mlx_data, void (*action)(void *, t_mlx *))
{
	t_key_event	*key_event;
	size_t		i;

	i = 0;
	while (i < mlx_data->key_input.key_events->num_elements)
	{
		key_event = get_vector_value(mlx_data->key_input.key_events, i);
		if (key_event->action && (key_event->action == action))
		{
			remove_vector_elem(mlx_data->key_input.key_events, i);
			return (0);
		}
		i++;
	}
	return (-1);
}

int	remove_key_hook_by_status(t_mlx *mlx_data, bool *status)
{
	t_key_event	*key_event;
	size_t		i;

	i = 0;
	while (i < mlx_data->key_input.key_events->num_elements)
	{
		key_event = get_vector_value(mlx_data->key_input.key_events, i);
		if (key_event->status && (key_event->status == status))
		{
			remove_vector_elem(mlx_data->key_input.key_events, i);
			return (0);
		}
		i++;
	}
	return (-1);
}
