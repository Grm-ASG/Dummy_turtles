#include "header.h"

int			main(int argc, char **argv)
{
    t_turtles   *prime;
    ULONG       map_coordinates;
    ULONG       cuc[2];
    char        flags_arr[5] = { 0, 0, 0, 0, 0 };

    prime = NULL;
    if (argc == 1)
        ft_errors(1);
    else
    {
        ft_check_arg(argv, &prime, &map_coordinates, &cuc, &flags_arr);
        ft_dummy_turtles(prime, map_coordinates, &cuc, flags_arr);
    }
	return (0);
}
