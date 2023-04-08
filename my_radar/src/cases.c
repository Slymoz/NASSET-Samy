/*
** EPITECH PROJECT, 2022
** B-MUL-100-TLS-1-1-myradar-samy.nasset
** File description:
** error.c
*/

#include "../radar.h"

int error(int ac, int fd, struct game *game, struct stat info)
{
    if (ac == 1) {
        my_putstr("./my_radar: bad arguments: 0 given but 84 is required\n");
        my_putstr("retry with -h\n");
        return 84;
    }
    if (ac != 2)
        return 84;
    if (fd == -1)
        return 84;
    if ((game->buffer = malloc(sizeof(char) * (info.st_size + 1))) == NULL)
        return 84;
    game->buffer[info.st_size] = '\0';
    if ((read(fd, game->buffer, info.st_size)) == -1)
        return 84;
    return 0;
}

int help(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Air traffic simulation panel\n\n");
        my_putstr("USAGE\n");
        my_putstr("./my_radar [OPTIONS] path_to_script\n");
        my_putstr("path_to_script     The path to the script file.\n\n");
        my_putstr("OPTIONS\n");
        my_putstr("-h               print the usage and quit.\n\n");
        my_putstr("USER INTERACTIONS\n");
        my_putstr("'L'              key enable/disable hitboxes and areas.\n");
        my_putstr("'S'              key enable/disable sprites.\n");
        return 1;
    }
    return 0;
}

void more_square(struct plane *plane, int i, sfRenderWindow *window)
{
    sfRectangleShape_setFillColor(plane[i].rectangle, sfTransparent);
    sfRectangleShape_setOutlineColor(plane[i].rectangle, sfMagenta);
    sfRectangleShape_setOutlineThickness(plane[i].rectangle, 3);
    sfRectangleShape_setSize(plane[i].rectangle, plane->size);
    sfRectangleShape_setPosition(plane[i].rectangle, plane[i].pos);
    sfRenderWindow_drawRectangleShape(window, plane[i].rectangle, NULL);
}
