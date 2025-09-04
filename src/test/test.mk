# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 22:11:03 by jaubry--          #+#    #+#              #
#    Updated: 2025/08/27 22:13:15 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
TEST_DIR	= $(SRCDIR)/test

# Source files
TEST_SRCS	= main.c

TEST_SRCS	:= $(addprefix $(TEST_DIR)/, $(TEST_SRCS))

# VPATH
vpath %.c $(TEST_DIR)
