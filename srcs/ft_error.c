
#include "fillit.h"

int		ft_error(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(2, &s[i], 1);
		i++;
	}
	ft_putchar('\n');
	return (-1);
}