/*
** EPITECH PROJECT, 2022
** B-MUL-100-TLS-1-1-myradar-samy.nasset
** File description:
** get_details.c
*/

#include "../radar.h"

int get_nb_details_p(struct game *game, int pos_p)
{
    int nb = 0;

    while (game->buffer[pos_p] != ' ' &&
    game->buffer[pos_p] != '\n' &&
    game->buffer[pos_p] != '\t') {
        nb = nb * 10;
        nb = nb + (game->buffer[pos_p] - '0');
        pos_p++;
    }
    return nb;
}

int get_len_p(struct game *game, int pos_p)
{
    int nb = 0;
    int len = 0;

    while (game->buffer[pos_p] != ' ' &&
    game->buffer[pos_p] != '\n' &&
    game->buffer[pos_p] != '\t') {
        nb = nb * 10;
        nb = nb + (game->buffer[pos_p] - '0');
        pos_p++;
        len++;
    }
    return len;
}

void get_details_p(struct game *game, struct plane *plane, int pos_p, int nb_p)
{
    int len = 0;

    pos_p++; pos_p = space(game, pos_p);
    plane[nb_p].start_x = get_nb_details_p(game, pos_p);
    len = get_len_p(game, pos_p); pos_p = pos_p + len;
    pos_p = space(game, pos_p);
    plane[nb_p].start_y = get_nb_details_p(game, pos_p);
    len = get_len_p(game, pos_p); pos_p = pos_p + len;
    pos_p = space(game, pos_p);
    plane[nb_p].end_x = get_nb_details_p(game, pos_p);
    len = get_len_p(game, pos_p); pos_p = pos_p + len;
    pos_p = space(game, pos_p);
    plane[nb_p].end_y = get_nb_details_p(game, pos_p);
    len = get_len_p(game, pos_p); pos_p = pos_p + len;
    pos_p = space(game, pos_p);
    plane[nb_p].speed = get_nb_details_p(game, pos_p);
    len = get_len_p(game, pos_p); pos_p = pos_p + len;
    pos_p = space(game, pos_p);
    plane[nb_p].delay = get_nb_details_p(game, pos_p);
    len = get_len_p(game, pos_p); pos_p = pos_p + len;
}

int space(struct game *game, int i)
{
    while (game->buffer[i] == ' ' || game->buffer[i] == '\t') {
        i++;
    }
    return i;
}

void create_inits(struct plane *plane, struct game *game,
struct tower *tower, struct bg *bg)
{
    create_plane(plane, game);
    create_tower(tower, game);
    create_bg(bg);
}
