
#include "fillit.h"

static void print_fieldrow_bottom(t_field field, size_t total_size, size_t width)
{
    unsigned long long tmp;
    size_t size;

    tmp = field.bot_left;
    size = total_size / 4;
    while(width != 8)
    {
        tmp = tmp >> (size - 1);
        if (tmp & 1)
            ft_putchar('#');
        else
            ft_putchar('.');
        width--;
        size--;
        tmp = field.bot_left;
    }
    tmp = field.bot_right;
    size = total_size / 4;
    while(width != 0)
    {
        tmp = tmp >> (size - 1);
        if (tmp & 1)
            ft_putchar('#');
        else
            ft_putchar('.');
        width--;
        size--;
        tmp = field.bot_right;
    }
    ft_putchar('\n');
}

static void print_fieldrow_top(t_field field, size_t total_size, size_t width)
{
    unsigned long long tmp;
    size_t size;

    tmp = field.top_left;
    size = total_size / 4;
    while(width != 8)
    {
        tmp = tmp >> (size - 1);
        if (tmp & 1)
            ft_putchar('#');
        else
            ft_putchar('.');
        width--;
        size--;
        tmp = field.top_left;
    }
    tmp = field.top_right;
    size = total_size / 4;
    while(width != 0)
    {
        tmp = tmp >> (size - 1);
        if (tmp & 1)
            ft_putchar('#');
        else
            ft_putchar('.');
        width--;
        size--;
        tmp = field.top_right;
    }
    ft_putchar('\n');
}

void    print_field(t_field field)
{
    size_t width;
    size_t total_size;

    total_size = 256;
    width = ft_sqrt(total_size);
    while(total_size != 128)
    {
        print_fieldrow_top(field, 256, width);
        field.top_left <<= 8;
        field.top_right <<= 8;
        total_size -= 16;
    }
    while(total_size != 0)
    {
        print_fieldrow_bottom(field, 256, width);
        field.bot_left <<= 8;
        field.bot_right <<= 8;
        total_size -= 16;
    }
}