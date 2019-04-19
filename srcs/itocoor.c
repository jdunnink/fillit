/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itocoor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 12:58:54 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/19 12:59:33 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	itocoor(int *x, int *y, size_t index, size_t size)
{
	*x = index % size;
	*y = index / size;
}
