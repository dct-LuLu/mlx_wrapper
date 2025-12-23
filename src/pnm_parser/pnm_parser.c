/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:04:54 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 20:46:48 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

char	*skip_comment(const int fd);

/*
	Invalid PNM header
		P0 to P3 -> invalid format can only parse raw binary data, 
			not ASCII decimal data
		else -> unsopported format or inexistant format specification

		invalid size
		invalid bit
		
*/
static inline int	parse_pnm_type(const int fd)
{
	t_pnm_type	pnm_type;
	char		*line;

	line = skip_comment(fd);
	if (!line)
		return (-1);
	if (line[0] != 'P')
		return (-1);
	pnm_type = ft_strncmp(line, "P4", 2);
	free(line);
	if (pnm_type < 0)
		return (-1);//ascii netbmp format not supported
	else if (pnm_type > PAM_TYPE)
		return (-1);//unrecognize format type
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
		return (NULL);
	if (!tex)
		return (NULL);//error;
	return (tex);
}
