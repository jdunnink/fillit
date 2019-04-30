/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 17:33:42 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/30 17:35:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	find_first(t_tetro *t)
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

static	int		add_tetro(unsigned short tetr, size_t count, t_list **lst)
{
	t_tetro *t;

	t = (t_tetro *)malloc(sizeof(t_tetro));
	if (!t)
		return (0);
	t->tetro = tetr;
	t->print = 'A' + (count - 1);
	t->order = count;
	find_first(t);
	set_indexes(t);
	if (!(ft_lstaddend(lst, t, sizeof(t_tetro))))
		return (0);
	return (1);
}

int				read_input(int fd, t_list **list, size_t *count)
{
	int test;
	int lr;
	char *line;
	unsigned short dst;
	size_t total_size;

	total_size = SIZE * SIZE;
	lr = 1;
	line = NULL;
	while (lr == 1)
	{
		if (*count > 25)
			return (ft_error("Too many tetrominos"));
		test = read_tetromino(&lr, fd, &line, &dst);
		if (test != 1)
			return (test);
		*count += 1;
		if (validate_tetro(&dst, total_size))
		{
			tetro_translate(&dst, total_size);
			if (!add_tetro(dst, *count, list))
				return (ft_error("Something went wrong while creating the list"));
		}
		else
			return(ft_error("Invalid tetromino found"));
		dst = 0;
		lr = get_next_line(fd, &line);
		if (lr == 0)
			return (0);
		if (!(line[0] == '\n' || line[0] == '\0'))
			return (ft_error("Unexpected character encountered"));
	}
	return (0);
}
