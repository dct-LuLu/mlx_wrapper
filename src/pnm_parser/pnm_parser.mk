# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pnm_parser.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 22:14:53 by jaubry--          #+#    #+#              #
#    Updated: 2025/12/20 22:17:18 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
PNM_PARSER_DIR	= $(SRCDIR)/pnm_parser

# Source files
PNM_PARSER_SRCS	= pnm_parser.c pnm_parser_utils.c \
				  parse_pbm.c \
				  parse_pgm.c \
				  parse_ppm.c \
				  parse_pam.c \
				  parse_pbgpm_header.c
SRCS			+= $(addprefix $(PNM_PARSER_DIR)/, $(PNM_PARSER_SRCS))

# VPATH
vpath %.c $(PNM_PARSER_DIR)
