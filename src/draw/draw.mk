# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    draw.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 12:21:12 by jaubry--          #+#    #+#              #
#    Updated: 2025/10/30 18:34:46 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
DRAW_DIR	= $(SRCDIR)/draw

# Source files
DRAW_SRCS	= ft_mlx_pixel_put.c \
			  \
			  ft_mlx_line_put.c \
			  ft_mlx_vline_put.c ft_mlx_hline_put.c \
			  \
			  ft_mlx_batch_put.c \
			  ft_mlx_aarec_put.c ft_mlx_out_aarec_put.c \
			  \
			  ft_mlx_circle_put.c ft_mlx_out_circle_put.c \
			  ft_mlx_quad_curve_put.c \
			  \
			  ft_mlx_select_put.c

DRAW_SRCS	:= $(addprefix $(DRAW_DIR)/, $(DRAW_SRCS))

SRCS			+= $(DRAW_SRCS)

# VPATH
vpath %.c $(DRAW_DIR)
