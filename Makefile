# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 10:16:04 by jaubry--          #+#    #+#              #
#    Updated: 2025/08/20 19:37:06 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOTDIR			?= .
include $(ROOTDIR)/mkidir/make_utils.mk

# Variables
WIDTH			= 500
HEIGHT			= 500

# Directories
CDIR			= mlx_wrapper
SRCDIR			= src
INCDIR			= include
OBJDIR			= .obj
DEPDIR			= .dep

LIBFTDIR		= $(LIBDIR)/libft
MLXDIR			= $(LIBDIR)/minilibx-linux

# Output
NAME			= libmlx-wrapper.a
LIBFT			= $(LIBFTDIR)/libft.a
MLX				= $(MLXDIR)/libmlx.a

# Compiler and flags
CC				= cc

CFLAGS			= -Wall -Wextra -Werror \
				  -std=gnu11

DFLAGS			= -MMD -MP -MF $(DEPDIR)/$*.d

IFLAGS			= -I$(INCDIR) -I$(LIBFTDIR)/include -I$(MLXDIR)

VFLAGS			= -D DEBUG=$(DEBUG) \
				  -D WIDTH=$(WIDTH) \
				  -D HEIGHT=$(HEIGHT)

CLFAGS			+= $(DEBUG_FLAGS) $(FFLAGS) $(VFLAGS)
CF				= $(CC) $(CFLAGS) $(IFLAGS)

AR				= $(if $(findstring -flto,$(CC)),llvm-ar,ar) $(SILENCE)
ARFLAGS			= rcs
RANLIB			= $(if $(findstring -flto,$(CC)),llvm-ranlib,ranlib) $(SILENCE)

# VPATH
vpath %.h $(INCDIR) $(LIBFTDIR)/$(INCDIR) $(MLXDIR)
vpath %.o $(OBJDIR) $(LIBFTDIR)/$(OBJDIR)
vpath %.d $(DEPDIR) $(LIBFTDIR)/$(DEPDIR)

# Sources
MKS				= mlx_wrapper/mlx_wrapper.mk

include $(addprefix $(SRCDIR)/, $(MKS))

OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(DEPDIR)/, $(notdir $(SRCS:.c=.d)))

all:	$(NAME)
fast:	$(NAME)
debug:	$(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(call ar-msg)
	@$(AR) $(ARFLAGS) $@ $^
ifeq ($(FAST),1)
	@$(RANLIB) $@
endif
	$(call ar-finish-msg)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR) $(RULE) $(MAKEFLAGS) ROOTDIR=../..

$(MLX):
	$(call mlx-build-msg)
	@$(MAKE) -s -C $(MLXDIR) CC="gcc-12 $(if $(filter 1,$(FAST)),$(OFLAGS))" $(MUTE)
	$(call mlx-finish-msg)

$(OBJDIR)/%.o: %.c | buildmsg $(OBJDIR) $(DEPDIR)
	$(call lib-compile-obj-msg)
	@$(CF) $(DFLAGS) -c $< -o $@

$(OBJDIR) $(DEPDIR):
	$(call create-dir-msg)
	@mkdir -p $@

buildmsg:
ifneq ($(shell [ -f $(NAME) ] && echo exists),exists)
	$(call lib-build-msg)
endif

help:
	@echo "Available targets:"
	@echo -e "\tall, $(NAME)\t\t: Build the library"
	@echo -e "\tdebug\t\t\t\t: Build the library with debug symbols"
	@echo -e "\tre\t\t\t\t: Rebuild $(NAME)"
	@echo
	@echo -e "\tclean\t\t\t\t: Remove object files"
	@echo -e "\tfclean\t\t\t\t: Remove object files, libraries"
	@echo
	@echo -e "\tprint-%\t\t\t\t: Prints makefile variable content when replacing '%'"

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

clean:
	@$(MAKE) -s -C $(LIBFTDIR) clean ROOTDIR=../..
	$(call rm-obj-msg)
	@rm -rf $(OBJDIR) $(DEPDIR)

fclean:
	$(call mlx-clean-msg)
	@$(MAKE) -s -C $(MLXDIR) clean $(SILENCE)
	@$(MAKE) -s -C $(LIBFTDIR) fclean ROOTDIR=../..
	$(call rm-obj-msg)
	@rm -rf $(OBJDIR) $(DEPDIR)
	$(call rm-lib-msg)
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all debug re clean fclean help buildmsg print-%
