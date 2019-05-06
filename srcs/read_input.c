/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:11:12 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/06 13:02:12 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_count(size_t *count)
{
	if (*count > 25)
		return (ft_error("error"));
	return (1);
}

int			read_input(int fd, t_list **list, size_t *count)
{
	int				lr;
	char			*line;
	unsigned short	dst;

	lr = 1;
	while (lr == 1)
	{
		if (read_tetromino(&lr, fd, &line, &dst) < 1 ||
			check_count(count) == 0)
			break ;
		*count += 1;
		if (validate_tetro(&dst, SIZE * SIZE) == 1)
		{
			tetro_translate(&dst, SIZE * SIZE);
			if (!add_tetro(dst, *count, list))
				return (ft_error("error"));
		}
		else
			return (-1);
		dst = 0;
		if (get_next_line(fd, &line) == 0)
			return (0);
		free(line);
	}
	return (-1);
}
