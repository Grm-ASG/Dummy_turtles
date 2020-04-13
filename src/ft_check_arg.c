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

void            ft_create_turtl(t_turtles **prime, int i, char *arg)
{
    t_turtles *tmp;
    t_turtles *tmp2;

    tmp = (*prime);
    tmp2 = tmp;

    if (!((*prime) = (t_turtles *)malloc(sizeof(t_turtles) * 1)))
        ft_errors(999);
    (*prime)->next = NULL;

    ft_turtle_way(prime, arg);
    ft_check_x_y(prime, &i, arg);
    ft_check_wlk_cmd(prime, &i, arg);
    ft_check_name(prime, i, arg);

    if (tmp == NULL)
    {
        (*prime)->num = 1;
    }

    if (tmp != NULL)
    {
        while (tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = (*prime);
        (*prime)->num = tmp2->num + 1;
        (*prime) = tmp;
    }
}

int             ft_check_turtle(char *arg, t_turtles **prime)
{
    int         i;

    i = 2;
    if (ft_is_beg_turtl(arg))
        ft_create_turtl(prime, i, arg);
    else if (arg[1] == ':')
        ft_errors(6);
    else
        return (0);
    return (1);
}

        //TODO DELETE FUNCTION
void            ft_print_players(t_turtles *prime)
{
    while (prime)
    {
        printf("Name of the turtle           = %s\n", prime->name);
        printf("Where is the turt watch      = %d\n", prime->way);
        printf("The number of turtule        = %d\n", prime->num);
        printf("The walk-command is          = %s\n", prime->walk_command);
        printf("The coordinates of Turtle    = %lu:%lu\n\n", prime->location >> 32, prime->location << 32 >> 32);
        prime = prime->next;
    }
}

void            ft_flag(char **argv, ULONG *map, int *i, ULONG cuc[][2], char fl_s[][5])
{
    ULONG   x;
    ULONG   y;
    int     tmp;
    int     tmp2;

    if (argv[*i][1] != '\0' && argv[*i][2] != '\0')
        ft_errors(7);
    if (argv[*i][1] != 's' && argv[*i][1] != 'l' &&
        argv[*i][1] != 'a' && argv[*i][1] != 'k' &&
        argv[*i][1] != 'i')
        ft_errors(8);
    if (argv[*i][1] == 's')
    {
        tmp2 = *i;
        *i = 0;
        ft_check_coord(&tmp, i, argv[tmp2 + 1], &x, ':');
        ft_check_coord(&tmp, i, argv[tmp2 + 1], &y, '\0');
        *i = tmp + 1;
        *map = ((x + 1) << 32) | (y + 1);
        cuc[0][0] = *map >> 33;
        cuc[0][1] = (*map & mask) >> 1;
        fl_s[0][0] = 1;
    }
    if (map)
    {
    }
}

void            ft_check_arg(int argc, char *argv[], t_turtles **prime, ULONG *map, ULONG cuc[][2])
{
    int     i;
    char    fl_s[5] = { 0, 0, 0, 0, 0 };

    i = 1;
    while (argv[i])
    {
        if (argv[i][0] == '-')
            ft_flag(argv, map, &i, cuc, &fl_s);
        else
            (ft_check_turtle(argv[i], prime));
        i++;
    }
    if (!fl_s[0])
    {
        *map = STANDART_MAP;
        //if (!fl_l)
        cuc[0][0] = (*map >> 33);
        cuc[0][1] = (*map << 32 >> 33);
    }
    if (argc)
    {
        //TODO
    }
    // DELETE
}
