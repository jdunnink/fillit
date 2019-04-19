/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitboards.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 10:35:17 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/18 11:34:27 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// starting mapsize == sqrt(number of tetros * 4)

static int		ft_is_prime(int c)
{
	int i;

	i = 2;
	if (c <= 1)
		return (0);
	while (i <= c / i)
	{
		if (c % i == 0)
			return (0);
		i++;
	}
	return (1);
}

size_t find_mapsize(size_t count)
{
    while (ft_is_prime(ft_sqrt(count * 4)) == 0)
        count--;
    return (count * 4);
}