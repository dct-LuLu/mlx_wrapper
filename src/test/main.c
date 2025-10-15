/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:12:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/16 00:37:25 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xcerrcal.h"
#include "lft_xcerrcal.h"
#include "mlxw_xcerrcal.h"
#include "mlx_wrapper.h"
#include <stdio.h>
#include <unistd.h>

#define MIN_CHAR "       '    ,-./0123456789 ; =                             [\\]  `abcdefghijklmnopqrstuvwxyz"
#define MAX_CHAR "       \"    <_>?)!@#$%^&*( : +                             {|}  ~ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMPAD_CHAR "7486293150.          *+ - /"

t_vec2i	start_pos;
t_vec2i	end_pos;

static char	get_char_input(int keycode, bool maj)
{
	char	c;

	c = '\0';
	if (is_char_key(keycode))
	{
		if (is_tkl_char_key(keycode))
		{
			if (maj)
				c = MAX_CHAR[keycode - ' '];
			else
				c = MIN_CHAR[keycode - ' '];
		}
		else if (is_tab_key(keycode))
			c = '\t';
		else if (is_enter_key(keycode))
			c = '\n';
		else if (is_numpad_char_key(keycode))
			c = NUMPAD_CHAR[keycode - 0xff95];
	}
	return (c);
}

static void	action_char_input(t_key_input *key_input, t_mlx *mlx)
{
	char	c;

	(void)mlx;
	c = get_char_input(key_input->keycode, key_input->caps ^ key_input->shift);
	write(1, &c, 1);
}

static bool	is_f1_key(int keycode)
{
	return (XK_F1 == keycode);
}

int	loop(t_mlx *mlx_data)
{
	ft_mlx_batch_put(&mlx_data->img, vec2i(0, 0), vec2i(WIDTH, HEIGHT), 0x000000);
	ft_mlx_line_put(&mlx_data->img, vec2i(0, 0), vec2i(WIDTH, HEIGHT), 0xFF0000);
	if (start_pos.x != 0 && start_pos.y != 0)
		ft_mlx_select(&mlx_data->img, start_pos, end_pos, 0xFFFFFF);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.img, 0, 0);
	return (0);
}

void	print_mouse_pos(void *v, t_mlx *mlx_data)
{
	(void)v;
	if (start_pos.x != 0 && start_pos.y != 0)
		end_pos = vec2i(mlx_data->mouse_input.pos.x, mlx_data->mouse_input.pos.y);
	/*
	printf("last x: %d,y: %d\t\tcur x: %d, y: %d\n",
			mlx_data->mouse_input.last_pos.x, mlx_data->mouse_input.last_pos.y,
			mlx_data->mouse_input.pos.x, mlx_data->mouse_input.pos.y);
	*/
}

void	add_mouse_hook(t_mlx *mlx_data)
{
	const t_mouse_event	mouse_event = (t_mouse_event)
	{
		.action = print_mouse_pos,
		.arg = NULL
	};
	vector_add(mlx_data->mouse_input.move_events, (void *)&mouse_event, 1);
}

void	switch_focus_state(void *v, t_mlx *mlx_data)
{
	mlx_data->mouse_input.focus = !mlx_data->mouse_input.focus;
	update_mouse_focus_state(v, mlx_data);
}

void	register_errors(void)
{
	register_lft_errors();
	register_mlxw_errors();
}


void	test(t_vec2i pos, t_maction action, void *arg, t_mlx *mlx_data)
{
	(void)mlx_data;
	if (action == MPRESS)
	{
		start_pos = pos;
		end_pos = pos;
	}
	else if (action == MRELEASE)
	{
		start_pos = vec2i(0, 0);
		end_pos = vec2i(0, 0);
	}
	(void)arg;
}

int	main(void)
{
	t_mlx	*mlx_data;
	int		ret;

	ret = 0;
	register_errors();
	mlx_data = init_mlx(WIDTH, HEIGHT, "TEST");
	if (!mlx_data)
		ret = error(pack_err(MLXW_ID, MLXW_E_INITF), FL, LN, FC);
	ft_mlx_center_window(mlx_data);
	mlx_data->mouse_input.focus = false;
	update_mouse_focus_state(NULL, mlx_data);
	add_func_key_hook(mlx_data, is_f1_key, switch_focus_state, NULL);
	add_func_key_hook(mlx_data, is_char_key,
			(void (*)(void *, t_mlx *))action_char_input, &(mlx_data->key_input));
	add_mouse_hook(mlx_data);
	add_func_button_hook(mlx_data, MLCLICK, test, NULL);
	start_mlx_loop(mlx_data, loop, mlx_data);
	print_errs();
	return (ret);
}
