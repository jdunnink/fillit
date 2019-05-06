/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:46:05 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 12:41:52 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	itocoor(int *x, int *y, size_t index, size_t size)
{
	*x = index % size;
	*y = index / size;
}
