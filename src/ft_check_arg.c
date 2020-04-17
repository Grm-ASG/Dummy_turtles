#include "header.h"

void           ft_check_coord(int *tmp, int *i, char *arg, USHORT *x, char c)
{
    *tmp = *i;
    while(arg[*tmp] != c)
    {
        if (!(arg[*tmp] >= '0' && arg[*tmp] <= '9'))
            ft_errors(3);
        ++(*tmp);
    }
    *x = ft_atoi(arg + (*i));
    *i = *tmp + 1;
}

void            ft_check_wlk_cmd(t_turtles **TURT, int *i, char *arg)
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
    if (!((*TURT)->walk_command = (char *)malloc(sizeof(char) * (len - *i))))
        ft_errors(999);
    len = 0;
    while (arg[*i] != '-')
        (*TURT)->walk_command[len++] = arg[(*i)++];
    (*TURT)->walk_command[*i] = '\0';
    (*i)++;
}

void             ft_check_x_y(t_turtles **TURT, int *i, char *arg)
{
    USHORT   x;
    USHORT   y;
    int     tmp;

    ft_check_coord(&tmp, i, arg, &x, ':');
    ft_check_coord(&tmp, i, arg, &y, '-');
    (*TURT)->turt_x = x;
    (*TURT)->turt_y = y;
}

void            ft_turtle_way(t_turtles **TURT, char *arg)
{
    if      (arg[0] == 'r')
        (*TURT)->way = RIGHT;
    else if (arg[0] == 'u')
        (*TURT)->way = UP;
    else if (arg[0] == 'l')
        (*TURT)->way = LEFT;
    else if (arg[0] == 'd')
        (*TURT)->way = DOWN;
}

void            ft_check_name(t_turtles **TURT, int i, char *arg)
{
    int len;

    len = i;
    if (arg[len] == '\0')
        ft_errors(15);
    while (arg[len++])
        if (!((arg[len - 1] >= 'a' && arg[len - 1] <= 'z') ||
              (arg[len - 1] >= 'A' && arg[len - 1] <= 'Z')) )
            ft_errors(5);
    if (len - i == 1)
            ft_errors(5);
    if (!((*TURT)->name = (char *)malloc(sizeof(char) * (len - i))))
        ft_errors(999);
    len = 0;
    while (arg[i])
        (*TURT)->name[len++] = arg[i++];
    (*TURT)->name[i] = '\0';
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

void            ft_create_turtl(t_turtles **TURT, int i, char *arg)
{
    t_turtles *tmp;
    t_turtles *tmp2;

    tmp = *TURT;
    tmp2 = tmp;

    if (!((*TURT) = (t_turtles *)malloc(sizeof(t_turtles) * 1)))
        ft_errors(999);
    (*TURT)->next = NULL;

    ft_turtle_way(TURT, arg);
    ft_check_x_y(TURT, &i, arg);
    ft_check_wlk_cmd(TURT, &i, arg);
    ft_check_name(TURT, i, arg);
    (*TURT)->stunned = 0;

    if (tmp == NULL)
        (*TURT)->num = 1;

    if (tmp != NULL)
    {
        while (tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = (*TURT);
        (*TURT)->num = tmp2->num + 1;
        if (tmp2->num > 9)
            ft_errors(99);
        (*TURT) = tmp;
    }
}

void             ft_check_turtle(char *arg, t_turtles **TURT, int *l, int *q)
{
    int         i;
    int         j;
    int         k;

    *q += 1;
    i = 2;
    j = 2;
    k = 0;
    if (ft_is_beg_turtl(arg))
        ft_create_turtl(TURT, i, arg);
    else if (arg[1] == ':')
    {
        while (arg[j++])
            if (arg[j - 1] == '-')
                k++;
        if (k == 2)
            ft_errors(6);
        else
            ft_errors(11);
    }
    else
        return ;
    *l += 1;

}

void            ft_flag(char **argv, USHORT map[][2], int *i, int *j, USHORT cuc[][2], char fl_s[][5])
{
    USHORT   x;
    USHORT   y;
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
        if ((*fl_s)[0] != 0)
            ft_errors(16);
        (*fl_s)[0] = 1;
        tmp2 = *i;
        *i = 0;
        if (argv[tmp2 + 1] == NULL)
            ft_errors(19);
        ft_check_coord(&tmp, i, argv[tmp2 + 1], &x, ':');
        ft_check_coord(&tmp, i, argv[tmp2 + 1], &y, '\0');
        if (x == 0 || y == 0)
            ft_errors(9);
        *i = tmp2 + 2;
        map[0][0] = x;
        map[0][1] = y;
        /* If there is no flag "-l" -> set cucumber *
         * coordinates at the half of the map       */
        if (!(*fl_s)[1])
        {
            (*cuc)[0] = (*map)[0] & 1 ? (*map)[0] >> 1 : ((*map)[0] >> 1) - 1;
            (*cuc)[1] = (*map)[1] & 1 ? (*map)[1] >> 1 : ((*map)[1] >> 1) - 1;
        }
        *j += 2;
    }
    else if (argv[*i][1] == 'l')
    {
        if ((*fl_s)[1] != 0)
            ft_errors(16);
        (*fl_s)[1] = 1;
        tmp2 = *i;
        *i = 0;
        if (argv[tmp2 + 1] == NULL)
            ft_errors(19);
        ft_check_coord(&tmp, i, argv[tmp2 + 1], &x, ':');
        ft_check_coord(&tmp, i, argv[tmp2 + 1], &y, '\0');
        if (x == 0 || y == 0)
            ft_errors(9);
        *i = tmp2 + 2;
        (*cuc)[0] = x - 1;
        (*cuc)[1] = y - 1;
        *j += 2;
    }
    else if (argv[*i][1] == 'a')
    {
        if ((*fl_s)[2] != 0)
            ft_errors(16);
        (*fl_s)[2] = 1;
        *i += 1;
        *j += 1;
    }
    else if (argv[*i][1] == 'k')
    {
        if ((*fl_s)[3] != 0)
            ft_errors(16);
        (*fl_s)[3] = 1;
        *i += 1;
        *j += 1;
    }
    else if (argv[*i][1] == 'i')
    {
        if ((*fl_s)[4] != 0)
            ft_errors(16);
        (*fl_s)[4] = 1;
        *i += 1;
        *j += 1;
    }
}

void            ft_check_turtle_in_the_map(t_turtles *TURT, USHORT map[][2], USHORT cuc[][2])
{
    while (TURT)
    {
        if (TURT_X > *map[0] ||
            TURT_Y > *map[1])
            ft_errors(13);
        if ((TURT_X - 1 == (*cuc)[0]) &&
            (TURT_Y - 1 == (*cuc)[1]))
            ft_winner(TURT, TURT->num);
        TURT = TURT_NEXT;
    }
}

void            ft_check_arg(char **argv, t_turtles **TURT, USHORT map[][2], USHORT cuc[][2], char fl_s[][5])
{
    int     j;
    int     i;

    i = 1;
    j = 1;
    while (argv[i])
        if (argv[i][0] == '-')
            ft_flag(argv, map, &i, &j, cuc, fl_s);
        else
            ft_check_turtle(argv[i], TURT, &j, &i);

    if (*TURT == NULL)
        ft_errors(14);
    if (i != j)
        ft_errors(12);
    if (((*cuc)[0] + 1) > (*map)[0] ||
        ((*cuc)[1] + 1) > (*map)[1] )
        ft_errors(10);
    ft_check_turtle_in_the_map(*TURT, map, cuc);
}
