# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 10:16:04 by jaubry--          #+#    #+#              #
#    Updated: 2026/01/04 21:56:23 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOTDIR		?= .
include $(ROOTDIR)/mkidir/make_utils.mk

LIBNAME		= libmlx-wrapper

# Directories
CDIR		= mlx_wrapper
SRCDIR		= src
INCDIR		= include
OBJDIR		= .obj
DEPDIR		= .dep

XCERRCALDIR	= $(LIBDIR)/xcerrcal
LIBFTDIR	= $(LIBDIR)/libft
MLXDIR		= $(LIBDIR)/minilibx-linux

# Includes
include $(LIBFTDIR)/includes.mk $(XCERRCALDIR)/includes.mk includes.mk

INCLUDES	= $(INCDIRS_MLXW) \
			  $(addprefix $(XCERRCALDIR)/, $(INCDIRS_XCERRCAL)) \
			  $(addprefix $(LIBFTDIR)/, $(INCDIRS_LIBFT)) \
			  $(MLXDIR)

# Output
NAME		= $(LIBNAME).a
XCERRCAL	= $(XCERRCALDIR)/libxcerrcal.a
LIBFT		= $(LIBFTDIR)/libft.a
MLX			= $(MLXDIR)/libmlx.a

# Variables
WINDOWLESS	= 0
FULLSCREEN	= 0
RESIZEABLE	= 0

ifeq ($(FULLSCREEN), 1)
WIDTH		= $(MAX_WIDTH)
HEIGHT		= $(MAX_HEIGHT)
else
WIDTH		= 500
HEIGHT		= 500
endif

PERF		= 0

VARS		= DEBUG=$(DEBUG) \
			  WIDTH=$(WIDTH) \
			  HEIGHT=$(HEIGHT) \
			  PERF=$(PERF) \
			  FULLSCREEN=$(FULLSCREEN) \
			  RESIZEABLE=$(RESIZEABLE) \
			  WINDOWLESS=$(WINDOWLESS)

# Compiler and flags
CC			= cc

CFLAGS		= -Wall -Wextra -Werror \
			  -std=gnu11

DFLAGS		= -MMD -MP -MF $(DEPDIR)/$*.d

IFLAGS		= $(addprefix -I,$(INCLUDES))

VFLAGS		= $(addprefix -D ,$(VARS))

CFLAGS		+= $(DEBUG_FLAGS) $(FFLAGS) $(VFLAGS)
CF			= $(CC) $(CFLAGS) $(IFLAGS)

AR          = $(if $(findstring -flto,$(FFLAGS)),$(FAST_AR),$(STD_AR))
ARFLAGS		= rcs
RANLIB      = $(if $(findstring -flto,$(FFLAGS)),$(FAST_RANLIB),$(STD_RANLIB))

# VPATH
vpath %.h $(INCLUDES)
vpath %.o $(OBJDIR) $(LIBFTDIR)/$(OBJDIR)
vpath %.d $(DEPDIR) $(LIBFTDIR)/$(DEPDIR)

# Sources
include $(SRCDIR)/srcs.mk

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

$(NAME): $(XCERRCAL) $(MLX) $(LIBFT) $(OBJS)
	@$(call ar-msg)
	@$(AR) $(ARFLAGS) $@ $^
ifeq ($(FAST),1)
	@$(RANLIB) $@ $(SILENCE)
endif
	$(call ar-finish-msg)

$(XCERRCAL):
	@$(MAKE) -s -C $(XCERRCALDIR) $(RULE) $(VARS) ROOTDIR=../..

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

re: fclean all

-include $(DEPS)

.PHONY: all debug re clean fclean help buildmsg print-%
