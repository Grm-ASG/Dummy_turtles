#include "header.h"

void            ft_print_map(char **map)
{
    int i;

    while (map[i])
    {
        ft_putstr(map[i]);
        ft_putchar('\n');
        i++;
    }
}
