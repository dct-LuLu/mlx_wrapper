# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 20:31:56 by jaubry--          #+#    #+#              #
#    Updated: 2025/12/11 11:11:39 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKS			= draw/draw.mk \
			  primitives/primitives.mk \
			  keys/keys.mk \
			  mouse/mouse.mk \
			  ppm_parser/ppm_parser.mk

include $(addprefix $(SRCDIR)/, $(MKS))

SRCS		+= register_mlxw_errors.c

include $(SRCDIR)/test/test.mk

vpath %.c $(SRCDIR)
