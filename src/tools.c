/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:49:42 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/21 19:09:23 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_exit(t_err_status err_status)
{
	t_err	err;

	err = g_errs[err_status];
	write(2, err.str, err.len);
	exit(1);
}
