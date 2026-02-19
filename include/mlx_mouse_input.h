/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:52:34 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/18 09:12:57 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MOUSE_INPUT_H
# define MLX_MOUSE_INPUT_H

typedef enum e_mbuttons
{
	MNULL = 0,
	MLCLICK,
	MWHEELCLICK,
	MRCLICK,
	MWHEELUP,
	MWHEELDOWN
}	t_mbuttons;

typedef enum e_maction
{
	MNONE = 0,
	MPRESS,
	MRELEASE
}	t_maction;

typedef void	t_button_action(t_vec2i, t_maction, void *, t_mlx *);

typedef struct s_button_event
{
	t_button_action	*action;
	void			*arg;
	bool			*status;
	t_mbuttons		keycode;
	ssize_t			event_idx;
}					t_button_event;

ssize_t	add_func_button_hook(t_mlx *mlx_data, t_mbuttons keycode,
			t_button_action *action, void *arg);

int		remove_button_hook(t_mlx *mlx_data, ssize_t event_idx);

void	update_mouse_focus_state(void *v, t_mlx *mlx_data);

typedef void	t_move_action(void *, t_mlx *);

typedef struct s_move_event
{
	t_move_action	*action;
	void			*arg;
	ssize_t			event_idx;
}					t_move_event;

ssize_t	add_func_move_hook(t_mlx *mlx_data,
			t_move_action *action, void *arg);

int		remove_move_hook(t_mlx *mlx_data, ssize_t event_idx);

typedef struct s_mouse_input
{
	t_vector	*move_events;
	t_vector	*button_events;
	t_vec2i		pos;
	t_vec2i		last_pos;
	bool		warped;
	bool		focus;
}				t_mouse_input;

#endif//MLX_MOUSE_INPUT_H
