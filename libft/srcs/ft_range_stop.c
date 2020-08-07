//
// Created by mendreik on 07.08.20.
//

#include "../includes/tmp.h"

int	ft_range_stop(int count, int stop)
{
	if (count == stop)
		return (1);
	if (count > stop || count < 1)
		return (0);
	return (count + 1);
}