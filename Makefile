# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 10:16:04 by jaubry--          #+#    #+#              #
#    Updated: 2026/09/06 21:44:32 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOTDIR		?= .
include $(ROOTDIR)/mkidir/make_utils.mk

LIBNAME		= libmlx-wrapper

# Directories
CDIR		= mlx_wrapper
SRCDIR		= src
OBJDIR		= .obj
DEPDIR		= .dep

XCERRCALDIR	= $(LIBDIR)/xcerrcal
LIBFTDIR	= $(LIBDIR)/libft
MLXDIR		= $(LIBDIR)/minilibx-linux

# Includes
include $(LIBFTDIR)/includes.mk $(XCERRCALDIR)/includes.mk includes.mk

INCXTEST	= $(MLXDIR)/local_xtst/include/X11/extensions

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
DEBUG_MLXW	= 2

ifeq ($(filter $(DEBUG_LVL),1 $(DEBUG_MLXW)),)
DEBUG		= 0
else
DEBUG		= 1
endif

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

VARS		= DEBUG_LVL=$(DEBUG_LVL) \
			  WIDTH=$(WIDTH) \
			  HEIGHT=$(HEIGHT) \
			  MAX_WIDTH=$(MAX_WIDTH) \
			  MAX_HEIGHT=$(MAX_HEIGHT) \
			  PERF=$(PERF) \
			  FULLSCREEN=$(FULLSCREEN) \
			  RESIZEABLE=$(RESIZEABLE) \
			  WINDOWLESS=$(WINDOWLESS) \
			  XTEST=$(XTEST) \
			  MINIRT_MODE=$(MINIRT_MODE)

# Compiler and flags
CC			?= cc

CFLAGS		= -Wall -Wextra -Werror \
			  -std=gnu11

DFLAGS		= -MMD -MP -MF $(DEPDIR)/$*.d

IFLAGS		= $(addprefix -I,$(INCLUDES) $(INCXTEST))

VFLAGS		= $(addprefix -D ,$(VARS) DEBUG=$(DEBUG))

CFLAGS		+= $(SANITIZE_FLAGS) $(INSPECT_FLAGS) $(PROFILE_FLAGS) $(FFLAGS) $(VFLAGS)

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

include $(ROOTDIR)/mkidir/make_rules.mk

$(NAME): $(XCERRCAL) $(MLX) $(LIBFT) $(OBJS) $(INCLUDES)
	@$(call ar-msg)
ifeq ($(VERBOSE),1)
	$(AR) $(ARFLAGS) $@ $(OBJS)
else
	@$(AR) $(ARFLAGS) $@ $(OBJS)
endif
ifeq ($(FAST),1)
ifeq ($(VERBOSE),1)
	$(RANLIB) $@
else
	@$(RANLIB) $@
endif
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
