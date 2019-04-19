/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitboards.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 10:35:17 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/18 11:34:27 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetro_translate(unsigned short *dest)
{
    if (*dest == 0)                             // if dest == 0 (invalid tetro)
        return (0);                                    // stop
    while ((61440 & *dest) == 0)                // while the first line does not contain a 1;
        *dest = *dest << 4;                         // shift up one row
    while ((34952 & *dest) == 0)               // while the first column does not contain a 1;
        *dest = *dest << 1;                         // shift left one column
	return (1);   
}