# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    box.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 10:09:04 by jaubry--          #+#    #+#              #
#    Updated: 2025/10/27 10:10:35 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
BOX_DIR		= $(DRAW_DIR)/box

# Source files
BOX_SRCS	= precompute_box.c \
			  precompute_radius.c \
			  draw_border.c \
			  draw_box.c
BOX_SRCS	:= $(addprefix $(BOX_DIR)/, $(BOX_SRCS))

SRCS		+= $(BOX_SRCS)

# VPATH
vpath %.c $(BOX_DIR)
