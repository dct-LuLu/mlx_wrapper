/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:04:54 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/20 00:29:27 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

typedef enum e_pnm_type
{
	PBM_TYPE,
	PGM_TYPE,
	PPM_TYPE,
	PAM_TYPE
}	t_pnm_type;

/*
	Invalid PNM header
		P0 to P3 -> invalid format can only parse raw binary data, not ASCII decimal data
		
*/

static int	parse_pam_header(const int fd, int *width, int *height, int *bit)
{

}

static int	parse_pbgpm_header(const int fd, int *width, int *height, int *bit)
{
		line = skip_comment(fd);
		if (!line || ft_scan(2, " *%d  *%d *\n", line, width, height) != 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = skip_comment(fd);
		if (!line || ft_scan(3, " *%d *\n", line, bit) != 0)
		{
			free(line);
			return (-1);
		}
		free(line);
}

static int	parse_pnm_header(const int fd, int *width, int *height, int *bit)
{
	t_pnm_type	pnm_type;
	char		*line;

	line = skip_comment(fd);
	if (!line)
		pnm_type = ft_strncmp(line, "P4", 2);
	free(line);
	if (pnm_type == PAM_TYPE)
		parse_pam_header(fd, width, height, bit);
	else if ((pnm_type == PBM_TYPE) || (pnm_type == PGM_TYPE) || (pnm_type == PPM_TYPE))
		parse_pbgm_header(fd, width, height, bit);
	return (0);
}

t_texture	*pnm_parser(const int fd, t_texture *tex)
{
}
