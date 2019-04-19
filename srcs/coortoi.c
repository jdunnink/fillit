/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coortoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 12:59:46 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/19 13:00:03 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	coortoi(int row, int column, size_t size)
{
	size_t index;

	index = row * size + column;
	return (index);
}
