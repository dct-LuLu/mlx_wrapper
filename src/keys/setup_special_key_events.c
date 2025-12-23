/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_special_key_events.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:30:55 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 20:31:14 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline void	ft_mlx_fullscreen_toggle(void *v, t_mlx *mlx_data)
{
	(void)v;
	if (RESIZEABLE)
	{
		mlx_data->fullscreen = !mlx_data->fullscreen;
		mlx_ext_fullscreen(mlx_data->mlx, mlx_data->win, mlx_data->fullscreen);
	}
}

static inline void	mlx_exit(void *v, t_mlx *mlx_data)
{
	(void)v;
	mlx_loop_end(mlx_data->mlx);
}

int	setup_special_key_events(t_mlx *mlx_data)
{
	if (add_status_key_hook(mlx_data, is_ctrl_key, false,
			&(mlx_data->key_input.ctrl)) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_status_key_hook(mlx_data, is_shift_key, false,
			&(mlx_data->key_input.shift)) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_status_key_hook(mlx_data, is_caps_key, true,
			&(mlx_data->key_input.caps)) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_key_hook(mlx_data, is_escape_key, mlx_exit, NULL) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	if (add_func_skey_hook(mlx_data, XK_F11,
			ft_mlx_fullscreen_toggle, NULL) != 0)
		return (error(pack_err(MLXW_ID, MLXW_E_EVENTH), FL, LN, FC));
	return (0);
}
