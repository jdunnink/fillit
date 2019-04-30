
#include "fillit.h"

int main(int argc, char **argv)
{
    t_field dest;
    t_list *tetros;

    int fd;
    int res;
    size_t count;

    tetros = NULL;
    dest = create_field(256);
    res = 0;
    fd = 0;
    count = 0;
    if (argc != 2)
        return (ft_error("Invalid number of input files"));
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
		return (ft_error("File could not be opened"));
	res	= read_input(fd, &tetros, &count);
	if (res != 0)
		return (-1);
    res = solver(&dest, tetros, count);
	print_solution(&dest, &tetros);
    return (0);
}
