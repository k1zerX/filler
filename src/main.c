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

#include <unistd.h>
void	print_map(t_map map)
{
	int		i;

	i = 0;
	while (i < map.n)
	{
		write(1, map.map[i], map.m);
		write(1, "\n", 1);
		++i;
	}
}

char	try_piece(t_map *board, t_map *piece, int n, int m)
{
	int			i;
	int			j;
	const int	y = n + piece->n;
	const int	x = m + piece->m;

	i = n;
	while (i < y)
	{
		j = m;
		while (j < x)
		{
			df
			++j;
		}
		++i;
	}
}

void	put_piece(t_map *board, t_map *piece)
{
	int			i;
	int			j;
	const int	y = board->n - piece->n;
	const int	x = board->m - piece->m;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			try_piece(board, piece, i, j);
			++j;
		}
		++i;
	}
}

void	fill_heat_map(t_map *heat_map, t_map board)
{
	char	visited[board->n][board->m];

	s
}

t_map	get_heat_map(t_map board)
{
	t_map	heat_map;
	int		i;
	int		j;

	if (!(heat_map = malloc(board->n * sizeof(char *))))
		ft_exit(MALLOC_ERR);
	i = 0;
	while (i < board->n)
	{
		if (!(heat_map[i] = malloc(board->n * sizeof(char *))))
			ft_exit(MALLOC_ERR);
		++i;
	}
	i = 0;
	while (i < board->n)
	{
		j = 0;
		while (j < board->m)
		{
			fill_heat_map(&heat_map, board, i, j);
			++j;
		}
		++i;
	}
}

int		main(void)
{
	t_map	board;
	t_map	piece;
	t_map	heat_map;

	ft_read(&board, &piece);
/*	write(1, "board:\n", 7);
	print_map(board);
	write(1, "piece:\n", 7);
	print_map(piece);
	write(1, "0 0\n", 4);*/
	heat_map = get_heat_map(board);
	return (0);
}
