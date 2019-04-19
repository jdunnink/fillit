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
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list *tetros;
    int fd;
    int res;

    if (argc == 1)
    {
        printf("error: no input file\n");
        return (0);
    }
    fd = open(argv[1], O_RDONLY);
    if (!fd)
        ft_putendl("\nerror: file could not be opened");
    else
        printf("\nfile was opened succesfully, fd == %i\n", fd);
    res = read_input(fd, &tetros);
    if(res == -1)
        printf("error: GNL was not able to return a line\n");
    else if (res == -2)
        printf("error: the length of the line read did not match a valid tetro.\n");
    else if (res == -3)
        printf("error: translation error occurred in function tetro_translate\n");
    else if (res == -4)
        printf("error: assembled tetromino was not valid\n");
    else if(res == 1)
        printf("reading phase was completed.\n");
    close(fd);
    return (0);
}