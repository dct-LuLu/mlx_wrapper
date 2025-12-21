# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 20:31:56 by jaubry--          #+#    #+#              #
#    Updated: 2025/12/20 22:17:36 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKS			= draw/draw.mk \
			  primitives/primitives.mk \
			  keys/keys.mk \
			  mouse/mouse.mk \
			  pnm_parser/pnm_parser.mk

include $(addprefix $(SRCDIR)/, $(MKS))

SRCS		+= register_mlxw_errors.c

vpath %.c $(SRCDIR)
