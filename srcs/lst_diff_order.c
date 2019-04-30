/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_diff_order.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 17:22:52 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/30 17:25:09 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	list_sort(t_list *tetros)
{
	t_list *iter;
	t_list *trail;
	t_list *tmp;

	iter = tetros->next;
	trail = tetros;
	while (iter)
	{
		if (((t_tetro*)iter->content)->order < (((t_tetro*)trail->content)->order))
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

int				lst_diff_order(t_list *tetros)
{
	t_list *iter;
	t_tetro *comp;
	t_tetro *tmp;

	comp = tetros->content;
	iter = tetros->next;
	while (iter)
	{
		if (((t_tetro*)iter->content)->order > (comp->order))
		{ 
			tmp = tetros->content;
			tetros->content = iter->content;
			iter->content = tmp;
			list_sort(tetros->next);
			return (1);
		}
		iter = iter->next;
	}
	list_sort(tetros);
	return (-1);
}
