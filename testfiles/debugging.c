#include <string.h>

void	itocoor(int *x, int *y, size_t index, size_t size)
{
	*x = index % size;
	*y = index / size;
}

static int is_one(unsigned short *tetro, size_t index)
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

static int count_sides(size_t index, unsigned short *tetro)
{
    int x;
    int y;
    int count;
    size_t total_blocks;

    total_blocks = 16;
    x = 0;
    y = 0;
    count = 0;
    itocoor(&x, &y, total_blocks - index, 4);

    if (x < 4)
        count += is_one(tetro, index - 1);
    if (y < 4)
        count += is_one(tetro, index - 4);
    if (y > 0)
        count += is_one(tetro, index  + 4);
    if (x > 0)
        count += is_one(tetro, index + 1);
    return (count);
}

static  int tetro_check(unsigned short *tetro)
{
    int count;
    size_t index;

    count = 0;
    index = 16;
    while (index)
    {
        if(is_one(tetro, index))
            count += count_sides(index, tetro);        
        index--;
    }
    if (count == 6 || count == 8)
        return (1);
    return (0);
}

int main(void)
{
    unsigned short dest;

    dest = 50240;

    if(tetro_check(&dest) == 0)
        return (0);
    return (1);
}