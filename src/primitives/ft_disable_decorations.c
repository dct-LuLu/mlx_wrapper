/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disable_decorations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:23:20 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/28 06:29:25 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_disable_decorations(Display *d, Window w)
{
	struct MotifWmHints	hints;
	Atom				prop;

	hints.flags = CWBackPixel;
	hints.decorations = 0;
	prop = XInternAtom(d, "_MOTIF_WM_HINTS", False);
	XChangeProperty(d, w, prop, prop, 32, PropModeReplace,
		(unsigned char *)&hints, 5);
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
		free(mlx);
	}
}
