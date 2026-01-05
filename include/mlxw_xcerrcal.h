/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_xcerrcal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:02:28 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/05 12:12:08 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_XCERRCAL_H
# define MLXW_XCERRCAL_H

# define MLXW_ID 3

typedef enum e_mlxw_err
{
	MLXW_E_INITF = 1,
	MLXW_E_WSIZE,
	MLXW_E_MLXF,
	MLXW_E_WINF,
	MLXW_E_IMGF,
	MLXW_E_SKEYF,
	MLXW_E_KEYF,
	MLXW_E_WMEVENT,
	MLXW_E_BUTTONHF,
	MLXW_E_MOTIONHF,
	MLXW_E_MOUSEF,
	MLXW_E_EVENTH,
	MLXW_E_PNMCREAD,
	MLXW_E_PNMALOC,
	MLXW_E_PNMWRT,
	MLXW_E_PNMDAT,
	MLXW_E_PNMHEAD,
	MLXW_E_PNMFLN,
	MLXW_E_PNMFFMT,
	MLXW_E_PNMAFMT,
	MLXW_E_PNMUFMT,
	MLXW_E_PNMDFMT,
	MLXW_E_PNMPWH,
	MLXW_E_PNMPMXV,
	MLXW_E_PNMRES,
	MLXW_E_PNMCHN,
	MLXW_E_PNMMXV,
	MLXW_E_PAMAT,
	MLXW_E_PAMHDMS,
	MLXW_E_PAMHEAD,
	MLXW_E_PNM,
	MLXW_E_PBM,
	MLXW_E_PGM,
	MLXW_E_PPM,
	MLXW_E_PAM,
	MLXW_ERRS_NUM
}	t_mlxw_err;

# define MLXW_E_MSG_INITF "Failed to initialize mlx_wrapper correctly"
# define MLXW_E_MSG_WSIZE "Invalid window size, WIDTH/HEIGHT and \
MAX_WIDTH/MAX_HEIGTH must be even"
# define MLXW_E_MSG_MLXF "Minilibx instance initialization failed"
# define MLXW_E_MSG_WINF "Window initialization failed"
# define MLXW_E_MSG_IMGF "Image initialization failed"
# define MLXW_E_MSG_SKEYF "Setup of standard keys and mod keys \
behaviour failed"
# define MLXW_E_MSG_KEYF "Key inputs hook logic initialization failed"
# define MLXW_E_MSG_WMEVENT "Mouse button hook with keycode value 0 \
is forbidden"
# define MLXW_E_MSG_BUTTONHF "Mouse buttons hook logic \
initialization failed"
# define MLXW_E_MSG_MOTIONHF "Mouse motion hook logic \
initialization failed"
# define MLXW_E_MSG_MOUSEF "Mouse inputs hook logic initialization failed"
# define MLXW_E_MSG_EVENTH "Failed to attach new event hook"

# define MLXW_E_MSG_PNMCREAD "Could not read character from file successfully"
# define MLXW_E_MSG_PNMALOC "Could not allocate memory buffer for image data"
# define MLXW_E_MSG_PNMWRT "Could not write image data to memory buffer"
# define MLXW_E_MSG_PNMDAT "Image data loading failed"

# define MLXW_E_MSG_PNMHEAD "Failed to parse PNM image header"
# define MLXW_E_MSG_PNMFLN "Could not read first line without comment in file"
# define MLXW_E_MSG_PNMFFMT "First uncommented line found has unexpected token\
, expected 'P'"
# define MLXW_E_MSG_PNMAFMT "ASCII PNM file format types are not supported"
# define MLXW_E_MSG_PNMUFMT "Unrecognized PNM file format type"
# define MLXW_E_MSG_PNMDFMT "Could not determine PNM file format"
# define MLXW_E_MSG_PNMPWH "Could not parse witdth and height values"
# define MLXW_E_MSG_PNMPMXV "Could not parse maxval value"

# define MLXW_E_MSG_PNMRES "Invalid image resolution (found width=%zd and \
height=%zd)"
# define MLXW_E_MSG_PNMCHN "Invalid image channels number (found %d)"
# define MLXW_E_MSG_PNMMXV "Invalid image maxval number (found %d expected \
1 or 255)"

# define MLXW_E_MSG_PAMAT "Could not parse attribute %s"
# define MLXW_E_MSG_PAMHDMS "Could not parse all mandatory attributes for \
PAM image header"
# define MLXW_E_MSG_PAMHEAD "Failed to parse PAM image header"

# define MLXW_E_MSG_PNM "Parsing PNM file image was unsucessful"
# define MLXW_E_MSG_PBM "Parsing PBM file image was unsucessful"
# define MLXW_E_MSG_PGM "Parsing PGM file image was unsucessful"
# define MLXW_E_MSG_PPM "Parsing PPM file image was unsucessful"
# define MLXW_E_MSG_PAM "Parsing PAM file image was unsucessful"

void	register_mlxw_errors(void);

#endif//MLXW_XCERRCAL_H
