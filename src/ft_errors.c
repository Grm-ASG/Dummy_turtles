#include "header.h"

void            ft_errors(int num_of_err)
{
    ft_putstr(ERR);
    if (num_of_err == 1)
        ft_putstr("Oops, There is no arguments!\nTry again with them ;)\n");
    else if (num_of_err == 2)
    {
        ft_putstr("Oh shit, we lost part of the turtle!\nCheck the correct data for turtles\n");
    }
    else if (num_of_err == 3)
    {
        ft_putstr("Wrong number of X coordinate\n"); //TODO
    }
    else if (num_of_err == 4)
    {
        ft_putstr("Command for turtle is incorrect\n"); //TODO
    }
    else if (num_of_err == 5)
    {
        ft_putstr("Incorrect Name of the turtle\n"); //TODO
    }
    else if (num_of_err == 6)
    {
        ft_putstr("Incorrect way of watcing of the turtle\n"); //TODO
    }
    else if (num_of_err == 7)
    {
        ft_putstr("Too mach arguments, try use 1 in 1 case\n"); //TODO
    }
    else if (num_of_err == 8)
    {
        ft_putstr("Sorry, I don't know this flag. Try use it 5 minuts later, I'll Google it for now\n"); //TODO
    }
    else if (num_of_err == 9)
    {
        ft_putstr("Check the coordinates, maybe there is 0?\n"); //TODO
    }
    else if (num_of_err == 10)
    {
        ft_putstr("Oh no, cucumber in other university, try too put it in our\n"); //TODO
    }
    else if (num_of_err == 11)
    {
        ft_putstr("I don't know this argument...\n"); //TODO
    }
    else if (num_of_err == 12)
    {
        ft_putstr("Some arguments is invalid, pls check them all\n"); //TODO
    }
    else if (num_of_err == 999)
    {
        ft_putstr("Oh, no, this is the rise of the machines!\nJoke, we just didn't get the memory, try a little bit less\n");
    }
    exit(num_of_err);
}

/*      Number of errors        Description
 *              1               Programm execute without arguments
 *              "oops, There is no arguments!\nTry again with them ;)\n"
 *              "seriosly? Maybe you lost something?\nThink carefully\n"
 *              "arguments, Carl! Arguments...\n"
 *
 */ 
