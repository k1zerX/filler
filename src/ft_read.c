/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:16:23 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/25 22:21:59 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"
#include "filler.h"
#include "libft.h"
#include "tools.h"

void	get_board_str(char *map, char *str, int len, t_p_nbr p)
{
	int		i;

	while (ft_isspace(*str))
		++str;
	while (ft_isdigit(*str))
		++str;
	while (ft_isspace(*str))
		++str;
	i = 0;
	while (i < len)
	{
		if (!is_valid(*str))
			ft_exit();
		if (*str == EMPTY)
			map[i] = 0;
		else if (*str == g_ps[p].new || *str == g_ps[p].old)
			map[i] = MY;
		else
			map[i] = OP;
		++str;
		++i;
	}
}

void	get_piece_str(char *map, char *str, int len)
{
	int		i;

	while (ft_isspace(*str))
		++str;
	while (ft_isdigit(*str))
		++str;
	while (ft_isspace(*str))
		++str;
	i = 0;
	while (i < len)
	{
		if (*str == EMPTY)
			map[i] = 0;
		else if (*str == FULL)
			map[i] = 1;
		else
			ft_exit();
		++str;
		++i;
	}
}

void	ft_read_board(t_board *board, t_p_nbr p)
{
	char	*str;

	if (gnl(0, &str) > 0)
	{
		get_size(&board->n, &board->m, str);
		free(str);
	}
	else
		ft_exit();
	if (gnl(0, &str) > 0)
		free(str);
	else
		ft_exit();
	if (!(board->map = malloc(board->n * board->m * sizeof(char))))
		ft_exit();
	if (!(board->heat_map = malloc(board->n * board->m * sizeof(int))))
		ft_exit();
	read_cycle(board, p);
}

void	ft_read_piece(t_piece *piece)
{
	char	*str;
	int		i;

	if (gnl(0, &str) > 0)
	{
		get_size(&piece->n, &piece->m, str);
		free(str);
	}
	else
		ft_exit();
	if (!(piece->map = malloc(piece->n * piece->m * sizeof(char))))
		ft_exit();
	i = 0;
	while (i < piece->n)
	{
		if (gnl(0, &str) > 0)
		{
			get_piece_str(piece->map + i * piece->m, str, piece->m);
			free(str);
		}
		else
			ft_exit();
		++i;
	}
}

void	ft_read(t_board *board, t_piece *piece)
{
	static t_p_nbr	p = -1;
	char			*str;

	if (p == UNDEFINED)
	{
		if (gnl(0, &str) > 0)
		{
			if (!ft_strnequ(str, "$$$ exec p", 10))
				ft_exit();
			if ((p = ft_atoi(str + 10) - 1) >= P_LEN)
				ft_exit();
			free(str);
		}
		else
			ft_exit();
	}
	ft_read_board(board, p);
	ft_read_piece(piece);
}
