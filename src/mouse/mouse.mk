# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mouse.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 02:51:32 by jaubry--          #+#    #+#              #
#    Updated: 2025/10/14 23:48:45 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
MOUSE_DIR	= $(SRCDIR)/mouse

# Source files
MOUSE_SRCS	= mouse.c \
			  mouse_button.c \
			  mouse_movement.c

MOUSE_SRCS	:= $(addprefix $(MOUSE_DIR)/, $(MOUSE_SRCS))

SRCS			+= $(MOUSE_SRCS)

# VPATH
vpath %.c $(MOUSE_DIR)
