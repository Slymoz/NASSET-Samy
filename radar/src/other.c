/*
** EPITECH PROJECT, 2022
** B-MUL-100-TLS-1-1-myradar-samy.nasset
** File description:
** other.c
*/

#include "../radar.h"

void display_a(struct plane *plane, sfRenderWindow *window, int a)
{
    sfVector2f pos_landing = {2147483647, 2147483647};
    sfVector2f speed_p = {0, 0};

    plane->rec_p.x = 0; plane->rec_p.y = 0;
    plane->size.x = 20; plane->size.y = 20;

    for (int i = 0; i < a; i++) {
        sfRenderWindow_drawSprite(window, plane[i].plane_sprite, NULL);
        plane[i].rectangle = sfRectangleShape_create();
        plane[i].pos = sfSprite_getPosition(plane[i].plane_sprite);
        if ((plane[i].pos.x >= plane[i].end_x &&
        plane[i].pos.x <= plane[i].end_x + 10) ||
        (plane[i].pos.y >= plane[i].end_y &&
        plane[i].pos.y <= plane[i].end_y + 10)) {
            sfSprite_setPosition(plane[i].plane_sprite, pos_landing);
            sfSprite_move(plane[i].plane_sprite, speed_p);
        }
        plane->rec_p.x = plane[i].start_x; plane->rec_p.y = plane[i].start_y;
        more_square(plane, i, window);
    }
}

void display_t(struct tower *tower, sfRenderWindow *window, int t)
{
    tower->circle_t.x = 0;
    tower->circle_t.y = 0;

    for (int i = 0; i < t; i++) {
        sfRenderWindow_drawSprite(window, tower[i].tower_sprite, NULL);
        tower[i].circle = sfCircleShape_create();
        tower[i].circle_t.x = tower[i].x - tower[i].radius + 45;
        tower[i].circle_t.y = tower[i].y - tower[i].radius + 45;
        sfCircleShape_setRadius(tower[i].circle, tower[i].radius);
        sfCircleShape_setOutlineColor(tower[i].circle, sfWhite);
        sfCircleShape_setOutlineThickness(tower[i].circle, 2);
        sfCircleShape_setFillColor(tower[i].circle, sfTransparent);
        sfCircleShape_setPosition(tower[i].circle, tower[i].circle_t);
        sfRenderWindow_drawCircleShape(window, tower[i].circle, NULL);
    }
}

void create_bg(struct bg *bg)
{
    bg->bg_sprite = sfSprite_create();
    bg->bg_texture = sfTexture_createFromFile("./img/map.png", NULL);
    sfSprite_setTexture(bg->bg_sprite, bg->bg_texture, sfFalse);
}

void window_op(sfRenderWindow *window, struct bg *bg)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, bg->bg_sprite, NULL);
}

int buff_more(struct game *game, struct stat info, int fd)
{
    game->buffer[info.st_size] = '\0';
    if ((read(fd, game->buffer, info.st_size)) == -1)
        return 84;
    return 0;
}
