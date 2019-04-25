/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_solution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 09:45:04 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/25 17:10:24 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_list		*is_tetromino_at_index(t_list *t, void *id)
{
	size_t *n;

	n = (size_t *)id;
	if (((t_tetro *)((t_list*)t)->content)->og_index1 == *n)
		return ((t_list*)t);
	return (NULL);
}

int	find_tetromino(size_t index, unsigned long long *mask, char *c, t_list **lst)
{
	t_list *curr;
	t_tetro *ct;

	curr = ft_lstsearch(lst, &is_tetromino_at_index, &index);
	if (!curr)
		return(ft_error("Something went wrong printing the solution"));
	ct = (t_tetro *)(t_list*)curr->content;
	*mask = ((t_tetro *)curr)->tetro;
	*c = ((t_tetro *)curr)->print;
	return (1);
}

void	place_char(char **map, size_t index, char c, size_t total_size)
{
	int x;
	int y;

	itocoor(&x, &y, index, total_size);
	map[x][y] = c;
}

void	place_tetromino(char **map, size_t totalsize, size_t index, t_list **lst, unsigned long long *solution)
{
	char c;
	unsigned long long tetro;
	unsigned long long mask;
	size_t i;

	i = index;
	mask = 1UL;
	find_tetromino(index, &tetro, &c, lst);
	while (i < 64)
	{
		if (tetro & mask)	//add to map
			place_char(map, i, c, totalsize);
		if (mask & *solution)	//remove from solution
			*solution ^= mask;
		mask <<= i;
	}
}

char		**initialize_array(size_t size)
{
	char **res;
	size_t i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = ft_strnew(size);
		i++;
	}
	return (res);
}

void	print_solution(unsigned long long solution, t_list **lst, size_t map_size)
{
	size_t i;
	size_t totalsize;
	char **map;
	unsigned long long mask;

	map = initialize_array(map_size);
	totalsize = map_size * map_size;
	mask = 1;
	i = 0;
	while (i < totalsize)
	{
		if ((solution & mask) == 0)
			place_char(map, i, '.', map_size);
		else
			place_tetromino(map, totalsize, i, lst, &solution);
		i++;
		mask <<= i;
	}
}
