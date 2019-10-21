/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:29:13 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/21 20:43:11 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef enum	e_output_color	t_output_color;
typedef enum	e_err_status	t_err_status;
typedef struct	s_err			t_err;

enum							e_output_color
{
	FG_RED		= 31,
	FG_GREEN	= 32,
	FG_BLUE		= 34,
	FG_DEFAULT	= 39,
	BG_RED		= 41,
	BG_GREEN	= 42,
	BG_BLUE		= 44,
	BG_DEFAULT	= 49,
};

enum							e_err_status
{
	MALLOC_ERR,
	READ_ERR,
	PLAYER_ERR,
	INVALID_MAP,
	ERR_LEN
};

struct							s_err
{
	char						*str;
	int							len;
};

extern t_err					g_errs[ERR_LEN];

void							ft_exit(t_err_status err_status);
//void							set_output_color(t_output_color color);

# endif
