#include "header.h"

void            ft_turtles(int argc, char *argv[])
{
    ULONG   cucumber;
    char    **map;
    ULONG   x;
    ULONG   y;

    x = 5;
    y = 5;
    /*  here I put the "X:Y" coordinates in the cucumber variable
     *  and if 'y' is even number i do some manipulates with bits
     */
    cucumber = (x << 32 | y >> 1) ;
    //printf("cucu_x = %lu\ncucu_y = %lu\n", CUCU_I, CUCU_J);
    if (!(map = ft_create_map(x, y, cucumber)))
            ft_errors(999, NULL);
    ft_print_map(map);

    if (argc)
    {
    }
    if (argv[0][0])
    {
    }
}
