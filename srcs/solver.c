
#include "fillit.h"

static void list_sort(t_list *tetros)
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

static size_t min_mapsize(size_t count)
{
    size_t i;

    count *= 4;
    i = 2;
    while (i * i < count)
        i++;
    return (i);
}

static t_field combine_fields(t_field map, t_field tmp)
{
    t_field dest;

    dest.top_left = map.top_left | tmp.top_left;
    dest.top_right = map.top_right | tmp.top_right;
    dest.bot_left = map.bot_left | tmp.bot_left;
    dest.bot_right = map.bot_right | tmp.bot_right;
    dest.size = map.size;
    return (dest);
}

static int solve_map(t_field field, t_list *tetros, t_field *dest)
{
    t_field tmp;
    int res;

    res = 0;
    if (tetros)
    {
        if (solve_pos(field, tetros->content, &tmp) == 1)
        {
            res = solve_map(combine_fields(field, tmp), tetros->next, dest);
            if (res == - 1)
            {
                if(lst_diff_order(tetros) == -1)
                     return (-1);
                else
                    res = solve_map(field, tetros, dest);
            }
            if (res == 1)
                return (1);
            else if (res == -1)
                return (-1);
        }
        else
            return (-1);
    }
    else
    {
        *dest = field;
        return (1);
    }
    return (1);
}

int solver(t_field *dest, t_list *tetros, size_t num_tetros)
{
    size_t size;
    t_field field;

    size = min_mapsize(num_tetros);
    while(size < 16)
    {
        field = create_field(size * size);
        if (solve_map(field, tetros, dest) == 1)
            return (1);
        else
        {
            size++;
            list_sort(tetros);
            field = create_field(256);
        }
    }
    return (0);
}
