

#include <string.h>
#include <stdio.h>
#include <unistd.h>


int	ft_sqrt(int nb)
{
	int i;
	int sq;

	i = 1;
	sq = 1;
	if(nb == 0)
		return(0);
	while (i * i < nb)
	{
		i++;
	}
	if ((nb % i) == 0)
		return (i);
	else
		return(0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// 3 X 3 FIELD = size 9

// 0 0 0 1 1 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 1 1 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0001111100011111000111111111111111111111111111111111111111111111     1111111111111111111111111111111111111111111111111111111111111111
// 2242546323825885183                                                  18446744073709551615

// 4 X 4 FIELD = size 16

// 0 0 0 0 1 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 1 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 1 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1 
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1 
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0000111100001111000011110000111111111111111111111111111111111111     1111111111111111111111111111111111111111111111111111111111111111
// 1085102596613472255                                                  18446744073709551615

// 5 X 5 FIELD = size 25

// 0 0 0 0 0 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 1 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0000011100000111000001110000011100000111111111111111111111111111     1111111111111111111111111111111111111111111111111111111111111111
// 506381209882853375                                                   18446744073709551615

// 6 X 6 FIELD = size 36

// 0 0 0 0 0 0 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 1 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0000001100000011000000110000001100000110000001111111111111111111     1111111111111111111111111111111111111111111111111111111111111111
// 506381209882853375                                                   18446744073709551615

// 7 X 7 FIELD = size 49

// 0 0 0 0 0 0 0 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 1  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0000000100000001000000010000000100000010000001000000011111111111     1111111111111111111111111111111111111111111111111111111111111111
// 72340172855052287                                                    18446744073709551615

// 8 X 8 FIELD = 64

// 0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  1 1 1 1 1 1 1 1

// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0000000000000000000000000000000000000000000000000000000000000000     1111111111111111111111111111111111111111111111111111111111111111
// 0                                                                    18446744073709551615

// 9 X 9 FIELD = 81

// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1

// 0 0 0 0 0 0 0 0  0 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0000000000000000000000000000000000000000000000000000000000000000     0111111101111111011111110111111101111111011111110111111101111111
// 0                                                                    9187201950435737471
// 0000000011111111111111111111111111111111111111111111111111111111     0111111111111111111111111111111111111111111111111111111111111111
// 72057594037927935                                                    9223372036854775807

// 10 X 10 FIELD = 100

// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1

// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0000000000000000000000000000000000000000000000000000000000000000     0011111100111111001111110011111100111111001111110011111100111111
// 0                                                                    4557430888798830399
// 0000000000000000111111111111111111111111111111111111111111111111     0011111100111111111111111111111111111111111111111111111111111111
// 281474976710655                                                      4557642822898941951

// 11 X 11 FIELD = 121

// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1

// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 0 0 0 0 0 0 0 0  0 0 0 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

// 0000000000000000000000000000000000000000000000000000000000000000     0001111100011111000111110001111100011111000111110001111100011111
// 0                                                                    2242545357980376863
// 0000000000000000000000001111111111111111111111111111111111111111     0001111100111110001111111111111111111111111111111111111111111111
// 1099511627775                                                        2251307232476004351


// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1


unsigned long long add_empty_node(unsigned long long part_field)            // set the topleft node of a partial field to zero
{
    return (part_field >> 1);
}

unsigned long long add_empty_row(unsigned long long part_field)             // add an empty row at the top of a partial field
{
    return (part_field >> 8);
}

void print_part_field(unsigned long long part_field, size_t size)
{
    unsigned long long tmp;
    size_t width;

    width = ft_sqrt(size);
    tmp = part_field;

    while (size)
    {
        tmp = tmp >> (size - 1);
        if (tmp & 1)
            ft_putchar('#');
        else
            ft_putchar('.');
        size--;
        tmp = part_field;
        if (size % width == 0)
            ft_putchar('\n');
    }
}

unsigned long long add_empty_left(unsigned long long part_field)            // set the right column of a partial field to zero
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

unsigned long long expand_part_field(unsigned long long part_field)              // expand the current open field by 1 row/col
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

typedef struct s_field
{
    unsigned long long top_left;
    unsigned long long top_right;
    unsigned long long bot_left;
    unsigned long long bot_right;
    size_t  size;
}               t_field;

// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1

void print_fieldrow_bottom(t_field field, size_t total_size, size_t width)
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

void print_fieldrow_top(t_field field, size_t total_size, size_t width)
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

void    print_field(t_field field, size_t total_size)
{
    size_t width;

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

t_field create_field(size_t size)
{
    t_field field;
    unsigned long long init;
    size_t i;

    init = 18446744073709551615ULL;
    i = 0;
    field.top_left = init;
    field.top_right = init;
    field.bot_left = init;
    field.bot_right = init;
    if (size == 0)
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

int main(void)
{
    t_field field;

    field = create_field(11);
    ft_putchar('\n');
    print_part_field(field.top_left, 64);
    ft_putchar('\n');
    print_part_field(field.top_right, 64);
    ft_putchar('\n');
    print_part_field(field.bot_left, 64);
    ft_putchar('\n');
    print_part_field(field.bot_right, 64);
    ft_putchar('\n');
    print_field(field, 256);
    return (0);
}



