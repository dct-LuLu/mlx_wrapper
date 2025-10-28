/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:12:25 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/28 01:47:13 by jaubry--         ###   ########.fr       */
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

t_vec2i		start_pos = (t_vec2i){{0, 0}};
t_vec2i		end_pos = (t_vec2i){{0, 0}};
t_box		box;
t_box		checkbox;
t_box		checkedbox;

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
	ft_mlx_batch_put(&mlx_data->img, vec2i(0, 0), vec2i(WIDTH, HEIGHT), drgb_int(0x000000));
	//ft_mlx_line_put(&mlx_data->img, vec2i(0, 0), vec2i(WIDTH, HEIGHT), drgb_int(0xFF0000));
	//ft_mlx_line_put(&mlx_data->img, vec2i(WIDTH, 0), vec2i(0, HEIGHT), drgb_int(0xFF0000));
	draw_box(&mlx_data->img, box);
	draw_box(&mlx_data->img, checkbox);
	draw_box(&mlx_data->img, checkedbox);
	t_vec2i check[3];
	check[0] = vec2i(checkedbox._lt.corner.x + 3, checkedbox._lt.corner.y + 9);
	check[1] = vec2i(checkedbox._lt.corner.x + 7, checkedbox._lt.corner.y + 13);
	check[2] = vec2i(checkedbox._lt.corner.x + 14, checkedbox._lt.corner.y + 6);
	ft_mlx_line_put(&mlx_data->img, check[0], check[1], drgb_int(0xFFFFFF));
	ft_mlx_line_put(&mlx_data->img, check[1], check[2], drgb_int(0xFFFFFF));
	if (start_pos.x != 0 && start_pos.y != 0)
	{
		//ft_mlx_line_put(&mlx_data->img, start_pos, end_pos, drgb_int(0xFF00FF));
		//ft_mlx_quad_curve_put(&mlx_data->img, (t_vec2i[3]){start_pos, vec2i(WIDTH/2, HEIGHT/2), end_pos}, drgb_int(0x00FFFF));
		ft_mlx_select_put(&mlx_data->img, start_pos, end_pos, drgb_int(0xFFFFFF));
		//ft_mlx_circle_aput(&mlx_data->img, start_pos, vec2i_dist(start_pos, end_pos), t);
		//ft_mlx_out_circle_aput(&mlx_data->img, start_pos, vec2i_dist(start_pos, end_pos), t);
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.img, 0, 0);
	return (0);
}

void	print_mouse_pos(void *v, t_mlx *mlx_data)
{
	(void)v;
	if (start_pos.x != 0 && start_pos.y != 0)
		end_pos = vec2i(mlx_data->mouse_input.pos.x, mlx_data->mouse_input.pos.y);
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

void	create_box(t_mlx *mlx_data)
{
	(void)mlx_data;
	box = (t_box)
	{
		.pos = vec2i(WIDTH / 2, HEIGHT / 2),
		.anchor = CENTER,
		.size = vec2i(160, 40),
		.color = rgba_int(29, 30, 31, 255),
		.radius = (t_radius)
		{
			.style = FULL_PX,
			.full = 20
		},
		.border = (t_border)
		{
			.size = 1,
			.color = rgba_int(61, 62, 62, 255),
			.style = SOLID
		}
	};
	precompute_box(&box);
}

void	create_checkbox(t_mlx *mlx_data)
{
	(void)mlx_data;
	checkbox = (t_box)
	{
		.pos = vec2i(WIDTH / 4, HEIGHT / 2),
		.anchor = CENTER,
		.size = vec2i(17, 17),
		.color = rgba_int(29, 30, 31, 255),
		.radius = (t_radius)
		{
			.style = FULL_PX,
			.full = 3
		},
		.border = (t_border)
		{
			.size = 1,
			.color = rgba_int(61, 62, 62, 255),
			.style = SOLID
		}
	};
	precompute_box(&checkbox);
}

void	create_checkedbox(t_mlx *mlx_data)
{
	(void)mlx_data;
	checkedbox = (t_box)
	{
		.pos = vec2i(WIDTH / 5, HEIGHT / 2),
		.anchor = CENTER,
		.size = vec2i(17, 17),
		.color = rgba_int(56, 93, 209, 255),
		.radius = (t_radius)
		{
			.style = FULL_PX,
			.full = 3
		},
		.border = (t_border)
		{
			.size = 0,
			.color = rgba_int(61, 62, 62, 255),
			.style = SOLID
		}
	};
	precompute_box(&checkedbox);
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

	create_box(mlx_data);
	create_checkbox(mlx_data);
	create_checkedbox(mlx_data);

	start_mlx_loop(mlx_data, loop, mlx_data);
	print_errs();
	return (ret);
}
