/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_len.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 10:00:35 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/06 10:00:45 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	lst_len(t_list **lst)
{
	size_t count;
	t_list *curr;

	curr = *lst;
	count = 0;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
