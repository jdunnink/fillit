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

void			read_tetromino(char **tetros, uint16_t *dst)
{
	int i;

	i = 0;
	*dst = 0;
	while (i < SIZE)
	{
		to_bits(tetros[i], dst, i, '#');
		i++;
	}
}
