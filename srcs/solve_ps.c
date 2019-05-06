/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_ps.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 13:48:05 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/06 12:05:54 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		check_fit(uint16_t *map, t_tetro *tetro)
{
	if ((*(uint64_t *)(map + tetro->y) & (tetro->tetro >> tetro->x)) == 0)
		return (1);
	return (0);
}

static	int		same_rest(t_list *curr, t_list *rest)
{
	t_list	*r;
	t_tetro *rc;
	t_tetro *ch;

	r = rest;
	ch = curr->content;
	if (!r)
		return (0);
	while (r)
	{
		rc = r->content;
		if (ch->fpt != rc->fpt)
			return (0);
		r = r->next;
	}
	ch->x = 0;
	ch->y = 0;
	return (1);
}

static int		check_pos(uint16_t *map, size_t size, t_list *lst, size_t index)
{
	t_tetro *tro;

	tro = (t_tetro *)lst->content;
	while (tro->y <= size - tro->height)
	{
		tro->x = 0;
		tro->y == index / size ? (tro->x = index % size) : 0;
		while (tro->x <= size - tro->width)
		{
			if (check_fit(map, tro))
			{
				toggle_tetro(map, tro);
				if (solve_map(map, &lst->next, size))
					return (1);
				toggle_tetro(map, tro);
				if (same_rest(lst, lst->next))
					return (0);
			}
			tro->x++;
		}
		tro->y++;
	}
	tro->x = 0;
	tro->y = 0;
	return (0);
}

int				solve_ps(t_list *lst, size_t size, uint16_t *mp, size_t i)
{
	if (size > 10)
	{
		if (available_space(mp, size) < (lst_len(&lst) * 4))
			return (0);
	}
	if (check_pos(mp, size, lst, i) == 1)
		return (1);
	return (0);
}
