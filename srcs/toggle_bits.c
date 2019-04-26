
#include "fillit.h"

static void toggle_bit(size_t index, size_t size, t_field *field)
{
    int x;
    int y;
    unsigned long long tmp;

    itocoor(&x, &y, index, ft_sqrt(size));
    tmp = 9223372036854775808ULL;
    if (y > 7  && x <= 7)
       y -= 8;
    else if (y <= 7 && x > 7)
        x -= 8;
    else if (y > 7 && x > 7)
    {
        y -= 8;
        x -= 8;
    } 
    while (y > 0)
    {
        tmp >>= 8;
        y--;
    }
    while (x > 0)
    {
        tmp >>= 1;
        x--;
    }
    itocoor(&x, &y, index, ft_sqrt(size));
    if (y <= 7 && x <= 7)
        field->top_left = field->top_left ^ tmp;
    else if (y > 7  && x <= 7)
        field->bot_left = field->bot_left ^ tmp;
    else if (y <= 7 && x > 7)
        field->top_right = field->top_right ^ tmp;
    else if (y > 7 && x > 7)
        field->bot_right = field->bot_right ^ tmp;
}

void toggle_bits(t_tetro tetro, t_field *field)
{
    toggle_bit(tetro.pl_index1, field->size, field);
    toggle_bit(tetro.pl_index2, field->size, field);
    toggle_bit(tetro.pl_index3, field->size, field);
    toggle_bit(tetro.pl_index4, field->size, field);
}