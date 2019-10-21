/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:16:23 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/21 21:43:01 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"
#include "filler.h"
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

void	get_size(t_map *map, char *str)
{
	while (ft_isalpha(*str))
		++str;
	while (ft_isspace(*str))
		++str;
	map->n = cool_atoi(&str);
	while (ft_isspace(*str))
		++str;
	map->m = cool_atoi(&str);
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

char	*get_board_str(char *str, int len)
{
	int		i;
	char	*res;

	if (!(res = malloc(len * sizeof(char *))))
		ft_exit(MALLOC_ERR);
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
			ft_exit(READ_ERR);
		if (*str == EMPTY)
			res[i] = 0;
		else if (*str == g_ps[p].new || *str == g_ps[p].old)
			res[i] = -1;
		else
			res[i] = -2;
		++str;
		++i;
	}
	return (res);
}

char	*get_piece_str(char *str, int len)
{
	int		i;
	char	*res;

	if (!(res = malloc(len * sizeof(char *))))
		ft_exit(MALLOC_ERR);
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
			res[i] = 0;
		else if (*str == FULL)
			res[i] = 1;
		else
			ft_exit(READ_ERR);
		++str;
		++i;
	}
	return (res);
}

void	ft_read_board(t_map *board)
{
	char	*str;
	int		i;

	if (gnl(0, &str) > 0)
	{
		get_size(board, str);
		free(str);
	}
	else
		ft_exit(READ_ERR);
	if (gnl(0, &str) > 0)
		free(str);
	else
		ft_exit(READ_ERR);
	if (!(board->map = malloc(board->n * sizeof(char *))))
		ft_exit(MALLOC_ERR);
	i = 0;
	while (i < board->n)
	{
		if (gnl(0, &str) > 0)
		{
			board->map[i] = get_board_str(str, board->m);
			free(str);
		}
		else
			ft_exit(READ_ERR);
		++i;
	}
}

void	ft_read_piece(t_map *piece)
{
	char	*str;
	int		i;

	if (gnl(0, &str) > 0)
	{
		get_size(piece, str);
		free(str);
	}
	else
		ft_exit(READ_ERR);
	if (!(piece->map = malloc(piece->n * sizeof(char *))))
		ft_exit(MALLOC_ERR);
	i = 0;
	while (i < piece->n)
	{
		if (gnl(0, &str) > 0)
		{
			piece->map[i] = get_piece_str(str, piece->m);
			free(str);
		}
		else
			ft_exit(READ_ERR);
		++i;
	}
}

t_p_nbr	ft_read(t_map *board, t_map *piece)
{
	t_p_nbr	p;
	char	*str;

	p = -1;
	if (gnl(0, &str) > 0)
	{
		if (!ft_strnequ(str, "$$$ exec p", 10))
			ft_exit(READ_ERR);
		if ((p = ft_atoi(str + 10)) >= P_LEN)
			ft_exit(READ_ERR);
		free(str);
	}
	else
		ft_exit(READ_ERR);
	ft_read_board(board);
	ft_read_piece(piece);
	if (gnl(0, &str) > 0)
		ft_exit(READ_ERR);
	return (p);
}
