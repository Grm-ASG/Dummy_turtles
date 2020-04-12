#ifndef HEADER_H
# define HEADER_H

/*delete*/
#include <stdio.h>

# define CUCU_I     (cucumber >> 33) 
# define CUCU_J     (cucumber << 32 >> 32)
# define ERR        "Error, "
typedef unsigned long ULONG;

# include <stdlib.h>

char            **ft_create_map(ULONG x, ULONG y, ULONG cucumber);
void            ft_print_map(char **map);
void            ft_turtles(int argc, char *argv[]);
void            ft_errors(int num_of_err, char **map);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int         	ft_strlen(char *str);

#endif
