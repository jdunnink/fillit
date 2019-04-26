
#include "fillit.h"

static unsigned long long add_empty_row(unsigned long long part_field)
{
    return (part_field >> 8);
}

static unsigned long long add_empty_left(unsigned long long part_field)
{
    unsigned long long mask;
    unsigned long long tmp;

    tmp = part_field;
    mask = 9259542123273814144ULL;
    while ((tmp >> 63) == 0)
    {
        tmp <<= 1;
        mask >>= 1;
    }
    part_field = part_field ^ mask;
    return (part_field);
}

static unsigned long long expand_part_field(unsigned long long part_field)
{
    unsigned long long mask1;
    unsigned long long mask2;
    unsigned long long tmp;

    mask1 = 18446744073709551615ULL;
    mask2 = 18446744073709551615ULL;
    tmp = part_field;
    while ((tmp >> 63) == 0)
    {
        tmp <<= 1;
        mask1 = add_empty_row(mask1);
        mask2 = add_empty_left(mask2);
    }
    mask1 = add_empty_row(mask1);
    mask2 = add_empty_left(mask2);
    return (mask2 | mask1);
}

static t_field init_field(size_t total_size)                              
{
    t_field field;
    unsigned long long init;

    init = 18446744073709551615ULL;
    field.top_left = init;
    field.top_right = init;
    field.bot_left = init;
    field.bot_right = init;
    field.size = total_size;
    return (field);
}

t_field create_field(size_t total_size)                                   
{
    size_t i;
    size_t size;
    t_field field;

    field = init_field(total_size);
    size = ft_sqrt(total_size);
    i = 0;
    if (total_size == 0)
        return (field);
    while (i < size && i < 8)
    {
        field.top_left = expand_part_field(field.top_left);
        i++;
    }
    if (i == size)
        return (field);    
    while (i < size && i < 16)
    {
        field.bot_right = expand_part_field(field.bot_right);
        field.bot_left = add_empty_row(field.bot_left);
        field.top_right = add_empty_left(field.top_right);
        i++;
    }
    return (field);
}
