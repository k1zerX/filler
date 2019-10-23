#include "heat_map.h"
#include "filler.h"
#include "tools.h"
#include <stdlib.h>

void	hm_reset(t_board *board)
{
	int		*hm;
	int		i;
	int		j;

	hm = board->heat_map;
	i = 0;
	while (i < board->n)
	{
		j = 0;
		while (j < board->m)
		{
			*hm = UNREACHABLE;
			++hm;
			++j;
		}
		++i;
	}
}

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

void	hm_queue_push(t_hm_queue *q, t_point p, int heat)
{
	t_hm_qelem	*tmp;

	if (!(tmp = malloc(sizeof(t_hm_qelem))))
		ft_exit(MALLOC_ERR);
	tmp->next = NULL;
	tmp->p = p;
	tmp->heat = heat;
	if (q->end)
		q->end->next = tmp;
	else
		q->start = tmp;
	q->end = tmp;
}

char	fill_hm_elem(t_board *board, t_point p, int *heat)
{
	char		c;
	int			*el;
	const int	k = p.y * board->m + p.x;

	if (p.y >= board->n || p.x >= board->m || \
			p.y < 0 || p.x < 0)
		return (0);
	c = board->map[k];
	el = board->heat_map + k;
	if (*el != UNREACHABLE && *heat >= *el)
		return (0);
	if (c == MY)
	{
		*el = MY;
		return (0);
		(*heat)++;
	}
	else if (c == OP)
	{
		*el = OP;
		*heat = 0;
	}
	else
		*el = (*heat)++;
	return (1);
}

void	fill_hm_bfs(t_board *board, int i, int j)
{
	t_hm_queue	q;
	t_hm_qelem	*tmp;
	t_point		p;
	int			heat;


	q = (t_hm_queue){NULL, NULL};
	hm_queue_push(&q, (t_point){i, j}, 0);
//int	visited[board->n][board->m];
//test_zero(board->n, board->m, visited);
//int nbr = 0;//
	while (q.start)
	{
		tmp = hm_queue_pop(&q);
		p = tmp->p;
//visited[p.y][p.x]++;
//(void)nbr;
//printf("%d : ||| (%d, %d) |||\n", ++nbr, p.y, p.x);//
		heat = tmp->heat;
		free(tmp);
		if (fill_hm_elem(board, p, &heat))
		{
			hm_queue_push(&q, (t_point){p.y + 1, p.x}, heat);
			hm_queue_push(&q, (t_point){p.y - 1, p.x}, heat);
			hm_queue_push(&q, (t_point){p.y, p.x + 1}, heat);
			hm_queue_push(&q, (t_point){p.y, p.x - 1}, heat);
		}
//print_heat_map(board->heat_map, board->n, board->m);
//printf("\n");
	}
//printf("---------------------------------\n");
//test_print(board->n, board->m, visited);
//printf("---------------------------------\n");
//printf("\n");
}

void	fill_heat_map(t_board *board)
{
	int		i;
	int		j;
	char	*map;

	hm_reset(board);
	map = board->map;
	i = 0;
	while (i < board->n)
	{
		j = 0;
		while (j < board->m)
		{
//printf("%d == %d -> %d\n", *map, OP, *map == OP);
			if (*map == OP)
			{
				fill_hm_bfs(board, i, j);
				return ;
			}
			++map;
			++j;
		}
		++i;
	}
}
