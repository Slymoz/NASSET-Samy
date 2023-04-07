/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../my.h"

int count_n(char *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i] != '\0') {
        i++;
        if (buffer[i] == '\n')
            count++;
    }
    return count;
}

int len_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i++;
    return i;
}

int help_sokoban(int ac, char **av)
{
    if (ac != 2)
        return 0;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("     ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("     map file representing the warehouse map, ");
        my_putstr("containing '#' for walls,\n");
        my_putstr("         'P' for the player, ");
        my_putstr("'X' for boxes and 'O' for storage locations.\n");
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    char *buffer = NULL;
    char *new = NULL;
    int fd = 0;
    struct stat info;

    if (help_sokoban(ac, av) == 1) return 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1) return 84;
    stat(av[1], &info);
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    buffer[info.st_size] = '\0';
    new = malloc(sizeof(char) * (info.st_size + 1));
    new[info.st_size] = '\0';
    read(fd, buffer, info.st_size);
    if (error_buff(buffer) == 84) return 84;
    my_strcpy(new, buffer);
    window_map(buffer, new);
    free(buffer); free(new);
    close(fd);
    return 0;
}
