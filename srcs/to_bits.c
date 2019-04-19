/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_bits.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 13:00:45 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/19 13:01:07 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void        to_bits(char *s, unsigned short *dst, int iter)
{
    int i;
    unsigned short res;
    int len;

    len = strlen(s);
    i = 0;
    res = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '#')
        {
            res |= 1 << (len - (i + 1));
        }
        i++;
    }
	*dst |= res << (len * (len - 1) - (len * iter));
}
