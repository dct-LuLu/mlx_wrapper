/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <pabellis@student.forty2.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:11:10 by pabellis          #+#    #+#             */
/*   Updated: 2025/12/09 16:15:09 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	check_header(int fd, int *width, int *height, int *bit);
int	get_binary_data(int fd, t_texture *tex);

t_texture	*pgm_parser(const int fd, t_texture *tex)
{
	if (check_header(fd, &tex->width, &tex->height, &tex->tex_bpp) == -1)
		return (NULL);
	if (get_binary_data(fd, tex) == -1)
		return (NULL);
	return (tex);
}

int	get_binary_data(int fd, t_texture *tex)
{
	ssize_t	ret_val;
	ssize_t	size;

	size = (ssize_t) tex->width * (size_t) tex->height;
	tex->line_len = tex->width;
	tex->tex_bpp = 8;
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

