/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_key_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:52:02 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/20 16:07:43 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	remove_key_hook(t_mlx *mlx_data, ssize_t event_idx)
{
	t_key_event	*key_event;
	size_t		i;

	i = 0;
	if (!mlx_data || !mlx_data->key_input.key_events)
		return (0);
	while (i < mlx_data->key_input.key_events->num_elements)
	{
		key_event = get_vector_value(mlx_data->key_input.key_events, i);
		if (key_event->event_idx == event_idx)
		{
			remove_vector_elem(mlx_data->key_input.key_events, i);
			return (0);
		}
		i++;
	}
	return (-1);
}
