/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:29:12 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/25 22:46:21 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

# include "filler.h"

void	ft_read(t_board *board, t_piece *piece);
void	read_cycle(t_board *board, t_p_nbr p);
int		cool_atoi(char **str);
void	get_size(int *n, int *m, char *str);
char	is_valid(char c);
void	get_board_str(char *map, char *str, int len, t_p_nbr p);

#endif
