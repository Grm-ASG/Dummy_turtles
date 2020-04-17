#include "header.h"

void            ft_prime_way_r(t_turtles *TURT, char num_of_turtle)
{
    while (TURT_NUM != num_of_turtle)
        TURT = TURT_NEXT;
    {
        if (TURT_WAY & 1)
            TURT_WAY = TURT_WAY << 3;
        else
            TURT_WAY = TURT_WAY >> 1;
    }
}

void            ft_prime_way_l(t_turtles *TURT, char num_of_turtle)
{
    while (TURT_NUM != num_of_turtle)
        TURT = TURT_NEXT;
    if (TURT_WAY & 8)
        TURT_WAY = TURT_WAY >> 3;
    else
        TURT_WAY = TURT_WAY << 1;
}

        /* If flag "-a" is enabled, I am pushing the first command 
         * of the "Walk-Command" (that was used right now) at the end
         * of the line. Due to this all turtles perform one action
         * per turn                                                */
void            ft_push_command_back(t_turtles *TURT, char num_of_turtle)
{
    int     i;
    char    tmp;

    while (TURT_NUM != num_of_turtle)
        TURT = TURT_NEXT;
    if (TURT_WALK_COM[1] == '\0')
        return ;
    i = 0;
    tmp = TURT_WALK_COM[0];
    while (TURT_WALK_COM[++i])
        TURT_WALK_COM[i - 1] = TURT_WALK_COM[i];
    TURT_WALK_COM[i - 1] = tmp;
}

void            ft_print_map(char **field)
{
    short j;

    j = -1;
    system("clear");
    while (field[++j])
    {
        ft_putstr(field[j]);
        ft_putchar('\n');
    }
    ft_putchar('\n');
    usleep(DELAY);
}

void            ft_prime_command(t_turtles *TURT, char num_of_turtle, USHORT map[2])
{
    while (prime->num != num_of_turtle)
        prime = prime->next;
    if      (TURT_WAY & RIGHT)
        if (TURT_Y == map[1])
            TURT_Y = 1;
        else
            TURT_Y += 1;
    else if (TURT_WAY & UP)
        if (TURT_X == 1)
            TURT_X = map[0];
        else
            TURT_X -= 1;
    else if (TURT_WAY & LEFT)
        if (TURT_Y == 1)
            TURT_Y = map[1];
        else
            TURT_Y -= 1;
    else if (TURT_WAY & DOWN)
        if (TURT_X == map[0])
            TURT_X = 1;
        else
            TURT_X += 1;
    else
        ft_errors(1000);
}

void            ft_check_back(t_turtles *TURT, USHORT x, USHORT y)
{
    t_turtles *tmp;

    tmp = TURT;
    while (TURT)
    {
        if (x == TURT_X && y == TURT_Y)
        {
            TURT_STUN = 1;
            ft_check_back(tmp, TURT_X_LAST, TURT_Y_LAST);
        }
        TURT = TURT_NEXT;
    }
}

void            ft_check_crash(t_turtles *TURT, char **field)
{
    t_turtles   *tmp;
    t_turtles   *tmp2;


    tmp = TURT;
    while (tmp->next)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->turt_x == tmp2->turt_x &&
                tmp->turt_y == tmp2->turt_y)
            {
                tmp->stunned = 1;
                tmp2->stunned = 1;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    tmp = TURT;
    while (TURT)
    {
        if (TURT_STUN)
        {
            TURT_X_DTP = TURT_X;
            TURT_Y_DTP = TURT_Y;
            field[TURT_X - 1][TURT_Y - 1] = CRASH;
            if (!(TURT_X == TURT_X_LAST && TURT_Y == TURT_Y_LAST))
                ft_check_back(TURT, TURT_X_LAST, TURT_Y_LAST);
            TURT_X = TURT_X_LAST;
            TURT_Y = TURT_Y_LAST;
            field[TURT_X - 1][TURT_Y - 1] = STUNNED;
        }
        TURT = TURT_NEXT;
    }
}

void            ft_turtle_goes(t_turtles *TURT, char **field, USHORT map[2], char flags_arr[5])
{
    USHORT   tmp_x;
    USHORT   tmp_y;
    USHORT   i;
    t_turtles   *back_up;

    back_up = TURT;
    while (TURT)
    {
        TURT_X_LAST = TURT_X;
        TURT_Y_LAST = TURT_Y;
        tmp_x = TURT_X;
        tmp_y = TURT_Y;
        i = -1;

        if (!TURT_STUN)
        {
            if (flags_arr[2])
            {
                if (TURT_WALK_COM[0] == 'g')
                    ft_prime_command(TURT, TURT_NUM, map);
                else if (TURT_WALK_COM[0] == 'r')
                    ft_prime_way_r(TURT, TURT_NUM);
                else if (TURT_WALK_COM[0] == 'l')
                    ft_prime_way_l(TURT, TURT_NUM);
                ft_push_command_back(TURT, TURT_NUM);
            }
            else
                while (TURT_WALK_COM[++i])
                    if (TURT_WALK_COM[i] == 'g')
                        ft_prime_command(TURT, TURT_NUM, map);
                    else if (TURT_WALK_COM[i] == 'r')
                        ft_prime_way_r(TURT, TURT_NUM);
                    else if (TURT_WALK_COM[i] == 'l')
                        ft_prime_way_l(TURT, TURT_NUM);

            if (field[TURT_X - 1][TURT_Y - 1] == '0')
                ft_winner(TURT, TURT_NUM);
            if (tmp_x != TURT_X || tmp_y != TURT_Y)
                if (field[tmp_x - 1][tmp_y - 1] == TURT_NUM + 'A' - 1)
                    field[tmp_x - 1][tmp_y - 1] = BLANK;
            field[TURT_X - 1][TURT_Y - 1] = TURT_NUM + 'A' - 1;
        }
        else
        {
            if (field[TURT_X_DTP - 1][TURT_Y_DTP - 1] == CRASH)
                field[TURT_X_DTP - 1][TURT_Y_DTP - 1] = BLANK;
            TURT_STUN = 0;
            
            field[TURT_X - 1][TURT_Y - 1] = TURT_NUM + 'A' - 1;
        }
        TURT = TURT_NEXT;
    }
    if (flags_arr[3])
        ft_check_crash(back_up, field);
    if (flags_arr[4])
        ft_print_map(field);
}

void            ft_dummy_turtles(t_turtles *TURT, USHORT map[2], USHORT cuc[][2], char flags_arr[5])
{
    char    **field;
    short   i;

    i = - 1;
    if (!(field = ft_create_map(map[0], map[1], cuc, TURT)))
            ft_errors(999);
    if (flags_arr[4])
        ft_print_map(field);
    while (++i < MAX_TURNS)
        ft_turtle_goes(TURT, field, map, flags_arr);
    ft_errors(100);
}
