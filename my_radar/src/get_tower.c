/*
** EPITECH PROJECT, 2022
** B-MUL-100-TLS-1-1-myradar-samy.nasset
** File description:
** get_tower.c
*/

#include "../radar.h"

void get_details_t(struct game *game, struct tower *tower, int pos_t, int nb_t)
{
    int len = 0;

    pos_t++;
    pos_t = space(game, pos_t);
    tower[nb_t].x = get_nb_details_t(game, pos_t) + 46;
    len = get_len_t(game, pos_t);
    pos_t = pos_t + len;
    pos_t = space(game, pos_t);
    tower[nb_t].y = get_nb_details_t(game, pos_t) + 46;
    len = get_len_t(game, pos_t);
    pos_t = pos_t + len;
    pos_t = space(game, pos_t);
    tower[nb_t].radius = get_nb_details_t(game, pos_t) * 1920 / 100;
    len = get_len_t(game, pos_t);
    pos_t = pos_t + len;
}

int get_nb_details_t(struct game *game, int pos_t)
{
    int nb = 0;

    while (game->buffer[pos_t] != ' ' &&
    game->buffer[pos_t] != '\n' &&
    game->buffer[pos_t] != '\t') {
        nb = nb * 10;
        nb = nb + (game->buffer[pos_t] - '0');
        pos_t++;
    }
    return nb;
}

int get_len_t(struct game *game, int pos_t)
{
    int nb = 0;
    int len = 0;

    while (game->buffer[pos_t] != ' ' &&
    game->buffer[pos_t] != '\n' &&
    game->buffer[pos_t] != '\t') {
        nb = nb * 10;
        nb = nb + (game->buffer[pos_t] - '0');
        pos_t++;
        len++;
    }
    return len;
}
