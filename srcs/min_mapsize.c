/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min_mapsize.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 10:39:24 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/06 10:39:35 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	min_mapsize(size_t num_tetros)
{
	size_t i;

	i = 2;
	while (i * i < (num_tetros * SIZE))
		i++;
	return (i);
}
