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

int check_read_error(int res, t_list *list)
{
    if(res == -1)
        printf("\nerror 1: GNL was not able to return a line\n");
    else if (res == -2)
        printf("\nerror 2: the length of the line read did not match a valid tetro.\n");
    else if (res == -3)
        printf("\nerror 3: translation error occurred in function tetro_translate\n");
    else if (res == -4)
        printf("\nerror 4: assembled tetromino was not valid\n");
    else if (res == -5)
        printf("\nerror 5: and invalid line was found in the input file\n");
    
    else if(res == -6)
        printf("\nerror 6: undefined behavior\n");
    else if (res == -7)
        printf("\nerror 7: the number of tetros has exceeded the max.\n");
    else if (res == 0)
    {
        printf("\nThe end of the file was reached, reading is completed\n");
        return (1);
    }
    if (list == NULL)
        printf("\nerror 8: No list has been created.\n");
    return (0);
}