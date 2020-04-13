#include "header.h"

int			main(int argc, char **argv)
{
    t_turtles   *prime;
    ULONG       map_coordinates;
    ULONG       cuc[2];

    prime = NULL;
    if (argc == 1)
        ft_errors(1);
    else
    {
        ft_check_arg(argc, argv, &prime, &map_coordinates, &cuc);
        ft_dummy_turtles(prime, map_coordinates, &cuc);
    }
	return (0);
}
