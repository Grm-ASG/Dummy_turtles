#include "header.h"

void            ft_dummy_turtles(t_turtles *prime, ULONG map, ULONG cuc[][2])
{
    char    **field;
    int     i;

    i = 1000;
    if (!(field = ft_create_map(map >> 32, map & mask, cuc)))
            ft_errors(999);
    ft_print_map(field);
    exit(1);

    while (i)
    {
        system("clear");
        if (prime)
        {
        }

        i--;
    }
    free (field);
    ft_errors(100);
}
