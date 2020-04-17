#include "header.h"

int			main(int argc, char **argv)
{
    t_turtles   *prime;
    UNS_TYPE    map_coordinates[2] = { STD_MAP, STD_MAP };
    UNS_TYPE    cuc[2] = { (STD_MAP >> 1) - 1, (STD_MAP >> 1) - 1 };
    char        flags_arr[5] = { 0, 0, 0, 0, 0 };

    prime = NULL;
    if (argc == 1)
        ft_errors(1);
    ft_check_arg(argv, &prime, &map_coordinates, &cuc, &flags_arr);
    ft_dummy_turtles(prime, map_coordinates, &cuc, flags_arr);
	return (0);
}
