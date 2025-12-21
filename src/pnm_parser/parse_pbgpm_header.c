/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pbgpm_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:18:49 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/21 01:06:30 by jaubry--         ###   ########.fr       */
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
	if (!line || (ft_scan(2, " *%d  *%d *\n", line, &tex->width, &tex->height) != 0))
	{
		// unable to parse width and height
		free(line);
		return (-1);
	}
	free(line);
	line = skip_comment(fd);
	if (!line || (ft_scan(3, " *%d *\n", line, &maxval) != 0))
	{
		// unable to parse bit depth
		free(line);
		return (-1);
	}
	free(line);
	return (has_invalid_fields(tex, &maxval));
}
