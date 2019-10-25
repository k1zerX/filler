/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:29:10 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/25 22:53:27 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define EMPTY			'.'
# define FULL			'*'
# define MY				-1
# define OP				-2
# define UNREACHABLE	-3

typedef struct s_board		t_board;
typedef struct s_piece		t_piece;
typedef struct s_p			t_p;
typedef struct s_point		t_point;
typedef struct s_sol		t_sol;
typedef enum e_p_nbr		t_p_nbr;

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

struct					s_sol
{
	int					min;
	t_point				p;
};

enum					e_p_nbr
{
	UNDEFINED = -1,
	P1 = 0,
	P2 = 1,
	P_LEN = 2
};

struct					s_p
{
	char				new;
	char				old;
};

extern t_p				g_ps[P_LEN];

#endif
