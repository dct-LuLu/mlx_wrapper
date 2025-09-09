/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:12:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/09 09:38:59 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include <stdio.h>

#define MIN_CHAR "       '    ,-./0123456789 ; =                             [\\]  `abcdefghijklmnopqrstuvwxyz"
#define MAX_CHAR "       \"    <_>?)!@#$%^&*( : +                             {|}  ~ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMPAD_CHAR "7486293150.          *+ - /"

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

#include <unistd.h>
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
	(void)mlx_data;
	return (0);
}

int	main(void)
{
	t_mlx	*mlx_data;

	mlx_data = init_mlx(WIDTH, HEIGHT, "TEST");
	if (!mlx_data)
		return (-1);
	ft_mlx_center_window(mlx_data);
	//setup_mouse_focus(mlx_data);
	add_status_key_hook(mlx_data, is_f1_key, true, &(mlx_data->mouse_input.focus));
	add_func_key_hook(mlx_data, is_char_key,
			(void (*)(void *, t_mlx *))action_char_input, &(mlx_data->key_input));
	start_mlx_loop(mlx_data, loop, mlx_data);
	return (0);
}
