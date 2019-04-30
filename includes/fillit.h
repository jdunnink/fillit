
#include "libft.h"
# include "get_next_line.h"
# define SIZE 4

typedef struct s_tetro
{
    unsigned short tetro;
    size_t order;
    size_t og_index1;
    size_t pl_index1;
    size_t og_index2;
    size_t pl_index2;
    size_t og_index3;
    size_t pl_index3;
    size_t og_index4;
    size_t pl_index4;
    char print;
}              t_tetro;

typedef struct s_field
{
    unsigned long long top_left;
    unsigned long long top_right;
    unsigned long long bot_left;
    unsigned long long bot_right;
    size_t  size;
}               t_field;

int		read_input(int fd, t_list **list, size_t *count);
int		ft_error(char *s);
int		read_tetromino(int *lr, int fd, char **line, unsigned short *dst);
int		validate_tetro(unsigned short *tetro, size_t total_size);
void    tetro_translate (unsigned short *tetro, size_t total_size);
void    set_indexes(t_tetro *t);

void    print_field(t_field field);
t_field create_field(size_t total_size);
void	itocoor(int *x, int *y, size_t index, size_t size);

int solver(t_field *dest, t_list *tetros, size_t num_tetros);
int solve_pos(t_field map, t_tetro *tetro, t_field *tmp);

int lst_diff_order(t_list *tetros);
void toggle_bits(t_tetro tetro, t_field *field);

void    print_solution(t_field *field, t_list **lst);
