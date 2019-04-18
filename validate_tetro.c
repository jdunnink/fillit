/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitboards.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 10:35:17 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/18 11:34:27 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void        to_bits(char *s, unsigned short *dst, int iter)
{
    int i;
    unsigned short res;
    int len;

    len = strlen(s);
    i = 0;
    res = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '#')
        {
            res |= 1 << (len - (i + 1));
        }
        i++;
    }
	*dst |= res << (len * (len - 1) - (len * iter));
}

void	conv_1d_index_to_2d(int *x, int *y, size_t index, size_t size)
{
	*x = index / size;
	*y = index % size;
}

int count_ones(unsigned short *tetro)
{
    unsigned short tmp;
    int count;

    count = 0;
    tmp = *tetro;
    while (tmp)
    {
        count += tmp & 1;
        tmp >>= 1;
    }
    return (count);
}

int is_one(unsigned short *tetro, size_t index)
{
    unsigned short tmp;
    unsigned short mask;

    tmp = *tetro;
    mask = 1 << (index - 1);
    tmp = tmp & mask;
    if (tmp == 0)
        return (0);
    return (1);
}

int     count_sides(size_t index, unsigned short *tetro, size_t size)
{
    int x;
    int y;
    int count;

    x = 0;
    y = 0;
    count = 0;
    conv_1d_index_to_2d(&x, &y, index, size);

    if (x < 4)
        count += is_one(tetro, index + 1);
    if (y < 4)
        count += is_one(tetro, index + 4);
    if (y > 0)
        count += is_one(tetro, index  - 4);
    if (x > 0)
        count += is_one(tetro, index - 1);
    return (count);
}

int tetro_check_1(unsigned short *tetro, size_t size)
{
    int count;
    size_t index;

    count = 0;
    index = size;
    while (index)
    {
        printf("\nThe index is currently %lu\n", index);
        if(is_one(tetro, index))
        {
            printf("\nThis bit is set\n");
            count += count_sides(index, tetro, size);
        }
        else
            printf("\nThis bit is not set\n");
        index--;
    }
    if (count != 6)
        return (0);
    return (1);
}

int tetro_check_2(unsigned short *tetro, size_t size)
{
    size_t i;
    int count;

    count = 0;
    i = 0;
    while (i < size)
    {
        if(is_one(tetro, i))
            count += count_sides(i, tetro, size);
        i++;
    }
    if (count != 8)
        return (0);
    return (1);
}

int validate_tetro(unsigned short *tetro, size_t size)
{   
    printf("\nThis tetromino has %i blocks\n", count_ones(tetro));
    if(count_ones(tetro) != 4)
    {
        printf("\n---------------------The number of blocks is invalid------------------------------\n");
        return (0);
    }
    if(tetro_check_1(tetro, size) == 0)
    {
        if(tetro_check_2(tetro, size) == 0)
            return (0);
    }
    return (1);
}

int main(void)
{
    unsigned short dest;
    char *str1 = "#...";
    char *str2 = "#...";
    char *str3 = "#...";
    char *str4 = "#...";

    dest = 0;
    to_bits(str1, &dest, 0);
    to_bits(str2, &dest, 1);
    to_bits(str3, &dest, 2);
    to_bits(str4, &dest, 3);

    if(validate_tetro(&dest, 16))
        printf("This tetrominoe is valid\n");
    else
        printf("not valid\n");
    return (0);
}