/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_solver.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 16:52:00 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/25 20:25:31 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_fit_field(t_field map, t_field tmp)
{
    tmp.top_left = tmp.top_left ^ map.top_left;
    map.top_left = tmp.top_left | map.top_left;
    if (map.top_left != tmp.top_left)
        return (0);
    tmp.top_right = tmp.top_right ^ map.top_right;
    map.top_right = tmp.top_right | map.top_right;
    if (map.top_right != tmp.top_right)
        return (0);
    tmp.bot_left = tmp.bot_left ^ map.bot_left;
    map.bot_left = tmp.bot_left | map.bot_left;
    if (map.bot_left != tmp.bot_left)
        return (0);
    tmp.bot_right = tmp.bot_right ^ map.bot_right;
    map.bot_right = tmp.bot_right | map.bot_right;
    if (map.bot_right != tmp.bot_right)
        return (0);
    return (1);
}

t_field combine_fields(t_field map, t_field tmp)
{
    t_field dest;

    dest.top_left = map.top_left | tmp.top_left;
    dest.top_right = map.top_right | tmp.top_right;
    dest.bot_left = map.bot_left | tmp.bot_left;
    dest.bot_right = map.bot_right | tmp.bot_right;
    return (dest);
}

int solve_pos(t_field *map, t_tetro *tetro)
{
    t_field tmp;

    tmp = create_field(256);
	set_indexes(tetro);
	tetro->pl_index1 = tetro->og_index1;
	tetro->pl_index2 =	tetro->og_index2;
	tetro->pl_index3 =	tetro->og_index3;
	tetro->pl_index4 =	tetro->og_index4;
    toggle_bits(*tetro, &tmp);
	print_field(tmp);
    while (check_fit_field(*map, tmp) == 0)
    {
        toggle_bits(*tetro, &tmp);
        (*tetro).pl_index1++;
        (*tetro).pl_index2++;
        (*tetro).pl_index3++;
        (*tetro).pl_index4++;
        toggle_bits(*tetro, &tmp);
    }
	if (check_fit_field(*map, tmp) == 1)
	{
    	*map = combine_fields(*map, tmp);
		return (1);
	}
	return (0);
}

int solve_map(t_field *field, t_list **list, size_t map_size, size_t num_tetros)
{
    t_list *curr;
	print_field(*field);
    curr = *list;
    if (count_field(field, map_size) == (int)num_tetros * SIZE)
        return (1);
    while(curr)
    {
        if(solve_pos(field, curr->content))
            if(solve_map(field, &curr->next, map_size, num_tetros))
                return (1);
		//remove curr from fiel
		curr = curr->next;
    }
    return (0);
}

int solver(t_field *field, size_t num_tetros, t_list **tetros)
{
    size_t size;

    size = min_mapsize(num_tetros);
    printf("MAP_SIZE: %zu\nNUM_TETROS: %zu\n", size, num_tetros);
    while (size < 5)
    {
        printf("in while\n");
        *field = create_field(size * size);
        if (solve_map(field, tetros, size, num_tetros))
            return (1);
        reset_field(field);
        size++;
    }
    print_field(*field);
    return (0);
}
