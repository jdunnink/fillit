/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_tetro.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 12:17:22 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/06 12:09:26 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	to_bits(char *s, uint16_t *dst, int iter, char f)
{
	int			i;
	uint16_t	res;
	int			len;

	len = ft_strlen(s);
	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] == f)
			res |= 1U << (len - (i + 1));
		i++;
	}
	*dst |= res << (len * (len - 1) - (len * iter));
}

static	int		valid_characters(char *line, char f, char e)
{
	size_t i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != f && line[i] != e)
			return (0);
		i++;
	}
	return (1);
}

int				read_tetromino(int *lr, int fd, char **l, unsigned short *d)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		*lr = get_next_line(fd, l);
		if (*lr == 0)
			return (ft_error("error"));
		if (*lr < 0)
			return (ft_error("error"));
		if (!(valid_characters(*l, '#', '.')))
			return (ft_error("error"));
		if (!(ft_strlen(*l) == 4))
			return (ft_error("error"));
		to_bits(*l, d, i, '#');
		i++;
		free(*l);
	}
	return (1);
}
