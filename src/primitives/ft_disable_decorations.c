/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disable_decorations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:23:20 by jaubry--          #+#    #+#             */
/*   Updated: 2025/08/21 19:06:49 by jaubry--         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_disable_decorations(Display *d, Window w)
{
	struct MotifWmHints	hints;
	Atom				prop;

	hints.flags = CWBackPixel;
	hints.decorations = 0;
	prop = XInternAtom(d, "_MOTIF_WM_HINTS", False);
	XChangeProperty(d, w, prop, prop, 32, PropModeReplace,
		(unsigned char *)&hints, 5);
}