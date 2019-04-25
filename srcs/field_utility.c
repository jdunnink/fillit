#include "fillit.h"

int     get_quadrant(size_t x, size_t y)
{
    int q;

    q = 0;
    if (x < 8)
    {
        if (y < 8)
            q = 1;
        else
            q = 2;    
    }
    else
    {
        if (y < 8)
            q = 3;
        else
            q = 4;
    }
    return (q);
}

void    convert_index(size_t *x, size_t *y)
{
    int q;

    q = get_quadrant(*x, *y);
    if (q == 2)
        *y -= 8;
    if (q == 3)
        *x -= 8;
    if (q == 4)
    {
        *x -= 8;
        *y -= 8; 
    }
}

int count_field(t_field *field, size_t width)
{
    int res;
    size_t i;
    size_t j;

    j = 0;
    i = 0;
    res = 0;

    while (i < 8 && i < width)
    {
        while (j < 8 && j < width)
        {
            res += is_one(coortoi(i, j, 8), field->top_left);
            j++;
        }
        while (j < 16 && j < width)
        {
            res += is_one(coortoi(i, j - 8, 8), field->top_right);
            j++;
        }
        i++;
        j = 0;
    }
    while (i < 16 && i < width)
    {
        while (j < 8 && j < width)
        {
            res += is_one(coortoi(i - 8, j, 8), field->bot_left);
            j++;
        }
        while (j < 16 && j < width)
        {
            res += is_one(coortoi(i - 8, j - 8, 8), field->bot_right);
            j++;
        }
        j = 0;
        i++;
    }
    return (res);
}

void    reset_field(t_field *field)
{
    field->top_left = 0ULL;
    field->bot_left = 0ULL;
    field->top_right = 0ULL;
    field->bot_right = 0ULL;
}