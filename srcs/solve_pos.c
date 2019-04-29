
#include "fillit.h"

static int check_fit_field(t_field map, t_field tmp)
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

int solve_pos(t_field map, t_tetro *tetro, t_field *tmp)
{
    *tmp = create_field(256);
	tetro->pl_index1 = tetro->og_index1;
	tetro->pl_index2 = tetro->og_index2;
	tetro->pl_index3 = tetro->og_index3;
	tetro->pl_index4 = tetro->og_index4;
    toggle_bits(*tetro, tmp);
    printf("\nThe current tetro: \n");
    print_field(*tmp);
    while (check_fit_field(map, *tmp) == 0)
    {
        toggle_bits(*tetro, tmp);
        if((*tetro).pl_index1 + 1 >= 255)
            return (0);
        (*tetro).pl_index1++;
        if((*tetro).pl_index2 + 1 >= 255)
            return (0);
        (*tetro).pl_index2++;
        if((*tetro).pl_index3 + 1 >= 255)
            return (0);
        (*tetro).pl_index3++;
        if((*tetro).pl_index4 + 1 >= 255)
            return (0);
        (*tetro).pl_index4++;
        toggle_bits(*tetro, tmp);
    }
	if (check_fit_field(map, *tmp) == 1)
		return (1);
	return (0);
}