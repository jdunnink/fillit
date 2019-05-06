/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetro_translate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 18:16:26 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 14:39:45 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	get_mask(uint16_t *top, uint16_t *left, size_t size)
{
	size_t i;

	i = size - SIZE;
	while (i < size)
	{
		*top |= 1U << i;
		i++;
	}
	i = SIZE - 1;
	while (i < size)
	{
		*left |= 1U << i;
		i += SIZE;
	}
}

void			tetro_translate(uint16_t *tetro, size_t total_size)
{
	uint16_t top_row;
	uint16_t left_col;

	top_row = 0;
	left_col = 0;
	get_mask(&top_row, &left_col, total_size);
	while ((*tetro & top_row) == 0)
		*tetro <<= SIZE;
	while ((*tetro & left_col) == 0)
		*tetro <<= 1;
}
