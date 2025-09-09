/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:52:34 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/08 23:14:34 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MOUSE_INPUT_H
# define MLX_MOUSE_INPUT_H

typedef struct s_mouse_input
{
	t_vec2i	pos;
	t_vec2i	last_pos;
	bool	warped;
	bool	focus;
}			t_mouse_input;

#endif//MLX_MOUSE_INPUT_H
