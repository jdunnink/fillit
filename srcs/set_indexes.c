/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_indexes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 17:39:06 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/30 17:41:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	get_index(size_t *n, unsigned short *t, unsigned short *mask, int *i)
{
	*n = 0U;
	while (*i < 16)
	{
		if (*mask & *t)
		{
			*n = *i;
			*i += 1;
			*mask >>= 1;
			return ;
		}
		*i += 1;
		*mask >>= 1;
	}
}

static	size_t	get_row_l(size_t index)
{
	size_t row;

	if (index < 4)
		row = 0;
	else if (index < 8)
		row = 1;
	else if (index < 12)
		row = 2;
	else
		row = 3;
	return (row);
}

static	void	convert_indexes(t_tetro *t)
{
	size_t row;

	row = get_row_l(t->og_index1);
	if (row != 0)
		t->og_index1 = (16 * row) + (t->og_index1 % 4);
	row = get_row_l(t->og_index2);
	if (row != 0)
		t->og_index2 = (16 * row) + (t->og_index2 % 4);
	row = get_row_l(t->og_index3);
	if (row != 0)
		t->og_index3 = (16 * row) + (t->og_index3 % 4);
	row = get_row_l(t->og_index4);
	if (row != 0)
		t->og_index4 = (16 * row) + (t->og_index4 % 4);
}

void			set_indexes(t_tetro *t)
{
	unsigned short mask;
	int i;

	i = 0;
	mask = 0U;
	mask = (1U << 15);
	get_index(&t->og_index1, &t->tetro, &mask, &i);
	get_index(&t->og_index2, &t->tetro, &mask, &i);
	get_index(&t->og_index3, &t->tetro, &mask, &i);
	get_index(&t->og_index4, &t->tetro, &mask, &i);
	convert_indexes(t);
}
