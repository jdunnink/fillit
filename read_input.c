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

#include "libft.h"
#include "fillit.h"
#include "get_next_line.h"

#include <stdio.h>

void    read_input(const int fd, char **line, t_list **list)
{
    int r;
    int i;
    short *dest;

    r = 1;
    while(r == 1)
    {
        while (i < 4)
        {
            r = get_next_line(fd, &line);
            if (r == -1)
                return (-1);
            if (ft_strlen(line) == 4)
                to_bits(line, dest, i);                                     // add the bitversion of line to bittetro.
            else
                return (-1);
            i++;
        }
        translate_tetro(dest);                                                // turn a bittetro into its absolute version
        if (validate_tetro(dest) == 1);                                         // check if bittetro is valid.
            ft_lstpushfront(dest, &list, 1);
        i == 0;
        r = get_next_line(fd, &line);
        if (line == '\n')
            continue;
        else
            return (-1);
    }
}
