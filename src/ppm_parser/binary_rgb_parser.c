/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_rgb_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <pabellis@student.forty2.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:43:53 by pabellis          #+#    #+#             */
/*   Updated: 2025/12/09 16:13:36 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int			check_header(int fd, int *width, int *height, int *bit);
static int	get_rgb_data(int fd, t_texture *tex);

t_texture	*ppm_parser(const int fd, t_texture *tex)
{
	if (check_header(fd, &tex->width, &tex->height, &tex->tex_bpp) == -1)
		return (NULL);
	if (get_rgb_data(fd, tex) == -1)
		return (NULL);
	return (tex);
}

static int	get_rgb_data(const int fd, t_texture *tex)
{
	ssize_t	ret_val;
	ssize_t	size;

	size = (ssize_t) tex->width * (size_t) tex->height * 3;
	tex->line_len = tex->width * 3;
	tex->tex_bpp = 24;
	tex->addr = malloc(size);
	if (!tex->addr)
		return (-1);
	ret_val = read(fd, tex->addr, size);
	if (ret_val != size)
	{
		free(tex->addr);
		tex->addr = NULL;
		return (-1);
	}
	return (0);
}
