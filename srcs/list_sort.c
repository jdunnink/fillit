/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   order_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:26:14 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 14:53:05 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	list_sort(t_list *tetros)
{
	t_list *iter;
	t_list *trail;
	t_list *tmp;

	iter = tetros->next;
	trail = tetros;
	while (iter)
	{
		if (((t_tetro*)iter->content)->order <
			(((t_tetro*)trail->content)->order))
		{
			tmp = iter->content;
			iter->content = trail->content;
			trail->content = tmp;
			trail = tetros;
			iter = tetros->next;
		}
		else
		{
			iter = iter->next;
			trail = trail->next;
		}
	}
}
