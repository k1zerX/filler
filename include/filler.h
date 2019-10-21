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

# define EMPTY	'.'
# define FULL	'*'

typedef struct	s_map	t_map;
typedef enum	e_p_nbr	t_p_nbr;
typedef struct	s_p		t_p;

struct					s_map
{
	char				**map;
	int					n;
	int					m;
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
