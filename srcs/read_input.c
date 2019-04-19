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

int    read_input(const int fd, t_list **list, size_t *count)
{
    int r;
    int i;
    unsigned short dest;
    char *line;

    dest = 0;
    r = 1;
    while(r == 1)
    {
        if(*count > 25)
            return (-7);
        i = 0;
        ft_putchar('\n');
        while (i < 4)
        {
            r = get_next_line(fd, &line);
            if (r == -1)
                return (-1);
            if (r == 0)
                return (0);
            ft_putendl(line);
            if (ft_strlen(line) == 4)
                to_bits(line, &dest, i);
            else
                return (-2);
            i++;
        }
        *count = *count + 1;
        printf("\n This is tetro : %lu\n", *count);
        ft_putchar('\n');
        printf("The current tetro == %u\n", dest);
        printf("the current tetro in binary == %s\n", ft_itoa_base(dest, 2));                                              
        if (validate_tetro(&dest) == 1)
        {
            if(tetro_translate(&dest) == 1)
                ft_lstpushfront(&dest, list, 1);
            else
                return (-3);
        }
        else
            return (-4);
        dest = 0;
        r = get_next_line(fd, &line);
        if (r == 0)
            return (0);
        if (line[0] == '\n' || line[0] == '\0')
            continue;
        else
            return (-5);
    }
    return (-6);
}
