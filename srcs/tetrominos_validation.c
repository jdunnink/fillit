/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetrominos_setup.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 13:00:59 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/22 15:11:36 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int count_ones(unsigned short *tetro)
{
    unsigned short tmp;
    int count;

    count = 0;
    tmp = *tetro;
    while (tmp)
    {
        count += tmp & 1;
        tmp >>= 1;
    }
    return (count);
}

int	check_connections(size_t index, size_t total_size, unsigned short *tetro)
{
	size_t i;
	int count;

	count = 0;
	i = index - 1;
	if (!((i + 1) % SIZE == 0))		//left border
	{
		if (*tetro & (1 << (i + 1)))
			count++;
	}
	if (!(i % SIZE == 0))		//right border
	{
		if (*tetro & (1 << (i - 1)))
			count++;
	}
	if (i < total_size - SIZE)		//top border
	{
		if (*tetro & (1 << (SIZE + i)))
			count++;
	}
	if (i >= SIZE)				//bottom_border
	{
		if (*tetro & (1 << (i - SIZE)))
			count++;
	}
	return (count);
}

int		check_edges(unsigned short *tetro, size_t total_size)
{
	unsigned short mask;
	size_t i;
	int edges;

	mask = 1U;
	edges = 0;
	i = 1;
	while (i <= total_size)
	{
		if (mask & *tetro)
			edges += check_connections(i, total_size, tetro);
		mask = (1 << i);
		i++;
	}
	if (edges > 5)
		return (1);
	return (0);
}

int		valid_characters(char *line, char f, char e)
{
	size_t i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != f && line[i] != e)
			return (0);
		i++;
	}
	return (1);
}
