/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   toggle_bit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 11:40:27 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/25 17:37:15 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void toggle_bit(size_t index, size_t size, t_field *field)      // flip a bit within a field on or off
{
    int x;
    int y;
    unsigned long long tmp;

    itocoor(&x, &y, index, ft_sqrt(size));
    tmp = 9223372036854775808ULL;
    if (y > 7  && x <= 7)
       y -= 8;
    else if (y <= 7 && x > 7)
        x -= 8;
    else if (y > 7 && x > 7)
    {
        y -= 8;
        x -= 8;
    } 
    while (y > 0)
    {
        tmp >>= 8;
        y--;
    }
    while (x > 0)
    {
        tmp >>= 1;
        x--;
    }
    itocoor(&x, &y, index, ft_sqrt(size));
    if (y <= 7 && x <= 7)
        field->top_left = field->top_left ^ tmp;
    else if (y > 7  && x <= 7)
        field->bot_left = field->bot_left ^ tmp;
    else if (y <= 7 && x > 7)
        field->top_right = field->top_right ^ tmp;
    else if (y > 7 && x > 7)
        field->bot_right = field->bot_right ^ tmp;
}
