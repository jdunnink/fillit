
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


int lst_diff_order(t_list *tetros)
{
    t_list *iter;
    t_tetro *comp;
    t_tetro *tmp;

    printf("\nLDO IS CALLED\n");

    comp = tetros->content;
    printf("\ncurrent first: %lu\n", comp->order);
    iter = tetros->next;
    while(iter)
    {
        printf("\ntarget: %lu\n", ((t_tetro*)iter->content)->order);
        if (((t_tetro*)iter->content)->order > (comp->order))
        { 
            printf("\nA swap has been found:\n"); 
            tmp = tetros->content;
            tetros->content = iter->content;
            iter->content = tmp;
            list_sort(tetros->next);
            return (1);
        }
        iter = iter->next;
    }
    list_sort(tetros);
    printf("\nNo swap has been found --> POP\n"); 
    return (-1);
}