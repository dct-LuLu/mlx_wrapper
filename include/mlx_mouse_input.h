/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:52:34 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 02:05:36 by jaubry--         ###   ########.fr       */
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

typedef struct s_mouse_event//rename move_event
{
	void	(*action)(void *, t_mlx *);
	void	*arg;
}			t_mouse_event;


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
