/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   available_space.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 10:02:47 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/06 10:05:18 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	count_adjacent(uint16_t *map, size_t x, size_t y,
								size_t mapsize)
{
	size_t count;

	count = 0;
	if ((((*(map + y)) & (1 << (15 - x)))) == 0)
	{
		*(map + y) |= (1 << (15 - x));
		if (x > 0)
			count += count_adjacent(map, x - 1, y, mapsize);
		if (x < (mapsize - 1))
			count += count_adjacent(map, x + 1, y, mapsize);
		if (y > 0)
			count += count_adjacent(map, x, y - 1, mapsize);
		if (y < (mapsize - 1))
			count += count_adjacent(map, x, y + 1, mapsize);
		count++;
	}
	return (count);
}

static void		copy_map(uint16_t *map, uint16_t *dst)
{
	int i;

	i = 0;
	while (i < 16)
	{
		dst[i] = map[i];
		i++;
	}
}

size_t			available_space(uint16_t *map, size_t mapsize)
{
	uint16_t	c_map[16];
	size_t		x;
	size_t		y;
	size_t		count;
	size_t		total;

	copy_map(map, c_map);
	total = 0;
	y = 0;
	while (y < mapsize)
	{
		x = 0;
		while (x < mapsize)
		{
			if ((*(c_map + y) & (1 << (15 - x))) == 0)
			{
				count = count_adjacent(c_map, x, y, mapsize);
				if (count > 3)
					total += count;
			}
			x++;
		}
		y++;
	}
	return (total);
}
