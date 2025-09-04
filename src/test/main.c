/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:12:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/28 06:21:54 by jaubry--         ###   ########.fr       */
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


static void	setup_print_char_key(t_mlx *mlx_data, bool *is_typing)
{
	t_key_event	char_key_event;

	char_key_event = (t_key_event)
	{
		.is_key = is_char_key,
		.action = (void (*)(void *, t_mlx *))action_char_input,
		.arg = &(mlx_data->key_input),
		.toggle = false,
		.status = is_typing
	};
	vector_add(mlx_data->key_input.key_events, &char_key_event, 1);
}

int	loop(t_mlx *mlx_data)
{
	(void)mlx_data;
	return (0);
}

int	main(void)
{
	t_mlx	*mlx_data;
	bool	is_typing;

	is_typing = false;
	mlx_data = init_mlx(500, 500, "TEST");
	if (!mlx_data)
		return (-1);
	setup_print_char_key(mlx_data, &is_typing);
	start_mlx_loop(mlx_data, loop, mlx_data);
	return (0);
}
