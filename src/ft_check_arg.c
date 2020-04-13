#include "header.h"

void           ft_check_coord(int *tmp, int *i, char *arg, ULONG *x, char c)
{
    *tmp = *i;
    while(arg[*tmp] != c)
        if (!(arg[*tmp] >= '0' && arg[(*tmp)++] <= '9'))
            ft_errors(3);
    *x = ft_atoi(arg + (*i)) - 1;
    *i = *tmp + 1;

    //TODO Think about coordinates '0' !!!
}

void            ft_check_wlk_cmd(t_turtles **prime, int *i, char *arg)
{
    int len;

    len = *i;
    while (arg[len++] != '-')
        if (arg[len - 1] != 'g' &&
            arg[len - 1] != 'l' &&
            arg[len - 1] != 'r')
            ft_errors(4);
    if (len - (*i) == 1)
            ft_errors(4);
    if (!((*prime)->walk_command = (char *)malloc(sizeof(char) * (len - *i))))
        ft_errors(999);
    len = 0;
    while (arg[*i] != '-')
        (*prime)->walk_command[len++] = arg[(*i)++];
    (*prime)->walk_command[*i] = '\0';
    (*i)++;
}

int             ft_check_x_y(t_turtles **prime, int *i, char *arg)
{
    ULONG   x;
    ULONG   y;
    int     tmp;

    ft_check_coord(&tmp, i, arg, &x, ':');
    ft_check_coord(&tmp, i, arg, &y, '-');
    (*prime)->location = (x << 32 | y);
    return (0);
}

void            ft_turtle_way(t_turtles **prime, char *arg)
{
    if      (arg[0] == 'r')
        (*prime)->way = 1;
    else if (arg[0] == 'u')
        (*prime)->way = 2;
    else if (arg[0] == 'l')
        (*prime)->way = 4;
    else if (arg[0] == 'd')
        (*prime)->way = 8;
}

void            ft_check_name(t_turtles **prime, int i, char *arg)
{
    int len;

    len = i;
    while (arg[len++])
        if (!((arg[len - 1] >= 'a' && arg[len - 1] <= 'z') ||
              (arg[len - 1] >= 'A' && arg[len - 1] <= 'Z')) )
            ft_errors(5);
    if (len - i == 1)
            ft_errors(5);
    if (!((*prime)->name = (char *)malloc(sizeof(char) * (len - i))))
        ft_errors(999);
    len = 0;
    while (arg[i])
        (*prime)->name[len++] = arg[i++];
    (*prime)->name[i] = '\0';
}
int             ft_is_beg_turtl(char *arg)
{
    if ((arg[0] == 'l' && arg[1] == ':') ||
        (arg[0] == 'r' && arg[1] == ':') ||
        (arg[0] == 'u' && arg[1] == ':') ||
        (arg[0] == 'd' && arg[1] == ':'))
        return (1);
    return (0);
}

void            ft_create_turtl(t_turtles **prime)
{
        if (!((*prime) = (t_turtles *)malloc(sizeof(t_turtles) * 1)))
            ft_errors(999);
        (*prime)->next = NULL;
}

int             ft_check_turtle(char *arg, t_turtles **prime)
{
    int         i;

    i = 2;
    if (ft_is_beg_turtl(arg))
    {
        ft_create_turtl(prime);
        ft_turtle_way(prime, arg);
        ft_check_x_y(prime, &i, arg);
        ft_check_wlk_cmd(prime, &i, arg);
        ft_check_name(prime, i, arg);

        /*delete*/
        printf("Name of the turtle           = %s\n", (*prime)->name);
        printf("Where is the turt watch      = %d\n", (*prime)->way);
        printf("The number of turtule        = %d\n", (*prime)->num);
        printf("The walk-command is          = %s\n", (*prime)->walk_command);
        printf("The coordinates of Turtle    = %lu:%lu\n\n", (*prime)->location >> 32, (*prime)->location << 32 >> 32);
        
    }
    else if (arg[1] == ':')
        ft_errors(6);
    else
        return (0);
    return (1);
}

void            ft_check_arg(int argc, char *argv[],
                            t_turtles **prime, ULONG *map)
{
    int i;

    i = 1;
    while (argv[i])
    {
        if (ft_check_turtle(argv[i], prime))
        {
            i++;
            continue;
        }
        if (argc || *map)
        {
        }
        i++;
    }
}
