/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_tetro.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:44:09 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/06 13:46:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	find_first(uint16_t tetro)
{
	uint16_t	mask;
	size_t		i;

	i = 0;
	mask = 1U;
	while ((mask & tetro) == 0)
	{
		mask = (mask << 1U);
		i++;
	}
	return (i);
}

static int		tetro_wh(t_tetro *t, uint16_t msk, uint16_t *visit, size_t i)
{
	uint16_t	prev_visited;
	size_t		total_size;

	prev_visited = 0;
	total_size = 0;
	total_size = SIZE * SIZE;
	if ((msk & t->fpt) != 0 && (*visit & msk) == 0)
	{
		prev_visited = *visit;
		*visit |= msk;
		if (count_ones(visit) == 4 && (prev_visited ^ *visit) == 0)
			return (0);
		if (i < total_size - SIZE && (*visit & (msk << SIZE)) == 0)
			t->height += tetro_wh(t, msk << SIZE, visit, i + SIZE);
		if (i >= SIZE && (*visit & (msk >> SIZE)) == 0)
			t->height += tetro_wh(t, msk >> SIZE, visit, i - SIZE);
		if (i % SIZE != 0 && (*visit & (msk >> 1)) == 0)
			t->width += tetro_wh(t, msk >> 1, visit, i - 1);
		if ((i + 1) % SIZE != 0 && (*visit & (msk << 1)) == 0)
			t->width += tetro_wh(t, msk << 1, visit, i + 1);
		return (1);
	}
	return (0);
}

static	void	find_last(t_list **lst, t_tetro *t)
{
	t_list *tmp;
	t_list *last;

	last = NULL;
	tmp = *lst;
	while (tmp)
	{
		if (((t_tetro *)(tmp->content))->fpt == t->fpt)
		{
			last = tmp;
			t->last = last;
		}
		tmp = tmp->next;
	}
}

static t_tetro	set_attributes(uint16_t tetr, size_t count)
{
	t_tetro t;

	t.fpt = tetr;
	t.tetro = convert_sll(tetr);
	t.print = 'A' + (count - 1);
	t.order = count;
	t.last = NULL;
	t.x = 0;
	t.y = 0;
	t.width = 1;
	t.height = 1;
	return (t);
}

int				add_tetro(uint16_t tetr, size_t count, t_list **lst)
{
	t_tetro		t;
	size_t		index;
	uint16_t	mask;
	uint16_t	visited;

	visited = 0;
	mask = 0;
	index = 0;
	t = set_attributes(tetr, count);
	index = find_first(tetr);
	mask = (1U << index);
	visited = 0UL;
	if (t.fpt == 52224)
	{
		t.width = 2;
		t.height = 2;
	}
	else
		tetro_wh(&t, mask, &visited, index);
	find_last(lst, &t);
	if (!(ft_lstaddend(lst, &t, sizeof(t_tetro))))
		return (0);
	return (1);
}
