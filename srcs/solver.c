/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:50:00 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 13:49:24 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				solver(uint16_t *map, t_list **tetros, size_t map_size)
{
	while (map_size <= 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		if (solve_map(map, tetros, map_size))
			return (map_size);
		map_size++;
	}
	return (0);
}
