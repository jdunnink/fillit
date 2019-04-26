
#include "fillit.h"


static size_t min_mapsize(size_t count)
{
    size_t i;

    count *= 4;
    i = 0;
    while (i * i < count)
        i++;
    return (i);
}

static t_field solve_map(t_field field, t_list *tetros, int *go)
{
    printf("\nSOLVE_MAP IS CALLED\n");
    if(tetros)
    {
        if(solve_pos(&field, tetros->content))
            field = solve_map(field, tetros->next, go);
    }
    else
    {
        *go = 1;
        return (field);
    }
    return(field);
}

int solver(t_field *dest, t_list *tetros, size_t num_tetros)
{
    size_t size;
    size_t list_change;
    int     go;
    t_field field;

    printf("\nSOLVER IS CALLED\n");

    go = 0;
    list_change = 0;
    size = min_mapsize(num_tetros);
    while(size < 256 && go == 0)
    {
        list_change = 0;
        while (list_change <= num_tetros && go == 0)
        {
            field = create_field(size * size);
            printf("\nA field has been created, the current field:\n");
            print_field(field);
            field = solve_map(field, tetros, &go);
            if (go == 1)
            {
                printf("\nA solution has been found\n");
                *dest = field;
                return (1);
            }
            printf("\nNo solution has been found\n");
            lst_diff_order(tetros);
            list_change++;
        }
        size++;
    }
    *dest = field;
    return (0);
}
