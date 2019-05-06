/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_solution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:38:05 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/06 12:22:44 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	**initialize_array(size_t size)
{
	char	**res;
	size_t	i;

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

static	void	fill_array(char **res, size_t mapsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < mapsize)
	{
		i = 0;
		while (i < mapsize)
		{
			res[j][i] = '.';
			i++;
		}
		j++;
	}
}

static	void	put_map(char **res, size_t mapsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < mapsize)
	{
		i = 0;
		while (i < mapsize)
		{
			ft_putchar(res[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

static	void	place_tetro(t_tetro *t, char **map)
{
	size_t		i;
	int			x;
	int			y;
	uint16_t	mask;

	mask = (1U << 15);
	i = 0;
	x = 0;
	y = 0;
	while (mask)
	{
		if (mask & t->fpt)
		{
			itocoor(&x, &y, i, 4);
			map[y + t->y][x + t->x] = t->print;
		}
		i++;
		mask >>= 1;
	}
}

void			print_solution(t_list **tetros, size_t mapsize)
{
	char		**res;
	t_list		*curr;

	res = initialize_array(mapsize);
	fill_array(res, mapsize);
	curr = *tetros;
	while (curr)
	{
		place_tetro(curr->content, res);
		curr = curr->next;
	}
	put_map(res, mapsize);
	free_map(res, mapsize);
}
