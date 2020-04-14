#include "header.h"

void            ft_turtle_goes(t_turtles *prime, char **field, int a_flag, ULONG map)
{
    int     i;
    ULONG   tmp;


    i = 0;
    if (a_flag)
    {
    }
    else
    {
        while(prime)
        {
            while (prime->walk_command[i])
            {
                tmp = prime->location;
                if (prime->walk_command[i] == 'g')
                {
                    if (prime->way & 1)
                        //
                        if ((prime->location & MASK) == (map & MASK))
                            prime->location = (prime->location & ANTI_MASKA) | 1;
                        else
                            prime->location = (prime->location & ANTI_MASKA) | ((prime->location & MASK) + 1);
                    else if (prime->way & 2)
                        //
                        if (prime->location >> 32 == 1)
                            prime->location = (map & ANTI_MASKA) | (prime->location & MASK);
                        else
                            prime->location = ((((prime->location >> 32) - 1) << 32) | (prime->location & MASK));
                    else if (prime->way & 4)
                    {
                        printf("Location prime->way = 4\n");
                        printf("prime-location [%lu][%lu]\n", prime->location >> 32, prime->location & MASK);
                        if ((prime->location & MASK) == 1)
                            prime->location = ((prime->location & ANTI_MASKA) | (map & MASK));
                        else
                            prime->location = ((prime->location & ANTI_MASKA) | ((prime->location & MASK) - 1));
                    }
                    else if (prime->way & 8)
                        //
                        if ((prime->location & ANTI_MASKA) == (map & ANTI_MASKA))
                            prime->location = (((ULONG)1 << 32) | (prime->location & MASK));
                        else
                            prime->location = ((((prime->location >> 32) + 1) << 32) | (prime->location & MASK));
                    else
                        ft_errors(1000);

                }
                else if (prime->walk_command[i] == 'r')
                {
                    if (prime->way & 1)
                        prime->way = prime->way << 3;
                    else
                        prime->way = prime->way >> 1;
                }
                else if (prime->walk_command[i] == 'l')
                {
                    if (prime->way & 8)
                        prime->way = prime->way >> 3;
                    else
                        prime->way = prime->way << 1;
                }
                if (tmp != prime->location)
                    field[(tmp >> 32) - 1][(tmp & MASK) - 1] = '-';
                i++;
            }
            field[(prime->location >> 32) -1][(prime->location & MASK) - 1] = prime->num + '0';
            prime = prime->next;
        }
    }
}

void            ft_dummy_turtles(t_turtles *prime, ULONG map, ULONG cuc[][2])
{
    char    **field;
    int     i;
    int     j;

    int     a_flag = 0;

    i = 0;
    if (!(field = ft_create_map(map >> 32, map & MASK, cuc)))
            ft_errors(999);
    while (i < 1000)
    {
        ft_turtle_goes(prime, field, a_flag, map);
       // system("clear");
        printf("Hello from cicle[%d]\n", i);
        printf("Right now the turtle watches = %d\n", prime->way);
        j = 0;
        while (field[j])
        {
            ft_putstr(field[j]);
            ft_putchar('\n');
            j++;
        }
        usleep(500000);
        i++;
    }
    ft_errors(100);
    if (prime)
    {
    }
}
