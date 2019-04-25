/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 13:29:05 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/22 13:31:08 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int is_one(size_t index, unsigned long long test)
{
    unsigned long long mask;

    mask = (1ULL << 63);
    mask >>= index;
    if (mask & test)
        return (1);
    return (0); 
}

size_t	coortoi(int row, int column, size_t size)
{
	size_t index;

	index = row * size + column;
	return (index);
}

void	itocoor(int *x, int *y, size_t index, size_t size)
{
	*x = index % size;
	*y = index / size;
}

size_t min_mapsize(size_t count)
{
    size_t i;

    count *= 4;
    i = 0;
    while (i * i < count)
        i++;
    return (i);
}

void    print_tetro( unsigned short *dest, size_t size)
{
    unsigned short tmp;
    size_t width;

    width = ft_sqrt(size);
    tmp = *dest;
    while (size)
    {
        tmp = tmp >> (size - 1);
        if (tmp & 1)
            ft_putchar('#');
        else
            ft_putchar('.');
        size--;
        tmp = *dest;
        if (size % width == 0)
            ft_putchar('\n');
    }
}
