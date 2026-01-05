/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pbgpm_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:18:49 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/05 12:03:48 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	check_already_parsed_type(const int fd, char **line);
bool	has_invalid_fields(t_texture *tex, int *maxval);
char	*skip_comment(const int fd);

int	parse_pbgpm_header(const int fd, t_texture *tex)
{
	int		maxval;
	char	*line;

	line = NULL;
	check_already_parsed_type(fd, &line);
	if (!line || (ft_scan(2, " *%d  *%d *\n", line,
				&tex->width, &tex->height) != 0))
	{
		free(line);
		return (neg_error(pack_err(MLXW_ID, MLXW_E_PNMPWH), FL, LN, FC));
	}
	free(line);
	line = skip_comment(fd);
	if (!line || (ft_scan(3, " *%d *\n", line, &maxval) != 0))
	{
		free(line);
		return (neg_error(pack_err(MLXW_ID, MLXW_E_PNMPMXV), FL, LN, FC));
	}
	free(line);
	return (has_invalid_fields(tex, &maxval));
}
