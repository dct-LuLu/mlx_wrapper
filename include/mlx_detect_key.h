/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_detect_key.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 05:02:16 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 19:09:36 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DETECT_KEY_H
# define MLX_DETECT_KEY_H
# include <stdbool.h>
# include <X11/keysym.h>
# include "mlx_detect_tkl_key.h"
# include "mlx_detect_numpad_key.h"
# include "mlx_detect_special_key.h"

static inline bool	is_char_key(const int keycode)
{
	return (is_tkl_char_key(keycode) || is_numpad_char_key(keycode)
		|| is_enter_key(keycode) || is_tab_key(keycode));
}

#endif//MLX_DETECT_KEY_H
