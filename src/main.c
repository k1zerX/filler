/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:00:08 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/25 23:17:25 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"
#include "filler.h"
#include "tools.h"
#include "gvars.h"
#include "heat_map.h"
#include "libft.h"

int		try_piece_ifs(int c, int *res, char *f)
{
	if (c == UNREACHABLE || c == OP)
		return (1);
	if (c == MY)
	{
		if (*f)
			return (1);
		*f = 1;
	}
	else
		*res += c;
	return (0);
}

int		try_piece(t_board *board, t_piece *piece, int y, int x)
{
	int			i;
	int			j;
	char		f;
	int			c;
	int			res;

	f = 0;
	res = 0;
	i = -1;
	while (++i < piece->n)
	{
		j = -1;
		while (++j < piece->m)
		{
			if (piece->map[i * piece->m + j])
			{
				c = board->heat_map[(y + i) * board->m + (x + j)];
				if (try_piece_ifs(c, &res, &f))
					return (-1);
			}
		}
	}
	return ((f) ? (res) : (-1));
}

void	put_piece_cycle(t_point p, t_board *board, t_piece *piece, t_sol *sol)
{
	int		buf;

	while (++p.x <= board->m - piece->m)
		if ((buf = try_piece(board, piece, p.y, p.x)) < sol->min && buf >= 0)
			(*sol) = (t_sol){buf, p};
}

t_point	put_piece(t_board *board, t_piece *piece, char *f)
{
	int			i;
	int			j;
	int			buf;
	t_sol		sol;

	*f = 1;
	i = -1;
	while (*f && ++i <= board->n - piece->n)
	{
		j = -1;
		while (++j <= board->m - piece->m)
			if ((buf = try_piece(board, piece, i, j)) >= 0)
			{
				sol = (t_sol){buf, (t_point){i, j}};
				*f = 0;
				break ;
			}
	}
	if (*f)
		return ((t_point){0, 0});
	put_piece_cycle((t_point){i, j}, board, piece, &sol);
	while (++i <= board->n - piece->n)
		put_piece_cycle((t_point){i, -1}, board, piece, &sol);
	return (sol.p);
}

int		main(void)
{
	t_board	board;
	t_piece	piece;
	char	f;
	t_point	p;

	while (1)
	{
		ft_read(&board, &piece);
		fill_heat_map(&board);
		p = put_piece(&board, &piece, &f);
		if (f)
			write(1, "0 0\n", 4);
		else
			ft_print(p);
		free(board.map);
		free(board.heat_map);
		free(piece.map);
	}
	return (0);
}
