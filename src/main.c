#include "header.h"

int			main(int argc, char **argv)
{
    t_turtles   *prime;
    ULONG       map_coordinates;

    prime = NULL;
    if (argc == 1)
        ft_errors(1);
    else
    {
        ft_check_arg(argc, argv, &prime, &map_coordinates);
        ft_dummy_turtles(argc, argv, prime, map_coordinates);
    }
	return (0);
}
