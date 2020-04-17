#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

# define RIGHT          1
# define UP             2
# define LEFT           4
# define DOWN           8
# define DELAY          500000
# define MAX_TURNS      1000
# define TURT           prime
# define TURT_X         prime->turt_x
# define TURT_X_DTP     prime->turt_dtp_x
# define TURT_X_LAST    prime->turt_x_last
# define TURT_Y         prime->turt_y
# define TURT_Y_DTP     prime->turt_dtp_y
# define TURT_Y_LAST    prime->turt_y_last
# define TURT_WAY       prime->way
# define TURT_NUM       prime->num
# define TURT_NAME      prime->name
# define TURT_NEXT      prime->next
# define TURT_STUN      prime->stunned
# define TURT_WALK_COM  prime->walk_command
# define BLANK          '.'
# define CRASH          '!'
# define STUNNED        '@'
# define ERR            "Error, "
# define STD_MAP        30
# define STD_CUC        15

typedef unsigned int UNS_TYPE;
typedef struct s_turtles    t_turtles;

struct         s_turtles
{
    t_turtles    *next;
    UNS_TYPE     turt_x;
    UNS_TYPE     turt_dtp_x;
    UNS_TYPE     turt_x_last;
    UNS_TYPE     turt_y;
    UNS_TYPE     turt_dtp_y;
    UNS_TYPE     turt_y_last;
    char         *walk_command;
    char         *name;
    char         way;
    char         num;
    char         stunned;
};

char            **ft_create_map(UNS_TYPE x, UNS_TYPE y, UNS_TYPE cucumber[][2], t_turtles *TURT);
void            ft_check_arg(char **argv, t_turtles **prime, UNS_TYPE map[][2], UNS_TYPE cuc[][2], char fl_l[][5]);
void            ft_dummy_turtles(t_turtles *prime, UNS_TYPE map[2], UNS_TYPE cuc[][2], char flags_arr[5]);
void            ft_winner(t_turtles *prime, char num);
void            ft_errors(int num_of_err);
void            ft_print_map(char **map);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void		    ft_putnbr(int nb);
int 			ft_strcmp(char *s1, char *s2);
int         	ft_strlen(char *str);
int             ft_atoi(char *str);

#endif
