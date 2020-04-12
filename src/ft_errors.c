#include "header.h"

void            ft_errors(int num_of_err, char **map)
{
    ft_putstr(ERR);
    if (num_of_err == 1)
        ft_putstr("Oops, There is no arguments!\nTry again with them ;)\n");
    else if (num_of_err == 999)
    {
        ft_putstr("Oh, no, this is the rise of the machines!\nJoke, we just didn't get the memory, try a little bit less\n");
    }
    free(map);
    exit(num_of_err);
}

/*      Number of errors        Description
 *              1               Programm execute without arguments
 *              "oops, There is no arguments!\nTry again with them ;)\n"
 *              "seriosly? Maybe you lost something?\nThink carefully\n"
 *              "arguments, Carl! Arguments...\n"
 *
 */ 
