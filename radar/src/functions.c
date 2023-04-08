/*
** EPITECH PROJECT, 2022
** B-MUL-100-TLS-1-1-myradar-samy.nasset
** File description:
** functions.c
*/

#include "../radar.h"

int get_plane(struct game *game)
{
    int a = 0;

    for (int i = 0; game->buffer[i] != '\0'; i++) {
        if (game->buffer[i] == 'A')
            a++;
    }
    return a;
}

int get_tower(struct game *game)
{
    int t = 0;

    for (int i = 0; game->buffer[i] != '\0'; i++) {
        if (game->buffer[i] == 'T')
            t++;
    }
    return t;
}

void create_plane(struct plane *plane, struct game *game)
{
    int nb_p = 0;
    int pos_p = 0;

    for (; game->buffer[pos_p] != '\0'; pos_p++) {
        if (game->buffer[pos_p] == 'A') {
            plane[nb_p].plane_sprite = sfSprite_create();
            plane[nb_p].plane_texture =
            sfTexture_createFromFile("./img/plane.png", NULL);
            get_details_p(game, plane, pos_p, nb_p);
            sfSprite_setTexture(plane[nb_p].plane_sprite,
            plane[nb_p].plane_texture, sfFalse);
            sfVector2f start_p = {plane[nb_p].start_x, plane[nb_p].start_y};
            sfSprite_setPosition(plane[nb_p].plane_sprite, start_p);
            nb_p++;
        }
    }
}

void create_tower(struct tower *tower, struct game *game)
{
    int pos_t = 0;
    int nb_t = 0;

    for (; game->buffer[pos_t] != '\0'; pos_t++) {
        if (game->buffer[pos_t] == 'T') {
            tower[nb_t].tower_sprite = sfSprite_create();
            tower[nb_t].tower_texture =
            sfTexture_createFromFile("./img/tower.png", NULL);
            get_details_t(game, tower, pos_t, nb_t);
            sfSprite_setTexture(tower[nb_t].tower_sprite,
            tower[nb_t].tower_texture, sfFalse);
            sfVector2f start_t = {tower[nb_t].x, tower[nb_t].y};
            sfSprite_setPosition(tower[nb_t].tower_sprite, start_t);
            nb_t++;
        }
    }
}

sfVector2f vector_direction(struct plane *plane, int nb_p)
{
    float d_x = 0;
    float d_y = 0;
    float abs_x = 0;
    float abs_y = 0;
    float vect_x = 0;
    float vect_y = 0;

    d_x = plane[nb_p].end_x - plane[nb_p].start_x;
    d_y = plane[nb_p].end_y - plane[nb_p].start_y;
    abs_x = fabs(d_x);
    abs_y = fabs(d_y);
    vect_x = d_x * plane[nb_p].speed / (abs_x + abs_y);
    vect_y = d_y * plane[nb_p].speed / (abs_x + abs_y);

    sfVector2f vector = {vect_x, vect_y};
    return vector;
}
