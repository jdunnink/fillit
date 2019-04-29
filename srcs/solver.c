
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
    i = 0;
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
    return (dest);
}

static int solve_map(t_field field, t_list *tetros, t_field *dest)
{
    t_field tmp;
    int res;

    res = 0;
    printf("\nSOLVE_MAP IS CALLED\n");
    printf("\nThe current field:\n");
    print_field(field);
    if (tetros)
    {
        printf("\nTetros remaining in the list\n");
        if (solve_pos(field, tetros->content, &tmp) == 1)
        {
            printf("\ncurrent tetro fits --> PUSH\n");
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
        {
            printf("\ncurrent tetro does not fit --> POP\n");
            return (-1);
        }
    }
    else
    {
        printf("\nA Valid square has been found --> POP\n");
        *dest = field;
        return (1);
    }
    return (1);
}

int solver(t_field *dest, t_list *tetros, size_t num_tetros)
{
    size_t size;
    t_field field;

    printf("\nSOLVER IS CALLED\n");

    size = min_mapsize(num_tetros);
    while(size < 16)
    {
        field = create_field(size * size);
        printf("\nA new field has been created\n");
        if (solve_map(field, tetros, dest) == 1)
        {
            printf("\nA solution has been found\n");
            return (1);
        }
        else
        {
            printf("\nNo solution at current size, increasing field\n");
            size++;
            list_sort(tetros);
            field = create_field(256);
        }
    }
    printf("\nNo viable solution wiithin parameters\n");
    return (0);
}
