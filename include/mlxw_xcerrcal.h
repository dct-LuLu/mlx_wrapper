/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_xcerrcal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:02:28 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/15 01:29:57 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_XCERRCAL_H
# define MLXW_XCERRCAL_H

#define MLXW_ID 3

typedef enum e_mlxw_err
{
	MLXW_E_INITF = 1,
	MLXW_E_WSIZE,
	MLXW_E_MLXF,
	MLXW_E_WINF,
	MLXW_E_IMGF,
	MLXW_E_SKEYF,
	MLXW_E_KEYF,
	MLXW_E_WMEVENT,
	MLXW_E_BUTTONHF,
	MLXW_E_MOTIONHF,
	MLXW_E_MOUSEF,
	MLXW_E_EVENTH,
	MLXW_ERRS_NUM
}	t_mlxw_err;

#define MLXW_E_MSG_INITF "Failed to initialize mlx_wrapper correctly"
#define MLXW_E_MSG_WSIZE "Invalid window size, WIDTH/HEIGHT and MAX_WIDTH/MAX_HEIGTH must be even"
#define MLXW_E_MSG_MLXF "Minilibx instance initialization failed"
#define MLXW_E_MSG_WINF "Window initialization failed"
#define MLXW_E_MSG_IMGF "Image initialization failed"
#define MLXW_E_MSG_SKEYF "Setup of standard keys and mod keys behaviour failed"
#define MLXW_E_MSG_KEYF "Key inputs hook logic initialization failed"
#define MLXW_E_MSG_WMEVENT "Mouse button hook with keycode value 0 is forbidden"
#define MLXW_E_MSG_BUTTONHF "Mouse buttons hook logic initialization failed"
#define MLXW_E_MSG_MOTIONHF "Mouse motion hook logic initialization failed"
#define MLXW_E_MSG_MOUSEF "Mouse inputs hook logic initialization failed"
#define MLXW_E_MSG_EVENTH "Failed to attach new event hook"

void	register_mlxw_errors(void);

#endif//MLXW_XCERRCAL_H
