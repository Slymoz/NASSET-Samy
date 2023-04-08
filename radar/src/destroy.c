/*
** EPITECH PROJECT, 2022
** B-MUL-100-TLS-1-1-myradar-samy.nasset
** File description:
** destroy.c
*/

#include "../radar.h"

void destroy(struct plane *plane, struct tower *tower, struct game *game)
{
    int a = get_plane(game);
    int t = get_tower(game);

    for (int i = 0; i < a; i++) {
        sfSprite_destroy(plane[i].plane_sprite);
        sfTexture_destroy(plane[i].plane_texture);
        sfRectangleShape_destroy(plane[i].rectangle);
    }
    for (int i = 0; i < t; i++) {
        sfSprite_destroy(tower[i].tower_sprite);
        sfTexture_destroy(tower[i].tower_texture);
        sfCircleShape_destroy(tower[i].circle);
    }
    free(plane);
    free(tower);
    free(game);
}

void destroy_2(struct bg *bg, sfRenderWindow *window)
{
    sfSprite_destroy(bg->bg_sprite);
    sfTexture_destroy(bg->bg_texture);
    sfRenderWindow_destroy(window);
}
