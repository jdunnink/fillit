/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_tetro.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 11:48:13 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 12:57:22 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	check_connections(size_t i, size_t total_size, uint16_t *tetro)
{
	int		count;

	count = 0;
	if (!((i + 1) % SIZE == 0))
	{
		if (*tetro & (1 << (i + 1)))
			count++;
	}
	if (!(i % SIZE == 0))
	{
		if (*tetro & (1 << (i - 1)))
			count++;
	}
	if (i < total_size - SIZE)
	{
		if (*tetro & (1 << (SIZE + i)))
			count++;
	}
	if (i >= SIZE)
	{
		if (*tetro & (1 << (i - SIZE)))
			count++;
	}
	return (count);
}

static	int	check_edges(uint16_t *tetro, size_t total_size)
{
	uint16_t	mask;
	size_t		i;
	int			edges;

	mask = 1U;
	edges = 0;
	i = 1;
	while (i <= total_size)
	{
		if (mask & *tetro)
			edges += check_connections(i - 1, total_size, tetro);
		mask = (1 << i);
		i++;
	}
	if (edges > 5)
		return (1);
	return (0);
}

int			validate_tetro(uint16_t *tetro, size_t total_size)
{
	if (count_ones(tetro) != 4)
		return (ft_error("error"));
	if (!check_edges(tetro, total_size))
		return (ft_error("error"));
	return (1);
}
