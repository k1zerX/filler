/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:14:10 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/21 21:41:14 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"
#include "filler.h"
#include "tools.h"
#include "gvars.h"
#include "heat_map.h"

#include <stdio.h>
#include <unistd.h>
#define LEN 3
void	print_map(char *map, int n, int m)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			printf("%*d", LEN, *map);
			++map;
			++j;
		}
		printf("\n");
		++i;
	}
}
void	print_heat_map(int *map, int n, int m)
{
	int		i;
	int		j;

	j = 0;
	while (j < LEN)
	{
		printf(" ");
		++j;
	}
	printf(" |");
	j = 0;
	while (j < m)
	{
		printf("%*d", LEN, j);
		++j;
	}
	printf("\n");
	j = 0;
	while (j < LEN)
	{
		printf("-");
		++j;
	}
	printf("-+");
	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < LEN)
		{
			printf("-");
			++j;
		}
	++i;
	}
	printf("--\n");
	i = 0;
	while (i < n)
	{
		printf("%*d |", LEN, i);
		j = 0;
		while (j < m)
		{
			if (*map == UNREACHABLE)
				printf("%*s", LEN, "UN");
			else if (*map == MY)
				printf("%*s", LEN, "MY");
			else if (*map == OP)
				printf("%*s", LEN, "OP");
			else
				printf("%*d", LEN, *map);
			++map;
			++j;
		}
		printf("\n");
		++i;
	}
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
	i = 0;
	while (i < piece->n)
	{
		j = 0;
		while (j < piece->m)
		{
			if (piece->map[i * piece->m + j])
			{
				c = board->heat_map[(y + i) * board->m + (x + j)];
//				printf("\t%d ---- %d\n", c, i * piece->m + j);
				if (c == UNREACHABLE || c == OP)
					return (-1);
				if (c == MY)
				{
					if (f)
						return (-1);
					f = 1;
				}
				else
					res += c;
			}
			++j;
		}
		++i;
	}
//	printf("%d %d --- %d\n", y, x, res);
	if (f)
		return (res);
	return (-1);
}

t_point	put_piece(t_board *board, t_piece *piece, char *f)
{
	int			i;
	int			j;
	const int	y = board->n - piece->n;
	const int	x = board->m - piece->m;
	int			min;
	int			buf;
	t_point		p;

	*f = 1;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((buf = try_piece(board, piece, i, j)) >= 0)
			{
				min = buf;
				p = (t_point){i, j};
				*f = 0;
				break ;
			}
			++j;
		}
		if (*f == 0)
			break ;
		++i;
	}
	if (*f)
	{
		// TRY TO PUT TO UNREACHABLE
		return ((t_point){0, 0});
	}
	while (++j < x)
		if ((buf = try_piece(board, piece, i, j)) < min && buf >= 0)
		{
			min = buf;
			p = (t_point){i, j};
		}
	while (++i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((buf = try_piece(board, piece, i, j)) < min && buf >= 0)
			{
				min = buf;
				p = (t_point){i, j};
			}
			++j;
		}
	}
	return (p);
}

void	test_zero(int n, int m, int visited[n][m])
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			visited[i][j] = 0;
			++j;
		}
		++i;
	}
}

void	test_print(int n, int m, int visited[n][m])
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			printf("%*d", 6, visited[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

int		main(void)
{
	t_board	board;
	t_piece	piece;
	char	f;
	t_point	p;

	ft_read(&board, &piece);
/*	write(1, "board:\n", 7);
	print_map(board);
	write(1, "piece:\n", 7);
	print_map(piece);
	write(1, "0 0\n", 4);*/
	fill_heat_map(&board);
	print_map(board.map, board.n, board.m);
	write(1, "\n", 1);
	print_map(piece.map, piece.n, piece.m);
	write(1, "\n", 1);
	print_heat_map(board.heat_map, board.n, board.m);
	p = put_piece(&board, &piece, &f);
	if (f)
	{
		printf("CAN'T PUT PIECE ON BOARD\n");
	}
	else
	{
		printf("%d %d\n", p.y, p.x);
	}
	return (0);
}
