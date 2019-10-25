/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:49:42 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/25 23:16:17 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void	ft_exit(void)
{
	exit(1);
}

void	ft_print(t_point p)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(p.y);
	len = ft_strlen(tmp);
	write(1, tmp, len);
	free(tmp);
	write(1, " ", 1);
	tmp = ft_itoa(p.x);
	len = ft_strlen(tmp);
	write(1, tmp, len);
	free(tmp);
	write(1, "\n", 1);
}
