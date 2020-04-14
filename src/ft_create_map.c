#include "header.h"

char            **ft_create_map(ULONG columns, ULONG rows, ULONG cuc[][2])
{
    char    **map;
    ULONG   i;
    ULONG   j;

    i = 0;
    if (!(map = (char **)malloc(sizeof(char *) * (columns + 1))))
        return (NULL);

    while (i < columns)
    {
        if (!(map[i] = (char *)malloc(sizeof(char) * (rows + 1))))
            return (NULL);
        ++i;
    }
    map[columns] = '\0';
    i = 0;
    while (map[i])
    {
        j = 0;
        while (j < rows)
        {
            map[i][j] = '-';
            ++j;
        }
        map[i][j] = '\0';
        ++i;
    }
    map[cuc[0][0]][cuc[0][1]] = '0';
    return (map);
}
