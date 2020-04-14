#include "header.h"

void            ft_winner(t_turtles *prime, char num)
{
    ft_putstr("Here is a Winner! Congratilation, ");
    ft_putstr(prime->name);
    ft_putstr("(");
    if (num == 10)
    {
        ft_putchar('1');
        ft_putchar('0');
    }
    else
        ft_putchar(prime->num + '0');
    ft_putstr(")");
    ft_putstr("!\n");
    exit(0);
}
