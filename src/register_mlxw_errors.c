/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_mlxw_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:01:59 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/05 12:10:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xcerrcal.h"
#include "mlxw_xcerrcal.h"

void	register_mlxw_errors(void)
{
	const char	*err_msgs[]
		= {
		MLXW_E_MSG_INITF, MLXW_E_MSG_WSIZE,
		MLXW_E_MSG_MLXF, MLXW_E_MSG_WINF, MLXW_E_MSG_IMGF,
		MLXW_E_MSG_SKEYF, MLXW_E_MSG_KEYF,
		MLXW_E_MSG_WMEVENT,
		MLXW_E_MSG_BUTTONHF, MLXW_E_MSG_MOTIONHF, MLXW_E_MSG_MOUSEF,
		MLXW_E_MSG_EVENTH,
		MLXW_E_MSG_PNMCREAD, MLXW_E_MSG_PNMALOC, MLXW_E_MSG_PNMWRT,
		MLXW_E_MSG_PNMDAT, MLXW_E_MSG_PNMHEAD, MLXW_E_MSG_PNMFLN,
		MLXW_E_MSG_PNMFFMT, MLXW_E_MSG_PNMAFMT, MLXW_E_MSG_PNMUFMT,
		MLXW_E_MSG_PNMDFMT,
		MLXW_E_MSG_PNMPWH, MLXW_E_MSG_PNMPMXV,
		MLXW_E_MSG_PNMRES, MLXW_E_MSG_PNMCHN, MLXW_E_MSG_PNMMXV,
		MLXW_E_MSG_PAMAT,
		MLXW_E_MSG_PAMHDMS, MLXW_E_MSG_PAMHEAD,
		MLXW_E_MSG_PNM, MLXW_E_MSG_PBM, MLXW_E_MSG_PGM, MLXW_E_MSG_PPM,
		MLXW_E_MSG_PAM,
	};

	bulk_register_error(MLXW_ERRS_NUM - 1, MLXW_ID, (const char **)err_msgs);
}
