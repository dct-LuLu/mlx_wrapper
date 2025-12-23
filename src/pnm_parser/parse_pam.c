/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:20:55 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 20:44:12 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

bool	has_invalid_fields(t_texture *tex, int *maxval);
int		read_binary_data(const int fd, t_texture *tex);
void	check_already_parsed_type(const int fd, char **line);
char	*read_by_char(const int fd);

#define KEYS_NUM 5

#define FMT_WIDTH " *WIDTH *%d *\n"
#define FMT_HEIGHT " *HEIGHT *%d *\n"
#define FMT_DEPTH " *DEPTH *%d *\n"
#define FMT_MAXVAL " *MAXVAL *%d *\n"

static inline int	read_key(char *line, size_t line_num,
						t_texture *tex, int *maxval)
{
	static const char	*keys[KEYS_NUM] = {"WIDTH", "HEIGHT", "DEPTH",
		"MAXVAL", "ENDHDR"};
	static const char	*scans[KEYS_NUM - 1] = {FMT_WIDTH, FMT_HEIGHT,
		FMT_DEPTH, FMT_MAXVAL};
	int *const			vals[KEYS_NUM - 1] = {(int *)&tex->width,
		(int *)&tex->height, (int *)&tex->channels, maxval};
	size_t				i;

	i = 0;
	while (i < KEYS_NUM)
	{
		if (ft_strncmp(line, keys[i], ft_strlen(keys[i])) == 0)
		{
			if (i == (KEYS_NUM - 1))
				return (1);
			else if (ft_scan(line_num, scans[i], line, vals[i]) != 0)
				return (-1);
		}
		i++;
	}
	return (0);
}

static inline int	parse_pam_header(const int fd, t_texture *tex)
{
	size_t	line_num;
	char	*line;
	int		ret;
	int		maxval;

	line = NULL;
	check_already_parsed_type(fd, &line);
	line_num = 2;
	while (true)
	{
		if (!line)
			return (-1);
		ret = read_key(line, line_num, tex, &maxval);
		if (ret == 1)
			break ;
		free(line);
		if (ret == -1)
			return (-1);
		line = read_by_char(fd);
		line_num++;
	}
	free(line);
	return (has_invalid_fields(tex, &maxval));
}

t_texture	*parse_pam(const int fd, t_texture *tex)
{
	if (parse_pam_header(fd, tex) != 0)
		return (NULL);// error while parsing %s header values
	tex->line_len = tex->width * tex->channels;
	if (read_binary_data(fd, tex) == -1)
		return (NULL);
	return (tex);
}
