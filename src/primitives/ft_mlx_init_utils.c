/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:26:41 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/08 10:14:27 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include "mlx.h"
#include <stdio.h>

/*
	Function to init image with given size, will init it's metadata too.
*/
static inline int	init_img_data(t_img_data *img_data, t_xvar *mlx,
						const int width, const int height)
{
	img_data->img = mlx_new_image(mlx, width, height);
	if (!img_data->img)
		return (-1);
	img_data->addr = (int *)mlx_get_data_addr(img_data->img,
			&img_data->byte_depth, &img_data->line_len, &img_data->endian);
	img_data->byte_depth /= 8;
	img_data->width = width;
	img_data->height = height;
	return (0);
}

static inline void	setup_settings(t_mlx *mlx, const int width, const int height)
{
	mlx->origin = vec2i(0, 0);
	mlx->size = vec2i(width, height);
	mlx->half_size = vec2i(width / 2, height / 2);
	mlx->fullscreen = FULLSCREEN;
	if (WINDOWLESS || FULLSCREEN)
		ft_disable_decorations(mlx->mlx->display, mlx->win->window);
	if (FULLSCREEN)
		mlx_ext_fullscreen(mlx->mlx, mlx->win, 1);
}

static inline bool	valid_win_size(const int width, const int height)
{
	return (((MAX_WIDTH % 2) == 1)
		|| ((MAX_HEIGHT % 2) == 1)
		|| ((width % 2) == 1)
		|| ((height % 2) == 1));
}

int		setup_key_input(t_mlx *mlx_data);
int		setup_mouse_input(t_mlx *mlx_data);

t_mlx	*init_mlx(const int width, const int height, char *title)
{
	t_mlx		*mlx;

	if (!valid_win_size(width, height))
		return (NULL);//err
	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (kill_mlx(mlx), NULL);
	mlx->win = mlx_new_window(mlx->mlx, width, height, title);
	if (!mlx->win)
		return (kill_mlx(mlx), NULL);
	setup_settings(mlx, width, height);
	if (init_img_data(&(mlx->img), mlx->mlx, width, height) != 0)
		return (kill_mlx(mlx), NULL);
	if (setup_key_input(mlx) != 0)
		return (kill_mlx(mlx), NULL);
	if (setup_mouse_input(mlx) != 0)
		return (kill_mlx(mlx), NULL);
	return (mlx);
}
