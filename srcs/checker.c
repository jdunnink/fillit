/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   starting_size.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 11:50:39 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/08 11:30:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		compare_tetros(t_list *list, t_tetro *check)
{
	t_list *curr;
	size_t count;

	curr = list;
	count = 0;
	while (curr)
	{
		if (((t_tetro *)(curr->content))->tetro ==
			(check->tetro))
			count += 1;
		curr = curr->next;
	}
	return (count);
}

static size_t	count_duplicates(int *dups, size_t num_tetros)
{
	size_t i;
	size_t res;

	res = 0;
	i = 0;
	while (i < num_tetros)
	{
		res += dups[i];
		i++;
	}
	return (res);
}

static	size_t	count_dup(t_list **lst, size_t num_tetros, size_t i)
{
	t_list	*curr;
	t_list	*check;
	int		dups[num_tetros];

	ft_bzero(dups, num_tetros);
	if (!*lst)
		return (0);
	curr = (*lst)->next;
	check = *lst;
	while (i < num_tetros && check)
	{
		dups[i] = compare_tetros(curr, check->content);
		check = check->next;
		i++;
	}
	return (count_duplicates(dups, num_tetros));
}

static	int		get_size(t_list **tetros, size_t num_tetros, uint16_t *map)
{
	size_t	start_size;
	size_t	duplicates;

	start_size = min_mapsize(num_tetros);
	duplicates = count_dup(tetros, num_tetros, 0);
	if (duplicates < num_tetros / 2 || num_tetros < 2)
		return (start_size);
	while (!find_perm(*tetros, *tetros, map, start_size))
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		start_size++;
	}
	return (start_size);
}

int				checker(uint16_t *map, t_list **tetros, size_t num_tetros)
{
	size_t min_size;

	min_size = get_size(tetros, num_tetros, map);
	list_sort(*tetros);
	return (min_size);
}
