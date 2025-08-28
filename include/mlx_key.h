/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 05:02:16 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/28 05:40:35 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEY_H
# define MLX_KEY_H
# include <stdbool.h>
# include <X11/keysym.h>
# include "mlx_tkl_key.h"
# include "mlx_numpad_key.h"
# include "mlx_special_key.h"

static inline bool	is_char_key(const int keycode)
{
	return (is_tkl_char_key(keycode) || is_numpad_char_key(keycode)
			|| is_enter_key(keycode) || is_tab_key(keycode));
}

#endif//MLX_KEY_H
