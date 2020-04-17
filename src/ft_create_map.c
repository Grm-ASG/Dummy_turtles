#include "header.h"

char            **ft_create_map(USHORT columns, USHORT rows, USHORT cuc[][2], t_turtles *TURT)
{
    char    **map;
    USHORT  i;
    USHORT  j;

    i = - 1;
    if (!(map = (char **)malloc(sizeof(char *) * (columns + 1))))
        return (NULL);

    while (++i < columns)
        if (!(map[i] = (char *)malloc(sizeof(char) * (rows + 1))))
            return (NULL);
    map[columns] = '\0';
    i = -1;
    while (map[++i])
    {
        j = -1;
        while (++j < rows)
            map[i][j] = BLANK;
        map[i][j] = '\0';
    }
    map[cuc[0][0]][cuc[0][1]] = '0';
    while (TURT)
    {
        map[TURT_X - 1][TURT_Y - 1] = TURT_NUM + 'A' - 1;
        TURT = TURT_NEXT;
    }
    return (map);
}
