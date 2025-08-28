# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    primitives.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 12:21:12 by jaubry--          #+#    #+#              #
#    Updated: 2025/08/21 19:07:06 by jaubry--         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Directories
PRIMITIVES_DIR	= $(SRCDIR)/primitives

# Source files
PRIMITIVES_SRCS	= ft_mlx_init_utils.c \
				  ft_mlx_kill_utils.c \
				  ft_disable_decorations.c \
				  start_mlx_loop.c

PRIMITIVES_SRCS	:= $(addprefix $(PRIMITIVES_DIR)/, $(PRIMITIVES_SRCS))

SRCS			+= $(PRIMITIVES_SRCS)

# VPATH
vpath %.c $(PRIMITIVES_DIR)
