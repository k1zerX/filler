#ifndef GVARS_H
# define GVARS_H

# include "tools.h"
# include "filler.h"

t_err	g_errs[ERR_LEN] =
{
	[MALLOC_ERR] =
	{
		"cannot allocate memory\n",
		23
	},
	[READ_ERR] =
	{
		"read error\n",
		11
	}
};

t_p		g_ps[P_LEN] =
{
	[P1] =
	{
		'o',
		'O'
	},
	[P2] =
	{
		'x',
		'X'
	}
};

#endif
