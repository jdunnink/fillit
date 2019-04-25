/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetrominos_setup.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 13:23:50 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/25 20:15:48 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	find_first(t_tetro *t)
{
	unsigned short mask;
	size_t i;

	i = 0;
	mask = 1U;
	while ((mask & t->tetro) == 0)
	{
		mask = mask << 1;
		i++;
	}
	t->og_index1 = i;
}

static int		is_smashboy(unsigned short tetro)
{
	unsigned short mask;
	mask = 52224;
	if ((tetro ^ mask) == 0)
		return (1);
	return (0);
}

int	tetro_wh(t_tetro* t, unsigned short mask, unsigned short *visited, unsigned short tetr, size_t index)
{
	unsigned short prev_visited;
	size_t total_size;
	
	total_size = SIZE * SIZE;
	if ((mask & tetr) != 0 && (*visited & mask) == 0)
	{
		prev_visited = *visited;
		*visited |= mask;
		if (count_ones(visited) == 4 && (prev_visited ^ *visited) == 0)
			return (0);
		if (index < total_size - SIZE && (*visited & (mask << SIZE)) == 0)
			t->height += tetro_wh(t, mask << SIZE, visited, tetr, index + SIZE);
		if (index >= SIZE && (*visited & (mask >> SIZE)) == 0)
			t->height += tetro_wh(t, mask >> SIZE, visited,  tetr, index - SIZE);
		if (index % SIZE != 0 && (*visited & (mask >> 1)) == 0)
			t->width += tetro_wh(t, mask >> 1, visited, tetr, index - 1);
		if ((index + 1) % SIZE != 0 && (*visited & (mask << 1)) == 0)
			t->width += tetro_wh(t, mask << 1, visited, tetr, index + 1);
		return (1);
	}
	return (0);
}

int		add_tetro(unsigned short tetr, size_t count, t_list **lst, size_t total_size)
{
	t_tetro *t;
	unsigned short mask;
	unsigned short visited;

	visited = 0;
	t = (t_tetro *)malloc(sizeof(t_tetro));
	if (!t)
		return (0);
	t->tetro = tetr;
	t->print = 'A' + (count - 1);
	find_first(t);
	mask = (1 << t->og_index1);
	t->width = 1;
	t->height = 1;
	t->og_index1 = 0U;
	t->og_index2 = 0U;
	t->og_index3 = 0U;
	t->og_index4 = 0U;
	t->pl_index1 = 0U;
	t->pl_index2 = 0U;
	t->pl_index3 = 0U;
	t->pl_index4 = 0U;
	total_size = SIZE * SIZE;
	if (is_smashboy(tetr))
	{
		t->width = SIZE / 2;
		t->height = SIZE / 2;
	}
	else
		tetro_wh(t, mask, &visited, tetr, t->og_index1);
	if (!(ft_lstaddend(lst, t, sizeof(t))))
		return (0);
	t_list *tmp;
	tmp = *lst;
	return (1);
}
