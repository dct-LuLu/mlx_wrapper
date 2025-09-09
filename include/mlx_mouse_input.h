/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:52:34 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/09 09:59:28 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MOUSE_INPUT_H
# define MLX_MOUSE_INPUT_H

void	update_mouse_focus_state(void *v, t_mlx *mlx_data);

typedef struct s_mouse_event
{
	void	(*action)(void *, t_mlx *);
	void	*arg;
}			t_mouse_event;

typedef struct s_mouse_input
{
	t_vector	*move_events;
	t_vec2i		pos;
	t_vec2i		last_pos;
	bool		warped;
	bool		focus;
}			t_mouse_input;

#endif//MLX_MOUSE_INPUT_H
