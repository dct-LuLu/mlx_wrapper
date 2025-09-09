/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:52:27 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/09 02:10:26 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static void	mouse_move_focus(t_mlx *mlx_data)
{
	mlx_data->mouse_input.warped = true;
	mlx_mouse_move(mlx_data->mlx, mlx_data->win,
			mlx_data->half_size.x, mlx_data->half_size.y);
	XFlush(mlx_data->mlx->display);
}

static void	check_mouse_focus_state(t_mlx *mlx_data)
{
	bool	focus_mode = mlx_data->mouse_input.focus;

	if (focus_mode)
	{
		mlx_mouse_hide(mlx_data->mlx, mlx_data->win);
		XGrabPointer(mlx_data->mlx->display, mlx_data->win->window,
				True, PointerMotionMask, GrabModeAsync, GrabModeAsync,
				mlx_data->win->window, None, CurrentTime);
	}
	else
	{
		mlx_mouse_show(mlx_data->mlx, mlx_data->win);
		XUngrabPointer(mlx_data->mlx->display, CurrentTime);
	}
}

static int	mouse_move(int x, int y, t_mlx *mlx_data)
{
	if (mlx_data->mouse_input.warped)
	{
		mlx_data->mouse_input.warped = false;
		return (0);
	}
	check_mouse_focus_state(mlx_data);
	if (mlx_data->mouse_input.focus)
		mouse_move_focus(mlx_data);
	printf("last x:%d y:%d\t\tcur x:%d y:%d\n", mlx_data->mouse_input.last_pos.x,
			mlx_data->mouse_input.last_pos.y, mlx_data->mouse_input.pos.x, mlx_data->mouse_input.pos.y);
	mlx_data->mouse_input.last_pos.x = mlx_data->mouse_input.pos.x;
	mlx_data->mouse_input.last_pos.y = mlx_data->mouse_input.pos.y;
	mlx_data->mouse_input.pos.x = x;
	mlx_data->mouse_input.pos.y = y;
	return (0);
}

static int	setup_mouse_movement(t_mlx *mlx_data)
{
	mlx_hook(mlx_data->win, MotionNotify,
			PointerMotionMask, mouse_move, mlx_data);
	return (0);
}

int	setup_mouse_input(t_mlx *mlx_data)
{
	return (setup_mouse_movement(mlx_data));
}
