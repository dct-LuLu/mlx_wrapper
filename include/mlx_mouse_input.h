/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:52:34 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/27 04:07:28 by jaubry--         ###   ########.fr       */
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

typedef struct s_button_event
{
	void		(*action)(t_vec2i, t_maction, void *, t_mlx *);
	void		*arg;
	bool		*status;
	t_mbuttons	keycode;
}				t_button_event;

int	add_func_button_hook(t_mlx *mlx_data, t_mbuttons keycode,
		void (*action)(t_vec2i, t_maction, void *, t_mlx *), void *arg);

void	update_mouse_focus_state(void *v, t_mlx *mlx_data);

typedef struct s_move_event//rename move_event
{
	void	(*action)(void *, t_mlx *);
	void	*arg;
}			t_move_event;

int	add_func_move_hook(t_mlx *mlx_data, void (*action)(void *, t_mlx *), void *arg);


typedef struct s_mouse_input
{
	t_vector	*move_events;
	t_vector	*button_events;
	t_vec2i		pos;
	t_vec2i		last_pos;
	bool		warped;
	bool		focus;
}			t_mouse_input;

#endif//MLX_MOUSE_INPUT_H
