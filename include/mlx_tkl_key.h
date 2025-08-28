/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tkl_key.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 05:00:11 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/28 05:40:43 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TKL_KEY_H
# define MLX_TKL_KEY_H
# include <stdbool.h>
# include <X11/keysym.h>

static inline bool	is_tkl_alpha_key(const int keycode)
{
	return (((keycode >= XK_a) && (keycode <= XK_z)));
}

static inline bool	is_tkl_special_key(const int keycode)
{
	return (((keycode >= XK_apostrophe) && (keycode <= XK_grave)));
}

static inline bool	is_tkl_char_key(const int keycode)
{
	 return (is_tkl_alpha_key(keycode) || is_tkl_special_key(keycode)
	 		 || (keycode == XK_space));
}

#endif//MLX_TKL_KEY_H
