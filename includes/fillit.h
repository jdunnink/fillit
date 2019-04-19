/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 08:38:03 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/18 08:39:07 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#   include "get_next_line.h"
#   include "libft.h"

typedef struct s_tetro
{
    short *tetro;                       // tetro
    int type;                           // which tetro it is
    int width;                          // total width of tetro
    int height;                         // total height of tetro
    char print;                         //   
    void    *next;  
}              t_tetro;

size_t coortoi(int row, int column, size_t size);
void    itocoor(int *x, int *y, size_t index, size_t size);
int    tetro_translate(unsigned short *dest);
int     validate_tetro(unsigned short *tetro);
void        to_bits(char *s, unsigned short *dst, int iter);
int    read_input(const int fd, t_list **list);

#endif
