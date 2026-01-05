/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:04:54 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/05 11:48:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

char	*skip_comment(const int fd);

static inline int	parse_pnm_type(const int fd)
{
	t_pnm_type	pnm_type;
	char		*line;

	line = skip_comment(fd);
	if (!line)
		return (neg_error(pack_err(MLXW_ID, MLXW_E_PNMFLN), FL, LN, FC));
	if (line[0] != 'P')
		return (neg_error(pack_err(MLXW_ID, MLXW_E_PNMFFMT), FL, LN, FC));
	pnm_type = ft_strncmp(line, "P4", 2);
	free(line);
	if (pnm_type < 0)
		return (neg_error(pack_err(MLXW_ID, MLXW_E_PNMAFMT), FL, LN, FC));
	else if (pnm_type > PAM_TYPE)
		return (neg_error(pack_err(MLXW_ID, MLXW_E_PNMUFMT), FL, LN, FC));
	return (pnm_type);
}

t_texture	*pnm_parser(const int fd, t_texture *tex)
{
	const t_pnm_type	pnm_type = parse_pnm_type(fd);

	if (pnm_type == PBM_TYPE)
		tex = parse_pbm(fd, tex);
	else if (pnm_type == PGM_TYPE)
		tex = parse_pgm(fd, tex);
	else if (pnm_type == PPM_TYPE)
		tex = parse_ppm(fd, tex);
	else if (pnm_type == PAM_TYPE)
		tex = parse_pam(fd, tex);
	else
		return (nul_error(pack_err(MLXW_ID, MLXW_E_PNMDFMT), FL, LN, FC));
	return (tex);
}
