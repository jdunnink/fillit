/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_part_field.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 09:19:46 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/25 09:19:47 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_part_field(unsigned long long part_field, size_t size)           // print a partial field
{
    unsigned long long tmp;
    size_t width;

    width = ft_sqrt(size);
    tmp = part_field;

    while (size)
    {
        tmp = tmp >> (size - 1);
        if (tmp & 1)
            ft_putchar('#');
        else
            ft_putchar('.');
        size--;
        tmp = part_field;
        if (size % width == 0)
            ft_putchar('\n');
    }
}