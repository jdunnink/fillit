/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_permutations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:23:13 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/06 10:30:33 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	swap_list(t_list *curr, t_list *new)
{
	t_tetro *tmp;

	tmp = curr->content;
	curr->content = new->content;
	new->content = tmp;
}

static	int		compare_lst(t_list *curr, t_list *comp)
{
	if (((t_tetro *)(curr->content))->tetro ==
((t_tetro*)(comp->content))->tetro)
		return (1);
	return (0);
}

static	int		should_swap(t_list *start, t_list *curr)
{
	t_list *iter;

	iter = start;
	while (iter != curr && iter)
	{
		if (compare_lst(curr, iter))
			return (0);
		iter = iter->next;
	}
	return (1);
}

int				find_perm(t_list *lst, t_list *pos,
uint16_t *map, size_t min)
{
	t_list	*curr;
	int		found;

	found = 0;
	curr = pos;
	if (!pos)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		found = solve_it(&lst, map, min);
	}
	if (found)
		return (1);
	while (curr)
	{
		if (should_swap(pos, curr))
		{
			swap_list(pos, curr);
			found = find_perm(lst, pos->next, map, min);
			if (found)
				return (1);
			swap_list(pos, curr);
		}
		curr = curr->next;
	}
	return (0);
}
