/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_bits.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 12:35:15 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/25 17:12:07 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void toggle_bits(t_tetro tetro, t_field *field)
{
    toggle_bit(tetro.pl_index1, field->size, field);
    toggle_bit(tetro.pl_index2, field->size, field);
    toggle_bit(tetro.pl_index3, field->size, field);
    toggle_bit(tetro.pl_index4, field->size, field);
}
