/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 12:10:09 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/06 12:21:30 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	uint16_t	*map;
	t_list		*tetros;
	size_t		mapsize;
	int			fd;
	size_t		count;

	tetros = NULL;
	fd = 0;
	if (argc != 2)
		return (ft_error("usage: source_file"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("error"));
	count = 0;
	map = (uint16_t *)malloc(sizeof(uint16_t) * 16);
	ft_bzero(map, sizeof(uint16_t) * 16);
	if (read_input(fd, &tetros, &count) < 0)
		return (0);
	mapsize = checker(map, &tetros, count);
	mapsize = solver(map, &tetros, mapsize);
	print_solution(&tetros, mapsize);
	free(map);
	free_list(&tetros);
	return (0);
}
