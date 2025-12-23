/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_detect_numpad_key.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 05:01:28 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 19:09:52 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DETECT_NUMPAD_KEY_H
# define MLX_DETECT_NUMPAD_KEY_H
# include <stdbool.h>
# include <X11/keysym.h>

static inline bool	is_numpad_num_key(const int keycode)
{
	return ((keycode >= 0xff95) && (keycode <= 0xff9e));
}

static inline bool	is_numpad_special_key(const int keycode)
{
	return ((keycode == XK_KP_Multiply) || (keycode == XK_KP_Add)
		|| (keycode == XK_KP_Subtract) || (keycode == XK_KP_Decimal)
		|| (keycode == XK_KP_Divide) || (keycode == XK_KP_Delete));
}

static inline bool	is_numpad_char_key(const int keycode)
{
	return (is_numpad_num_key(keycode) || is_numpad_special_key(keycode));
}

#endif//MLX_DETECT_NUMPAD_KEY_H
