
#include "fillit.h"

t_list *lst_diff_order(t_list *tetros)
{
    t_list *curr;
    t_list *trail;
    t_tetro *tmp;
    t_tetro *current;
    t_tetro *trailing;

    curr = tetros->next;
    trail = tetros;
    while(curr)
    {
        current = (t_tetro *)curr->content;
        trailing = (t_tetro *)trail->content;
        if (trailing->order > current->order)
        {
            tmp = (t_tetro *)curr->content;
            curr->content = trail->content;
            trail->content = tmp;
            return (tetros);
        }
        trail = curr;
        curr = curr->next;
    }
    curr = tetros->next;
    trail = tetros;
    current = (t_tetro *)curr->content;
    trailing = (t_tetro *)trail->content;
    tmp = (t_tetro *)curr->content;
    curr->content = trail->content;
    trail->content = tmp;
    return (tetros);
}