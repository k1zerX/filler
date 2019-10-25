/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:50:07 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/25 22:11:41 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heat_map.h"
#include <stdlib.h>
#include "tools.h"

t_hm_qelem	*hm_queue_pop(t_hm_queue *q)
{
	t_hm_qelem	*tmp;

	tmp = q->start;
	if (tmp)
	{
		q->start = tmp->next;
		if (q->start == NULL)
			q->end = NULL;
	}
	return (tmp);
}

void		hm_queue_push(t_hm_queue *q, t_point p, int heat)
{
	t_hm_qelem	*tmp;

	if (!(tmp = malloc(sizeof(t_hm_qelem))))
		ft_exit();
	tmp->next = NULL;
	tmp->p = p;
	tmp->heat = heat;
	if (q->end)
		q->end->next = tmp;
	else
		q->start = tmp;
	q->end = tmp;
}
