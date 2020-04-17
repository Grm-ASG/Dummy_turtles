#include "header.h"

void            ft_winner(t_turtles *prime, char num)
{
    ft_putstr("Here is a Winner! Congratilation, ");
    ft_putstr(TURT_NAME);
    ft_putstr("(");
    ft_putnbr(num);
    ft_putstr(")!\n");
    exit(0);
}
