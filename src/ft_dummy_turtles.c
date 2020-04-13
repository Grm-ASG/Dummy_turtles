#include "header.h"

void            ft_dummy_turtles(t_turtles *prime, ULONG map, ULONG cuc[][2])
{
    char    **field;

    if (!(field = ft_create_map(map >> 32, map & mask, cuc)))
            ft_errors(999);
    ft_print_map(field);

    if (prime)
    {
    }
}
