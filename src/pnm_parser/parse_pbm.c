/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pbm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:44:07 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/05 12:04:02 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	read_binary_data(const int fd, t_texture *tex);
int	parse_pbgpm_header(const int fd, t_texture *tex);

t_texture	*parse_pbm(const int fd, t_texture *tex)
{
	if (parse_pbgpm_header(fd, tex) == -1)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_PNMHEAD), FL, LN, FC));
	tex->channels = 1;
	tex->line_len = tex->width * tex->channels;
	if (read_binary_data(fd, tex) == -1)
		return (nul_error(pack_err(MLXW_ID, MLXW_E_PNMDAT), FL, LN, FC));
	return (tex);
}
