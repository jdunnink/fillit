/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 14:05:29 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/25 19:40:25 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate_tetro(unsigned short *tetro, size_t total_size)
{
	if (count_ones(tetro) != 4)
		return (ft_error("Too many blocks in tetromino"));
	if (!check_edges(tetro, total_size))
		return (ft_error("Invalid tetromino shape found"));
	return (1);
}


int		read_tetromino(int *lr, int fd, char **line, unsigned short *dst)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		*lr = get_next_line(fd, line);
		if (*lr == 0)
			return (0);
		if (*lr < 0)
			return(ft_error("Invalid file or problem while reading"));
		if (!(valid_characters(*line, '#', '.')))
			return(ft_error("Invalid character found"));
		if (!(ft_strlen(*line) == 4))
			return(ft_error("Invalid line width"));
		to_bits(*line, dst, i, '#');
		i++;
	}
	return (1);
}

int		read_input(int fd, t_list **list, size_t *count)
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
			if (!add_tetro(dst, *count, list, total_size))
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
