/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   toggle_tetro.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 18:11:46 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/07 11:53:59 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	toggle_tetro(uint16_t *map, t_tetro *tetro)
{
	*(uint64_t *)(map + tetro->y) ^= (tetro->tetro >> tetro->x);
}
