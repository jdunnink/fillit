/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 13:45:45 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/06 10:41:02 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve_map(uint16_t *map, t_list **tetros, size_t map_size)
{
	size_t	index;
	t_list	*curr;
	t_tetro	*tetro;
	t_list	*last;

	curr = *tetros;
	if (!curr)
		return (1);
	tetro = curr->content;
	last = ((t_tetro *)((t_list *)curr)->content)->last;
	index = 0;
	if (map_size < tetro->width || map_size < tetro->height)
		return (0);
	if (last)
	{
		index = ((t_tetro *)(last->content))->x +
				((t_tetro *)(last->content))->y * map_size;
		tetro->y = index / map_size;
	}
	else
		tetro->y = 0;
	return (solve_ps(curr, map_size, map, index));
}
