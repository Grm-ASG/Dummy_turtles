#include "header.h"

void            ft_errors(int num_of_err)
{
    ft_putstr(ERR);
    if (num_of_err == 1)
    {
        ft_putstr("Oops, There is no arguments!\nTry again with them ;)\n");
    }
    else if (num_of_err == 2)
    {
        ft_putstr("Oh shit, we lost part of the turtle!\nCheck the correct data for turtles\n");
    }
    else if (num_of_err == 3)
    {
        ft_putstr("Wrong number of coordinates. Check it\n"); 
    }
    else if (num_of_err == 4)
    {
        ft_putstr("Command for turtle is incorrect\n"); 
    }
    else if (num_of_err == 5)
    {
        ft_putstr("Incorrect Name of the turtle\n"); 
    }
    else if (num_of_err == 6)
    {
        ft_putstr("Incorrect way of watcing of the turtle\n"); 
    }
    else if (num_of_err == 7)
    {
        ft_putstr("Too mach arguments, try use 1 in 1 case\n"); 
    }
    else if (num_of_err == 8)
    {
        ft_putstr("Sorry, I don't know this flag. Try use it 5 minuts later, I'll Google it for now\n"); 
    }
    else if (num_of_err == 9)
    {
        ft_putstr("Check the coordinates, maybe there is 0?\n"); 
    }
    else if (num_of_err == 10)
    {
        ft_putstr("Oh no, cucumber in other university, try too put it in our\n"); 
    }
    else if (num_of_err == 11)
    {
        ft_putstr("I don't know this argument...\n"); 
    }
    else if (num_of_err == 12)
    {
        ft_putstr("Some arguments is invalid, pls check them all\n"); 
    }
    else if (num_of_err == 13)
    {
        ft_putstr("Some turtle come from another galaxy, check it\n"); 
    }
    else if (num_of_err == 14)
    {
        ft_putstr("No way, how we gona play if there is no any players? Minimal number of turtles = 1\n"); 
    }
    else if (num_of_err == 15)
    {
        ft_putstr("One of your turtles without name. Think about it, noname\n"); 
    }
    else if (num_of_err == 16)
    {
        ft_putstr("Double notification of flags\n"); 
    }
    else if (num_of_err == 19)
    {
        ft_putstr("The last argument is invalid, check coordinates for this flag\n"); 
    }
    else if (num_of_err == 99)
    {
        ft_putstr("Oops, to much turtles! Only 10 can play this game\n");
    }
    else if (num_of_err == 999)
    {
        ft_putstr("Oh, no, this is the rise of the machines!\nJoke, we just didn't get the memory, try a little bit less\n");
    }
    else if (num_of_err == 100)
    {
        ft_putstr("Of course we could do it 1 bilion years, but after 1000 steps nobody can't took cucumber, oh sweet CUUUCUMBER!\n");
    }
    else if (num_of_err == 1000)
    {
        ft_putstr("No way! If it happens, send me this case\n");
    }
    exit(num_of_err);
}
