#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
/*delete*/
#include <stdio.h>

# define ERR            "Error, "
# define MASK           4294967295
# define STANDART_MAP   ((ULONG)30 << 32 | (ULONG)30)
# define MAX_UL         18446744073709551615UL
# define ANTI_MASKA     18446744069414584320UL

typedef unsigned long ULONG;

struct         s_turtles
{
    struct s_turtles    *next;
    ULONG               location;
    char                *walk_command;
    char                *name;
    char                way;
    char                num;
};

typedef struct s_turtles    t_turtles;

char            **ft_create_map(ULONG x, ULONG y, ULONG cucumber[][2]);
void            ft_winner(t_turtles *prime, char num);
void			*ft_memset(void *memptr, int val, size_t num);
void            ft_check_arg(int argc, char **argv, t_turtles **prime, ULONG *map, ULONG cuc[][2]);
void            ft_print_map(char **map);
void            ft_dummy_turtles(t_turtles *prime, ULONG map, ULONG cuc[][2]);
void            ft_errors(int num_of_err);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int         	ft_strlen(char *str);
int             ft_atoi(char *str);

#endif
