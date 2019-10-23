/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:29:10 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/21 20:39:25 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define EMPTY			'.'
# define FULL			'*'
# define MY				-1
# define OP				-2
# define UNREACHABLE	-3

typedef struct	s_board	t_board;
typedef struct	s_piece	t_piece;
typedef enum	e_p_nbr	t_p_nbr;
typedef struct	s_p		t_p;
typedef struct	s_point	t_point;

struct					s_board
{
	char				*map;
	int					*heat_map;
	int					n;
	int					m;
};

struct					s_piece
{
	char				*map;
	int					n;
	int					m;
};

struct					s_point
{
	int					y;
	int					x;
};

enum					e_p_nbr
{
	P1,
	P2,
	P_LEN
};

struct					s_p
{
	char				new;
	char				old;
};

extern t_p				g_ps[P_LEN];

#endif
