# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 10:16:04 by jaubry--          #+#    #+#              #
#    Updated: 2025/08/28 07:23:30 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOTDIR		?= .
include $(ROOTDIR)/mkidir/make_utils.mk

# Variables
WINDOWLESS	= 0
FULLSCREEN	= 0
RESIZEABLE	= 0
ifeq ($(FULLSCREEN), 1)
WIDTH		= 1920
HEIGHT		= 1080
else
WIDTH		= 500
HEIGHT		= 500
endif
PERF		= 0

# Directories
CDIR		= mlx_wrapper
SRCDIR		= src
INCDIR		= include
OBJDIR		= .obj
DEPDIR		= .dep

LIBFTDIR	= $(LIBDIR)/libft
MLXDIR		= $(LIBDIR)/minilibx-linux

# Output
NAME		= libmlx-wrapper.a
LIBFT		= $(LIBFTDIR)/libft.a
MLX			= $(MLXDIR)/libmlx.a
ARCHIVES	= $(MLX) $(LIBFT)

# Compiler and flags
CC			= cc

CFLAGS		= -Wall -Wextra -Werror \
			  -std=gnu11

DFLAGS		= -MMD -MP -MF $(DEPDIR)/$*.d

IFLAGS		= -I$(INCDIR) -I$(LIBFTDIR)/include -I$(MLXDIR)

LFLAGS		= -L$(MLXDIR) -L$(LIBFTDIR) \
			  -lmlx -lft \
			  -lXext -lX11 -lXrandr -lm

VARS		= DEBUG=$(DEBUG) \
			  WIDTH=$(WIDTH) \
			  HEIGHT=$(HEIGHT) \
			  PERF=$(PERF) \
			  FULLSCREEN=$(FULLSCREEN) \
			  RESIZEABLE=$(RESIZEABLE) \
			  WINDOWLESS=$(WINDOWLESS)
VFLAGS		= $(addprefix -D ,$(VARS))

CFLAGS		+= $(DEBUG_FLAGS) $(FFLAGS) $(VFLAGS)
CF			= $(CC) $(CFLAGS) $(IFLAGS)

AR          = $(if $(findstring -flto,$(FFLAGS)),$(FAST_AR),$(STD_AR))
ARFLAGS		= rcs
RANLIB      = $(if $(findstring -flto,$(FFLAGS)),$(FAST_RANLIB),$(STD_RANLIB))

# VPATH
vpath %.h $(INCDIR) $(LIBFTDIR)/$(INCDIR) $(MLXDIR)
vpath %.o $(OBJDIR) $(LIBFTDIR)/$(OBJDIR)
vpath %.d $(DEPDIR) $(LIBFTDIR)/$(DEPDIR)

# Sources
MKS			= draw/draw.mk \
			  primitives/primitives.mk \
			  keys/keys.mk

include $(addprefix $(SRCDIR)/, $(MKS))

include $(SRCDIR)/test/test.mk

ifneq (,$(filter 1 1,$(RESIZEABLE) $(FULLSCREEN)))
	SRCS	+= $(MLXDIR)/mlx_ext_randr.c
	CFLAGS	+= -Wno-error=sign-compare -Wno-error=return-type
	vpath %.c $(MLXDIR)
endif

OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(DEPDIR)/, $(notdir $(SRCS:.c=.d)))

all:	$(NAME)
fast:	$(NAME)
debug:	$(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(call ar-msg)
	@$(AR) $(ARFLAGS) $@ $^
ifeq ($(FAST),1)
	@$(RANLIB) $@ $(SILENCE)
endif
	$(call ar-finish-msg)

test: $(NAME)
	$(CF) $(TEST_SRCS) $(ARCHIVES) $(NAME) $(LFLAGS) -o $@


$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR) $(RULE) $(VARS) ROOTDIR=../..

$(MLX):
	$(call mlx-build-msg)
	@$(MAKE) -s -C $(MLXDIR) CC="$(MLX_GCC) $(if $(filter 1,$(FAST)),$(OFLAGS))" $(MUTE)
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
	@rm -f test

re: fclean all

-include $(DEPS)

.PHONY: all debug re clean fclean help buildmsg print-%



