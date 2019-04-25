/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_bits.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 12:35:55 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/25 17:13:56 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void move_bits(t_tetro tetro, int move_height, int move_width, t_field *field)
{
    size_t new_index;

    new_index = tetro.pl_index1 + coortoi(move_width, move_height, ft_sqrt(field->size));
    move_bit(tetro.pl_index1, new_index, field);
    new_index = tetro.pl_index2 + coortoi(move_width, move_height, ft_sqrt(field->size));
    move_bit(tetro.pl_index2, new_index, field);
    new_index = tetro.pl_index3 + coortoi(move_width, move_height, ft_sqrt(field->size));
    move_bit(tetro.pl_index3, new_index, field);
    new_index = tetro.pl_index4 + coortoi(move_width, move_height, ft_sqrt(field->size));
    move_bit(tetro.pl_index4, new_index, field);
}
