
#include "fillit.h"

static int count_ones(unsigned short *tetro)
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

static int	check_connections(size_t index, size_t total_size, unsigned short *tetro)
{
	size_t i;
	int count;

	count = 0;
	i = index - 1;
	if (!((i + 1) % SIZE == 0))
	{
		if (*tetro & (1 << (i + 1)))
			count++;
	}
	if (!(i % SIZE == 0))
	{
		if (*tetro & (1 << (i - 1)))
			count++;
	}
	if (i < total_size - SIZE)
	{
		if (*tetro & (1 << (SIZE + i)))
			count++;
	}
	if (i >= SIZE)
	{
		if (*tetro & (1 << (i - SIZE)))
			count++;
	}
	return (count);
}

static int		check_edges(unsigned short *tetro, size_t total_size)
{
	unsigned short mask;
	size_t i;
	int edges;

	mask = 1U;
	edges = 0;
	i = 1;
	while (i <= total_size)
	{
		if (mask & *tetro)
			edges += check_connections(i, total_size, tetro);
		mask = (1 << i);
		i++;
	}
	if (edges > 5)
		return (1);
	return (0);
}

int		validate_tetro(unsigned short *tetro, size_t total_size)
{
	if (count_ones(tetro) != 4)
		return (ft_error("Too many blocks in tetromino"));
	if (!check_edges(tetro, total_size))
		return (ft_error("Invalid tetromino shape found"));
	return (1);
}