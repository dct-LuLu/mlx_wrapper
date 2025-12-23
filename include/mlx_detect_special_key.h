/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_detect_special_key.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 05:04:33 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 19:28:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DETECT_SPECIAL_KEY_H
# define MLX_DETECT_SPECIAL_KEY_H

# include <stdbool.h>
# include <X11/keysym.h>

static inline bool	is_shift_key(int keycode)
{
	return ((keycode == XK_Shift_L) || (keycode == XK_Shift_R));
}

static inline bool	is_ctrl_key(int keycode)
{
	return ((keycode == XK_Control_L) || (keycode == XK_Control_R));
}

static inline bool	is_caps_key(int keycode)
{
	return (keycode == XK_Caps_Lock);
}

static inline bool	is_escape_key(int keycode)
{
	return (keycode == XK_Escape);
}

#endif//MLX_DETECT_SPECIAL_KEY_H
