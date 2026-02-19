/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:23:52 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 15:57:02 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include <X11/extensions/XTest.h>

static void	mouse_move_focus(t_mlx *mlx_data)
{
	XEvent	event;

	mlx_data->mouse_input.warped = true;
	if (XTEST)
	{
		XTestFakeMotionEvent(mlx_data->mlx->display,
			DefaultScreen(mlx_data->mlx->display),
			MAX_WIDTH / 2, MAX_HEIGHT / 2, CurrentTime);
		while (XCheckMaskEvent(mlx_data->mlx->display,
				PointerMotionMask, &event))
		{
		}
	}
	else
		mlx_mouse_move(mlx_data->mlx, mlx_data->win, WIDTH / 2, HEIGHT / 2);
	XFlush(mlx_data->mlx->display);
	mlx_data->mouse_input.last_pos = mlx_data->half_size;
}

void	update_mouse_focus_state(void *v, t_mlx *mlx_data)
{
	const bool	focus_mode = mlx_data->mouse_input.focus;

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
	t_move_event	*move_event;
	size_t			i;

	i = 0;
	while (i < mlx_data->mouse_input.move_events->num_elements)
	{
		move_event = get_vector_value(mlx_data->mouse_input.move_events, i);
		if (move_event->action)
			move_event->action(move_event->arg, mlx_data);
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

int	setup_mouse_movement(t_mlx *mlx_data)
{
	mlx_data->mouse_input.move_events = ft_calloc(1, sizeof(t_vector));
	if (!mlx_data->mouse_input.move_events)
		return (-1);
	vector_init(mlx_data->mouse_input.move_events, sizeof(t_move_event));
	mlx_hook(mlx_data->win, MotionNotify,
		PointerMotionMask, mouse_move, mlx_data);
	return (0);
}
