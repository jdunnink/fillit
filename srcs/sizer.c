/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sizer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 09:56:43 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/08 11:17:56 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_pos(t_list *curr, uint16_t *map, size_t mapsize, size_t index)
{
	t_tetro *tetro;

	tetro = curr->content;
	if (mapsize > 7)
	{
		if (available_space(map, mapsize) < lst_len(&curr) * 4)
			return (0);
	}
	while (tetro->y <= mapsize - tetro->height)
	{
		tetro->x = 0;
		if (tetro->y == index / mapsize)
			tetro->x = index % mapsize;
		while (tetro->x <= mapsize - tetro->width)
		{
			if (((*(uint64_t *)(map + tetro->y)) &
				(tetro->tetro >> tetro->x)) == 0)
				return (1);
			tetro->x++;
		}
		tetro->y++;
	}
	tetro->x = 0;
	tetro->y = 0;
	return (0);
}

static	int	check_tetro(t_list *curr, uint16_t *map, size_t mapsize)
{
	t_tetro *tetro;
	t_list	*last;
	size_t	index;

	index = 0;
	tetro = curr->content;
	last = tetro->last;
	if (last)
	{
		index = ((t_tetro *)(last->content))->x +
			((t_tetro *)(last->content))->y * mapsize;
		tetro->y = index / mapsize;
	}
	else
		tetro->y = 0;
	return (check_pos(curr, map, mapsize, index));
}

int			solve_it(t_list **tetros, uint16_t *map, size_t mapsize)
{
	t_list *curr;

	if (!*tetros)
		return (1);
	curr = *tetros;
	if (curr == NULL)
		return (1);
	if (mapsize < ((t_tetro *)(curr->content))->width ||
		mapsize < ((t_tetro *)(curr->content))->height)
		return (0);
	if (check_tetro(curr, map, mapsize))
	{
		toggle_tetro(map, curr->content);
		if (solve_it(&curr->next, map, mapsize))
			return (1);
		toggle_tetro(map, curr->content);
	}
	return (0);
}
