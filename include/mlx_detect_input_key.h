/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_detect_input_key.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:26:57 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 19:28:20 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DETECT_INPUT_KEY_H
# define MLX_DETECT_INPUT_KEY_H

# include <stdbool.h>
# include <X11/keysym.h>

static inline bool	is_enter_key(const int keycode)
{
	return ((keycode == XK_Return) || (keycode == XK_KP_Enter));
}

static inline bool	is_tab_key(const int keycode)
{
	return (keycode == XK_Tab);
}

#endif//MLX_DETECT_INPUT_KEY_H
