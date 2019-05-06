/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_ones.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 18:18:00 by lravier       #+#    #+#                 */
/*   Updated: 2019/05/03 18:18:44 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_ones(uint16_t *tetro)
{
	uint16_t	tmp;
	int			count;

	count = 0;
	tmp = *tetro;
	while (tmp)
	{
		count += tmp & 1;
		tmp >>= 1U;
	}
	return (count);
}
