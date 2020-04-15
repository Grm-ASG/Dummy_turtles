#include "header.h"


void            ft_prime_command(t_turtles *prime, char num_of_turtle, ULONG map)
{
    while (prime->num != num_of_turtle)
        prime = prime->next;
    if (prime->way & 1)
    {
        if ((prime->location & MASK) == (map & MASK))
            prime->location = (prime->location & ANTI_MASKA) | 1;
        else
            prime->location = (prime->location & ANTI_MASKA) | ((prime->location & MASK) + 1);
    }
    else if (prime->way & 2)
    {
        if (prime->location >> 32 == 1)
            prime->location = (map & ANTI_MASKA) | (prime->location & MASK);
        else
            prime->location = ((((prime->location >> 32) - 1) << 32) | (prime->location & MASK));
    }
    else if (prime->way & 4)
    {
        if ((prime->location & MASK) == 1)
            prime->location = ((prime->location & ANTI_MASKA) | (map & MASK));
        else
            prime->location = ((prime->location & ANTI_MASKA) | ((prime->location & MASK) - 1));
    }
    else if (prime->way & 8)
    {
        if ((prime->location & ANTI_MASKA) == (map & ANTI_MASKA))
            prime->location = (((ULONG)1 << 32) | (prime->location & MASK));
        else
            prime->location = ((((prime->location >> 32) + 1) << 32) | (prime->location & MASK));
    }
    else
        ft_errors(1000);
}


void            ft_prime_way_r(t_turtles *prime, char num_of_turtle)
{
    while (prime->num != num_of_turtle)
        prime = prime->next;
    {
        if (prime->way & 1)
            prime->way = prime->way << 3;
        else
            prime->way = prime->way >> 1;
    }
}

void            ft_prime_way_l(t_turtles *prime, char num_of_turtle)
{
    while (prime->num != num_of_turtle)
        prime = prime->next;
    if (prime->way & 8)
        prime->way = prime->way >> 3;
    else
        prime->way = prime->way << 1;
}

void            ft_move_command(t_turtles *prime, char num_of_turtle)
{
    int     i;
    char    tmp;


    while (prime->num != num_of_turtle)
        prime = prime->next;
    if (prime->walk_command[1] == '\0')
        return ;
    i = 0;
    tmp = prime->walk_command[0];
    while (prime->walk_command[++i])
        prime->walk_command[i - 1] = prime->walk_command[i];
    prime->walk_command[i - 1] = tmp;
}


void            ft_turtle_goes(t_turtles *prime, char **field, ULONG map, char flags_arr[5])
{
    int     i;
    ULONG   tmp;

    if (flags_arr[2])
    {
        while (prime)
        {
            tmp = prime->location;

            if (prime->walk_command[0] == 'g')
                ft_prime_command(prime, prime->num, map);
            else if (prime->walk_command[0] == 'r')
                ft_prime_way_r(prime, prime->num);
            else if (prime->walk_command[0] == 'l')
                ft_prime_way_l(prime, prime->num);

            ft_move_command(prime, prime->num);
            if (field[(prime->location >> 32) - 1][(prime->location & MASK) - 1] == '0')
                ft_winner(prime, prime->num);
            if (tmp != prime->location)
                field[(tmp >> 32) - 1][(tmp & MASK) - 1] = '-';
            field[(prime->location >> 32) -1][(prime->location & MASK) - 1] = prime->num + 'A' - 1;
            prime = prime->next;
        }
    }
    else
    {
        while (prime)
        {
            tmp = prime->location;
            i = 0;
            while (prime->walk_command[i++])
                if (prime->walk_command[i - 1] == 'g')
                    ft_prime_command(prime, prime->num, map);
                else if (prime->walk_command[i - 1] == 'r')
                    ft_prime_way_r(prime, prime->num);
                else if (prime->walk_command[i - 1] == 'l')
                    ft_prime_way_l(prime, prime->num);
            if (field[(prime->location >> 32) - 1][(prime->location & MASK) - 1] == '0')
                ft_winner(prime, prime->num);
            if (tmp != prime->location)
                field[(tmp >> 32) - 1][(tmp & MASK) - 1] = '-';
            field[(prime->location >> 32) -1][(prime->location & MASK) - 1] = prime->num + 'A' - 1;
            prime = prime->next;
        }
    }
}

void            ft_is_eat_cuc(t_turtles *prime, ULONG cuc[][2])
{
    while (prime)
    {
        if (((prime->location >> 32) - 1 == cuc[0][0]) &&
            ((prime->location & MASK) - 1 == cuc[0][1]))
            ft_winner(prime, prime->num);
        prime = prime->next;
    }
}

void            ft_dummy_turtles(t_turtles *prime, ULONG map, ULONG cuc[][2], char flags_arr[5])
{
    char    **field;
    int     i;
    int     j;

    i = 0;
    if (!(field = ft_create_map(map >> 32, map & MASK, cuc)))
            ft_errors(999);
    while (i < 1000)
    {
        ft_is_eat_cuc(prime, cuc);
        ft_turtle_goes(prime, field, map, flags_arr);
        j = 0;
        if (flags_arr[4])
        {
            system("clear");
            while (field[j])
            {
                ft_putstr(field[j]);
                ft_putchar('\n');
                j++;
            }
            usleep(200000);
        }
        i++;
    }
    ft_errors(100);
    if (prime)
    {
    }
}
