/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:12:42 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/25 22:45:43 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"
#include "libft.h"
#include "tools.h"

int		cool_atoi(char **str)
{
	int		n;

	if (**str == '-')
	{
		++(*str);
		n = 0;
		while (ft_isdigit(**str))
			n = n * 10 - (*(*str)++ - '0');
	}
	else
	{
		if (**str == '+')
			++(*str);
		n = 0;
		while (ft_isdigit(**str))
			n = n * 10 + (*(*str)++ - '0');
	}
	return (n);
}

void	get_size(int *n, int *m, char *str)
{
	while (ft_isalpha(*str))
		++str;
	while (ft_isspace(*str))
		++str;
	*n = cool_atoi(&str);
	while (ft_isspace(*str))
		++str;
	*m = cool_atoi(&str);
}

char	is_valid(char c)
{
	int		i;

	if (c == EMPTY)
		return (1);
	i = 0;
	while (i < P_LEN)
	{
		if (c == g_ps[i].new || c == g_ps[i].old)
			return (1);
		++i;
	}
	return (0);
}

void	read_cycle(t_board *board, t_p_nbr p)
{
	char	*str;
	int		i;

	i = 0;
	while (i < board->n)
	{
		if (gnl(0, &str) > 0)
		{
			get_board_str(board->map + i * board->m, str, board->m, p);
			free(str);
		}
		else
			ft_exit();
		++i;
	}
}
