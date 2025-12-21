/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_img_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:58 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/21 01:47:53 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_mlx_img_put(t_img_data *mlx_img, const t_vec2i pos, t_img_data *img)
{
	t_vec2i		cur_pos;
	t_rgb_int	color;
	ssize_t		x;
	ssize_t		y;
	size_t		offset;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			cur_pos = vec2i(pos.x + x, pos.y + y);
			offset = y * img->line_len + x * img->channels;
			color.r = img->pixels[offset];
			color.g = img->pixels[offset + 1];
			color.b = img->pixels[offset + 2];
			ft_mlx_pixel_put(mlx_img, cur_pos, color);
			x++;
		}
		y++;
	}
}

void	ft_mlx_img_aput(t_img_data *mlx_img, const t_vec2i pos, t_img_data *img)
{
	t_vec2i		cur_pos;
	t_rgba_int	color;
	ssize_t		x;
	ssize_t		y;
	size_t		offset;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			cur_pos = vec2i(pos.x + x, pos.y + y);
			offset = y * img->line_len + x * img->channels;
			color.r = img->pixels[offset];
			color.g = img->pixels[offset + 1];
			color.b = img->pixels[offset + 2];
			color.a = img->pixels[offset + 3];
			ft_mlx_pixel_aput(mlx_img, cur_pos, color);
			x++;
		}
		y++;
	}
}

void	ft_mlx_safe_img_put(t_img_data *mlx_img, const t_vec2i pos,
		t_img_data *img)
{
	t_vec2i		cur_pos;
	t_rgb_int	color;
	ssize_t		x;
	ssize_t		y;
	size_t		offset;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			cur_pos = vec2i(pos.x + x, pos.y + y);
			offset = y * img->line_len + x * img->channels;
			color.r = img->pixels[offset];
			color.g = img->pixels[offset + 1];
			color.b = img->pixels[offset + 2];
			ft_mlx_safe_pixel_put(mlx_img, cur_pos, color);
			x++;
		}
		y++;
	}
}

void	ft_mlx_safe_img_aput(t_img_data *mlx_img, const t_vec2i pos,
		t_img_data *img)
{
	t_vec2i		cur_pos;
	t_rgba_int	color;
	ssize_t		x;
	ssize_t		y;
	size_t		offset;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			cur_pos = vec2i(pos.x + x, pos.y + y);
			offset = y * img->line_len + x * img->channels;
			color.r = img->pixels[offset];
			color.g = img->pixels[offset + 1];
			color.b = img->pixels[offset + 2];
			color.a = img->pixels[offset + 3];
			ft_mlx_safe_pixel_aput(mlx_img, cur_pos, color);
			x++;
		}
		y++;
	}
}
