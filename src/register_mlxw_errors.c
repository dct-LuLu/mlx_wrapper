/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_mlxw_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:01:59 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/11 20:26:45 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xcerrcal.h"
#include "mlxw_xcerrcal.h"

void	register_mlxw_errors(void)
{
	const char	*err_msgs[] =
	{
		MLXW_E_MSG_INITF,
		MLXW_E_MSG_WSIZE,
		MLXW_E_MSG_MLXF,
		MLXW_E_MSG_WINF,
		MLXW_E_MSG_IMGF,
		MLXW_E_MSG_SKEYF,
		MLXW_E_MSG_KEYHF,
		MLXW_E_MSG_MOUSEHF,
		MLXW_E_MSG_KEY
	};
	bulk_register_error(MLXW_ERRS_NUM - 1, MLXW_ID, (const char **)err_msgs);
}
