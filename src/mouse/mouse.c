/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:52:27 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/09 09:58:13 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static void	mouse_move_focus(t_mlx *mlx_data)
{
	mlx_data->mouse_input.warped = true;
	mlx_mouse_move(mlx_data->mlx, mlx_data->win,
			mlx_data->half_size.x, mlx_data->half_size.y);
	XFlush(mlx_data->mlx->display);
	mlx_data->mouse_input.last_pos = mlx_data->half_size;
}

static void	update_mouse_focus_state(void *v, t_mlx *mlx_data)//a ameliorer
{
	bool	focus_mode = mlx_data->mouse_input.focus;

	(void)v;
	if (focus_mode)
	{
		mlx_mouse_hide(mlx_data->mlx, mlx_data->win);
		XGrabPointer(mlx_data->mlx->display, mlx_data->win->window,
				True, PointerMotionMask, GrabModeAsync, GrabModeAsync,
				None, None, CurrentTime);
		mlx_data->mouse_input.pos = mlx_data->half_size;
		mouse_move_focus(mlx_data);
	}
	else
	{
		mlx_mouse_show(mlx_data->mlx, mlx_data->win);
		XUngrabPointer(mlx_data->mlx->display, CurrentTime);
	}
}

static void	mouse_move_action(t_mlx *mlx_data)
{
	t_mouse_event	*mouse_event;
	size_t			i;

	i = 0;
	while (i < mlx_data->mouse_input.move_events->num_elements)
	{
		mouse_event = get_vector_value(mlx_data->mouse_input.move_events, i);
		if (mouse_event->action)
			mouse_event->action(mouse_event->arg, mlx_data);
		i++;
	}
}

static int	mouse_move(int x, int y, t_mlx *mlx_data)
{
	if (mlx_data->mouse_input.warped)
	{
		mlx_data->mouse_input.warped = false;
		return (0);
	}
	if (mlx_data->mouse_input.focus)
		mouse_move_focus(mlx_data);
	else
		mlx_data->mouse_input.last_pos = mlx_data->mouse_input.pos;
	mlx_data->mouse_input.pos.x = x;
	mlx_data->mouse_input.pos.y = y;
	mouse_move_action(mlx_data);
	return (0);
}

static int	setup_mouse_movement(t_mlx *mlx_data)
{
	mlx_data->mouse_input.move_events = ft_calloc(1, sizeof(t_vector));
	if (!mlx_data->mouse_input.move_events)
		return (-1);
	vector_init(mlx_data->mouse_input.move_events, sizeof(t_mouse_event));
	mlx_hook(mlx_data->win, MotionNotify,
			PointerMotionMask, mouse_move, mlx_data);
	return (0);
}

int	setup_mouse_input(t_mlx *mlx_data)
{
	return (setup_mouse_movement(mlx_data));
}
