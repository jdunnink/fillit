/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:38:42 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/07 10:47:36 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include "get_next_line.h"
# define SIZE 4
# include <stdint.h>

typedef struct	s_tetro
{
	uint64_t		tetro;
	uint16_t		fpt;
	unsigned char	x;
	unsigned char	y;
	size_t			order;
	size_t			width;
	size_t			height;
	t_list			*last;
	char			print;
}				t_tetro;

void			free_list(t_list **lst);
void			free_map(char **map, size_t mapsize);
void			free_tetro(char **tetro);
size_t			available_space(uint16_t *map, size_t mapsize);
int				read_input(int fd, t_list **list, size_t *count);
int				add_tetro(uint16_t tetr, size_t count, t_list **lst);
uint64_t		convert_sll(uint16_t t);
void			itocoor(int *x, int *y, size_t index, size_t size);
int				ft_error(char *s);
void			read_tetromino(char **l, uint16_t *d);
int				validate_tetro(uint16_t *tetro, size_t total_size);
void			tetro_translate (uint16_t *tetro, size_t total_size);
int				initialize_map(uint16_t **map);
int				solver(uint16_t *map, t_list **tetros, size_t map_size);
int				solve_map(uint16_t *map, t_list **tetros, size_t map_size);
int				solve_ps(t_list *curr, size_t size, uint16_t *mp, size_t i);
void			print_solution (t_list **tetros, size_t mapsize);
void			toggle_tetro(uint16_t *map, t_tetro *tetro);
int				count_ones(uint16_t *tetro);
uint64_t		convert_sll(uint16_t t);
size_t			min_mapsize(size_t num_tetros);
size_t			lst_len(t_list **lst);
#endif
