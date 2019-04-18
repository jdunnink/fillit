
#include "libft.h"
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

void		get_masks(unsigned short *top_row, unsigned short *left_col, size_t size, size_t row_size)
{
	size_t i;

	i = 1;
	while (i <= row_size)
	{
		*top_row |= 1 << (size - i);
		i++;
	}
    printf("TOPROW%s\n", ft_itoa_base(*top_row, 2));
	i = 1;
	while (i <= size)
	{
		if (i % row_size == 0)
			*left_col |= (1 << i);
		i++;
	}
    printf("LEFTCOL%s\n", ft_itoa_base(*left_col, 2));

}

void		tetro_translate(unsigned short *dest, size_t size, size_t row_size)
{
	unsigned short top_row;
	unsigned short left_col;

    top_row = 0;
    left_col = 0;
	get_masks(&top_row, &left_col, size, row_size);
	while (~(top_row ^ *dest) == 0)
		*dest = *dest << row_size;
	while (~(left_col ^ *dest) == 0)
		*dest = *dest << 1;
}

int main(void)
{
    char *str1 = "....";
    char *str2 = "....";
    char *str3 = "##..";
    char *str4 = "##..";

    unsigned short dest = 0;


    to_bits(str1, &dest, 0);
 //   printf("%s, %zu\n", ft_itoa_base(dest, 2), ft_strlen(ft_itoa_base(dest, 2)));
    to_bits(str2, &dest, 1);
//    printf("%s\n", ft_itoa_base(dest, 2));
    to_bits(str3, &dest, 2);
//    printf("%s\n", ft_itoa_base(dest, 2));
    to_bits(str4, &dest, 3);
    printf("%s\n", ft_itoa_base(dest, 2));
    tetro_translate(&dest, 16, 4);
    printf("%s\n", ft_itoa_base(dest, 2));
    return (0);
}


