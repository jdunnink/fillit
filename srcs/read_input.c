/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:11:12 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/07 10:49:44 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_count(size_t *count)
{
	if (*count > 25)
		return (0);
	return (1);
}

static int		valid_characters(char *line, char f, char e)
{
	size_t i;

	i = 0;
	if (ft_strlen(line) == 21 && line[20] != '\n')
		return (0);
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (line[i] != f && line[i] != e)
				return (0);
		}
		else if (line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int				validate_input(size_t *count, char *buff, uint16_t *dst,
t_list **list)
{
	char	**tetro;
	size_t	total;

	total = SIZE * SIZE;
	tetro = NULL;
	if (!check_count(count))
		return (0);
	tetro = ft_strsplit(buff, '\n');
	if (!valid_characters(buff, '#', '.'))
		return (0);
	*dst = 0;
	*count += 1;
	read_tetromino(tetro, dst);
	free_tetro(tetro);
	if (!validate_tetro(dst, total))
		return (0);
	tetro_translate(dst, total);
	if (!add_tetro(*dst, *count, list))
		return (0);
	return (1);
}

int				read_tetri(int fd, size_t *count, uint16_t *dst, t_list **list)
{
	int		nbr;
	char	buff[22];
	int		pnbr;

	pnbr = 0;
	nbr = 21;
	while (nbr >= 20)
	{
		ft_bzero(buff, 22);
		nbr = read(fd, buff, 21);
		if (nbr == 0)
		{
			if (pnbr == 20)
				return (1);
			return (0);
		}
		if (nbr < 20)
			return (0);
		if (!validate_input(count, buff, dst, list))
			return (0);
		pnbr = nbr;
	}
	return (1);
}

int				read_input(int fd, t_list **list, size_t *count)
{
	int			test;
	uint16_t	dst;

	dst = 0;
	*list = NULL;
	test = read_tetri(fd, count, &dst, list);
	if (!test)
		return (0);
	return (1);
}
