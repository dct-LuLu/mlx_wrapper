# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mlx_wrapper.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 12:21:12 by jaubry--          #+#    #+#              #
#    Updated: 2025/08/07 08:46:36 by jaubry--         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Directories
MLX_WRAPPER_DIR	= $(SRCDIR)/mlx_wrapper

# Source files
MLX_WRAPPER_SRCS	= ft_mlx_pixel_put.c \
					  ft_mlx_line_put.c \
					  ft_mlx_batch_put.c \
					  ft_mlx_circle_put.c \
					  ft_mlx_draw_quadratic_curve.c \
					  ft_mlx_init_utils.c \
					  ft_mlx_kill_utils.c

MLX_WRAPPER_SRCS	:= $(addprefix $(MLX_WRAPPER_DIR)/, $(MLX_WRAPPER_SRCS))

SRCS			+= $(MLX_WRAPPER_SRCS)

# VPATH
vpath %.c $(MLX_WRAPPER_DIR)
