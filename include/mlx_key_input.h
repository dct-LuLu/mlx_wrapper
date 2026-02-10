/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_input.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:07:04 by jaubry--          #+#    #+#             */
/*   Updated: 2026/02/10 10:43:38 by jaubry--         ###   ########.fr       */
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
	bool		*status;//program defined
}				t_key_event;

typedef struct s_key_input
{
	t_vector	*key_events;
	bool		shift;
	bool		ctrl;
	bool		caps;
	int			keycode;
}				t_key_input;

int	add_status_key_hook(t_mlx *mlx_data, bool (*is_key)(int),
		bool toggle, bool *status);

int	add_func_key_hook(t_mlx *mlx_data, bool (*is_key)(int),
		void (*action)(void *, t_mlx *), void *arg);

int	add_status_skey_hook(t_mlx *mlx_data, int keycode,
		bool toggle, bool *status);

int	add_func_skey_hook(t_mlx *mlx_data, int keycode,
		void (*action)(void *, t_mlx *), void *arg);

int	remove_key_hook_by_func(t_mlx *mlx_data,
		void (*action)(void *, t_mlx *));

int	remove_key_hook_by_status(t_mlx *mlx_data,
		bool *status);

#endif//MLX_KEY_INPUT_H
