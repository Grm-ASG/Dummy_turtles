#include "header.h"

void            ft_dummy_turtles(int argc, char *argv[], t_turtles *prime, ULONG map_coordinates)
{
    ULONG   cucumber;
    char    **map;
    ULONG   x;
    ULONG   y;

    if (map_coordinates)
    {
    }
    x = 7;
    y = 8;
    /*  here I put the "X:Y" coordinates in the cucumber variable
     *  and if 'y' is even number i do some manipulates with bits
     */
    cucumber = (x << 32 | y >> 1) ;
    printf("cucu_x = %lu\ncucu_y = %lu\n", prime->location >> 33, prime->location << 32 >> 32);
    if (!(map = ft_create_map(x, y, cucumber)))
            ft_errors(999);
    ft_print_map(map);

    prime->num = 1;

    if (argc)
    {
    }
    if (argv[0][0])
    {
    }
}
