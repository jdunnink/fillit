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

#include <stdio.h>
#include <stdlib.h>

size_t	conv_2d_index_to_1d(int row, int column, size_t size)
{
	size_t index;

	index = row * size + column;
	return (index);
}

void	conv_1d_index_to_2d(int *x, int *y, size_t index, size_t size)
{
	*x = index / size;
	*y = index % size;
}

void        to_bits(char *s, unsigned short *dst, int iter)
{
    int i;
    unsigned short res;
    int len;

    len = strlen(s);
    i = 0;
    res = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '#')
        {
            res |= 1 << (len - (i + 1));
        }
        i++;
    }
	*dst |= res << (len * (len - 1) - (len * iter));
}

void		get_masks(unsigned short *top_row, unsigned short *left_col, size_t size, size_t row_size)
{
	int i;

	i = 1;
	while (i <= row_size)
	{
		*top_row |= 1 << size - i;
		i++;
	}
	i = 1;
	while (i <= size)
	{
		if (i % row_size == 0)
			*left_col |= 1 << i;
		i++;
	}
}

void		tetro_translate(unsigned short *dest, size_t size, size_t row_size)
{
	unsigned short top_row;
	unsigned short left_col;

	get_masks(&top_row, &left_col, size, row_size);
	while (~(top_row ^ *dest) == 0)
		*dest << row_size;
	while (~(left_col ^ *dest) == 0)
		*dest << 1;
}