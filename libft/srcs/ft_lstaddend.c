/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:00:42 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 14:12:30 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstaddend(t_list **begin_list, void *content, size_t n)
{
	t_list *new;
	t_list *tmp;

	tmp = *begin_list;
	new = ft_lstnew(content, n);
	if (!new)
		return(0);
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}
