# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    draw.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 12:21:12 by jaubry--          #+#    #+#              #
#    Updated: 2025/08/21 13:40:06 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
DRAW_DIR	= $(SRCDIR)/draw

# Source files
DRAW_SRCS	= ft_mlx_pixel_put.c \
			  ft_mlx_line_put.c \
			  ft_mlx_batch_put.c \
			  ft_mlx_circle_put.c \
			  ft_mlx_draw_quadratic_curve.c

DRAW_SRCS	:= $(addprefix $(DRAW_DIR)/, $(DRAW_SRCS))

SRCS			+= $(DRAW_SRCS)

# VPATH
vpath %.c $(DRAW_DIR)
