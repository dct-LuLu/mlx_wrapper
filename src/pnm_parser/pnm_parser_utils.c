/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnm_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:54:08 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/05 12:12:20 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

char	*read_by_char(const int fd)
{
	t_vector	vec;
	char		read_char;

	read_char = 0;
	vector_init(&vec, sizeof(char));
	while (read_char != '\n')
	{
		if (read(fd, &read_char, 1) == -1)
		{
			free_vector(&vec);
			return (nul_error(pack_err(MLXW_ID, MLXW_E_PNMCREAD), FL, LN, FC));
		}
		if (vector_add(&vec, &read_char, 1) == -1)
		{
			free_vector(&vec);
			return (nul_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
		}
	}
	if (vector_add(&vec, "\0", 1) == -1)
	{
		free_vector(&vec);
		return (nul_error(pack_err(LFT_ID, LFT_E_VEC_ADD), FL, LN, FC));
	}
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
		return (neg_error(pack_err(MLXW_ID, MLXW_E_PNMALOC), FL, LN, FC));
	ret_val = read(fd, tex->pixels, size);
	if (ret_val != size)
	{
		free(tex->addr);
		tex->addr = NULL;
		return (neg_error(pack_err(MLXW_ID, MLXW_E_PNMWRT), FL, LN, FC));
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
	{
		register_complex_err_msg(MLXW_E_MSG_PNMRES, tex->width, tex->height);
		ret = true;
	}
	else if (tex->channels <= 0)
	{
		register_complex_err_msg(MLXW_E_MSG_PNMCHN, tex->channels);
		ret = true;
	}
	else if (maxval && (*maxval != 1) && (*maxval != 255))
	{
		register_complex_err_msg(MLXW_E_MSG_PNMMXV, *maxval);
		ret = true;
	}
	return (ret);
}
