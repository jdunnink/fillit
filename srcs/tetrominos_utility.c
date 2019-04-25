/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetrominos_utility.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 13:18:04 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/22 13:21:54 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	get_mask(unsigned short *top_row, unsigned short *left_col, size_t total_size)
{
	size_t i;

	i = total_size - SIZE;
	while (i < total_size)
	{
		*top_row |=  1 << i;
		i++;
	}
	i = SIZE - 1;
	while (i < total_size)
	{
		*left_col |= 1 << i;
		i += SIZE;
	}
}

void tetro_translate (unsigned short *tetro, size_t total_size)
{
	unsigned short top_row;
	unsigned short left_col;

	top_row = 0;
	left_col = 0;
	get_mask(&top_row, &left_col, total_size);
	while ((*tetro & top_row) == 0)
		*tetro <<= SIZE;
	while ((*tetro & left_col) == 0)
		*tetro <<= 1;
}

void        to_bits(char *s, unsigned short *dst, int iter, char f)
{
    int i;
    unsigned short res;
    int len;

    len = ft_strlen(s);
    i = 0;
    res = 0;
    while (s[i] != '\0')
    {
        if (s[i] == f)
            res |= 1 << (len - (i + 1));
        i++;
    }
	*dst |= res << (len * (len - 1) - (len * iter));
}

size_t	get_row(size_t index, size_t total_new, size_t width_old)
{
	size_t test;
	size_t row = 0;

	test = total_new - width_old;
	while (index <= test)
	{
		test -= width_old;
		row++;
	}
	return (row);
}

unsigned long long	tetro_to_ll(t_tetro *t)
{
	unsigned long long res;
	unsigned long long tmp;
	unsigned long long mask;
	int j;
	size_t i;
	size_t row;

	j = 0;
	row = 1;
	res = 0ULL;
	tmp = (unsigned long long)t->tetro;
	tmp <<= 48ULL;
	i = 1;
	mask = 1ULL;
	while (j < SIZE - 1)
	{
		while ((tmp & mask) == 0)
		{
			mask = (1ULL << i);
			i++;
		}
		row = get_row(i, 64, 4);
		tmp ^= mask;
		mask >>= SIZE * row;
		res |= mask;
		j++;
	}
	res |= tmp;
	return (res);
}
