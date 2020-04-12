#include "header.h"

int			main(int argc, char **argv)
{
    if (argc == 1)
        ft_errors(1, NULL);
    else
    {
        ft_turtles(argc, argv);
    }
	return (0);
}
