/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:53:20 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/21 20:53:52 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAT_MAP_H
# define HEAT_MAP_H

# include "filler.h"

typedef struct	s_hm_queue	t_hm_queue;
typedef struct	s_hm_qelem	t_hm_qelem;

struct						s_hm_queue
{
	t_hm_qelem				*start;
	t_hm_qelem				*end;
};

struct						s_hm_qelem
{
	t_point					p;
	int						heat;
	t_hm_qelem				*next;
};

void						fill_heat_map(t_board *board);

#endif
