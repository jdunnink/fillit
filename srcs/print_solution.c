/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_solution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 09:45:04 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/30 11:18:40 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t  get_row_q(size_t index, size_t o_size)
{
	size_t row;

	row = 0;
	row = index / o_size;
	return (row);
}

static size_t convert(size_t index, size_t n_width, size_t o_width)
{
	size_t new;
	size_t diff;
	size_t row;

	row = get_row_q(index, o_width);
	if (o_width < n_width)
	{
		diff = o_width - n_width;
		new = index - (diff * row);
	}
	else
	{
		diff = n_width - o_width;
		new = index + (diff * row);
	}
	return (new);
}

static void	place_tetro(t_tetro *t, char **map, size_t size)
{
	int x;
	int y;
	size_t index;

	index = t->pl_index1;
	convert(index, size, 16);
	itocoor(&x, &y, t->pl_index1, 16);
	map[x][y] = t->print;

	index = t->pl_index2;
	convert(index, size, 16);
	itocoor(&x, &y, t->pl_index2, 16);
	map[x][y] = t->print;

	index = t->pl_index3;
	convert(index, size, 16);
	itocoor(&x, &y, t->pl_index3, 16);
	map[x][y] = t->print;

	index = t->pl_index4;
	convert(index, size, 16);
	itocoor(&x, &y, t->pl_index4, 16);
	map[x][y] = t->print;
}

static void		place_tetraminos(char **map, t_list **lst, size_t size)
{
	t_list *curr;

	curr = *lst;
	while (curr)
	{
		place_tetro(curr->content, map, size);
		curr = curr->next;
	}
}

static char		**initialize_array(size_t size)
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

void	print_solution(t_field *field, t_list **lst)
{
	size_t i;
	size_t j;
	size_t size;
	char **map;

	size = ft_sqrt(field->size);
	map = initialize_array(size);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	place_tetraminos(map, lst, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[j][i]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
