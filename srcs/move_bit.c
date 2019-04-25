/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_bit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 12:35:34 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/25 12:35:43 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void move_bit(size_t index, size_t new_index, t_field *field)
{
    toggle_bit(index, field->size, field);
    toggle_bit(new_index, field->size, field);
}
