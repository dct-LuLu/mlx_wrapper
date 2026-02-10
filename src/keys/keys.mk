# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    keys.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 05:37:37 by jaubry--          #+#    #+#              #
#    Updated: 2026/02/10 08:59:20 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
KEYS_DIR	= $(SRCDIR)/keys

# Source files
KEYS_SRCS	= keys.c \
			  add_key_hook.c \
			  remove_key_hook.c \
			  setup_special_key_events.c

KEYS_SRCS	:= $(addprefix $(KEYS_DIR)/, $(KEYS_SRCS))

SRCS		+= $(KEYS_SRCS)

# VPATH
vpath %.c $(KEYS_DIR)
