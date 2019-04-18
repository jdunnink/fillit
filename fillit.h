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

typedef struct s_tetro
{
    short *tetro;                       // tetro
    int type;                           // which tetro it is
    int width;                          // total width of tetro
    int height;                         // total height of tetro
    char print;                         //   
    void    *next;  
}              t_tetro;

#endif
