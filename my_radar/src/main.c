/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../radar.h"

static sfRenderWindow *create_window
(unsigned int x, unsigned int y,
unsigned int bpp, char* title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfClose, NULL));
}

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void time_elapsed(struct plane *plane, int a)
{
    int clock_i = 0;

    for (; clock_i < a; clock_i++) {
        sfVector2f final = vector_direction(plane, clock_i);
        final.x = final.x / 60;
        final.y = final.y / 60;
        sfSprite_move(plane[clock_i].plane_sprite, final);
    }
}

void window_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
        close_window(window, event);
}

int main(int ac, char **av)
{
    if (help(ac, av) == 1) return 0;
    struct plane *plane = NULL; struct tower *tower = NULL;
    struct game *game = NULL; struct bg bg; struct stat info;
    int fd = 0; int a = 0; int t = 0; sfEvent event;
    sfRenderWindow *window = create_window(1920, 1080, 32, "My Radar");
    sfRenderWindow_setFramerateLimit(window, 60);

    game = malloc(sizeof(struct game) + 1);
    fd = open(av[1], O_RDONLY); stat(av[1], &info);
    if (error(ac, fd, game, info) == 84) return 84;
    a = get_plane(game); t = get_tower(game);
    plane = malloc(sizeof(struct plane) * a);
    tower = malloc(sizeof(struct tower) * t);
    create_inits(plane, game, tower, &bg);
    while (sfRenderWindow_isOpen(window)) {
        window_op(window, &bg); time_elapsed(plane, a);
        display_a(plane, window, a); display_t(tower, window, t);
        window_events(window, event);
    }
    destroy(plane, tower, game); destroy_2(&bg, window);
}
