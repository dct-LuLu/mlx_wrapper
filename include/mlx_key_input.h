/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_input.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:07:04 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/19 15:55:58 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEY_INPUT_H
# define MLX_KEY_INPUT_H
# include "mlx_detect_key.h"

typedef struct s_mlx	t_mlx;

typedef struct s_key_event
{
	bool		(*is_key)(int);
	int			keycode;
	bool		toggle;
	void		(*action)(void *, t_mlx *);
	void		*arg;
	bool		*status;
	ssize_t		event_idx;
}				t_key_event;

typedef struct s_key_input
{
	t_vector	*key_events;
	bool		shift;
	bool		ctrl;
	bool		caps;
	int			keycode;
}				t_key_input;

ssize_t	add_status_key_hook(t_mlx *mlx_data, bool (*is_key)(int),
			bool toggle, bool *status);

ssize_t	add_func_key_hook(t_mlx *mlx_data, bool (*is_key)(int),
			void (*action)(void *, t_mlx *), void *arg);

ssize_t	add_status_skey_hook(t_mlx *mlx_data, int keycode,
			bool toggle, bool *status);

ssize_t	add_func_skey_hook(t_mlx *mlx_data, int keycode,
			void (*action)(void *, t_mlx *), void *arg);

int		remove_key_hook(t_mlx *mlx_data, ssize_t event_idx);

#endif//MLX_KEY_INPUT_H
