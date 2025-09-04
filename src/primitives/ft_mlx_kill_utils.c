/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_kill_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:11:45 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/28 06:30:35 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

/*
	Function that destroys key_events
*/
static void	free_key_events(t_mlx *mlx_data)
{
	if (mlx_data->key_input.key_events)
	{
		free_vector(mlx_data->key_input.key_events);
		free(mlx_data->key_input.key_events);
	}
}

/*
	Function that kills the image
*/
static void	kill_img(t_xvar *mlx, t_img_data *img)
{
	if (img->img)
	{
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
	}
	if (img->addr)
		img->addr = NULL;
	img->byte_depth = 0;
	img->width = 0;
	img->height = 0;
}

/*
	Function that kills the mlx and free everything
*/
void	kill_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (FULLSCREEN)
			mlx_ext_fullscreen(mlx->mlx, mlx->win, 0);
		if (mlx->img.img)
			kill_img(mlx->mlx, &mlx->img);
		if (mlx->win)
		{
			mlx_destroy_window(mlx->mlx, mlx->win);
			mlx->win = NULL;
		}
		if (mlx->mlx)
		{
			mlx_destroy_display(mlx->mlx);
			free(mlx->mlx);
			mlx->mlx = NULL;
		}
		free_key_events(mlx);
		free(mlx);
	}
}
