/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnm_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:54:08 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 20:45:54 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

char	*read_by_char(const int fd)
{
	t_vector	vec;
	char		read_char;

	vector_init(&vec, sizeof(char));
	if (read(fd, &read_char, 1) == -1)
		return (NULL);
	while (read_char != '\n')
	{
		if (vector_add(&vec, &read_char, 1) == -1)
		{
			free_vector(&vec);
			return (NULL);
		}
		if (read(fd, &read_char, 1) == -1)
		{
			free_vector(&vec);
			return (NULL);
		}
	}
	read_char = 0;
	if (vector_add(&vec, &read_char, 1) == -1)
		free_vector(&vec);
	return (vec.data);
}

char	*skip_comment(const int fd)
{
	char	*line;

	line = read_by_char(fd);
	while (line)
	{
		if (line[0] != '#')
			return (line);
		free(line);
		line = read_by_char(fd);
	}
	return (NULL);
}

int	read_binary_data(const int fd, t_texture *tex)
{
	ssize_t	ret_val;
	ssize_t	size;

	size = tex->width * tex->height * tex->channels;
	tex->pixels = malloc(size);
	if (!tex->pixels)
		return (-1);
	ret_val = read(fd, tex->pixels, size);
	if (ret_val != size)
	{
		free(tex->addr);
		tex->addr = NULL;
		return (-1);
	}
	return (0);
}

void	check_already_parsed_type(const int fd, char **line)
{
	*line = skip_comment(fd);
	if (*line && ((*line)[0] == 'P'))
	{
		free(*line);
		*line = skip_comment(fd);
	}
}

bool	has_invalid_fields(t_texture *tex, int *maxval)
{
	bool	ret;

	ret = false;
	if ((tex->width <= 0) || (tex->height <= 0))
		ret = true;
	else if (tex->channels <= 0)
		ret = true;
	else if (maxval && (*maxval != 1) && (*maxval != 255))
		ret = true;
	return (ret);
}
