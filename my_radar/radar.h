/*
** EPITECH PROJECT, 2022
** radar
** File description:
** radar.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#ifndef RADAR_H
    #define RADAR_H

struct plane {
    sfSprite *plane_sprite;
    sfTexture *plane_texture;
    sfVector2f movement;
    float start_x;
    float start_y;
    float end_x;
    float end_y;
    int speed;
    int delay;
    sfRectangleShape *rectangle;
    sfVector2f rec_p;
    sfVector2f size;
    sfVector2f pos;
};

struct tower {
    sfSprite *tower_sprite;
    sfTexture *tower_texture;
    int x;
    int y;
    float radius;
    sfCircleShape *circle;
    sfVector2f circle_t;
};

struct bg {
    sfSprite *bg_sprite;
    sfTexture *bg_texture;
};

struct game {
    char *buffer;
};

void my_putchar(char c);
int my_putstr(char const *str);
int my_getnbr(char const *str);
void close_window(sfRenderWindow *window, sfEvent event);
void time_elapsed(struct plane *plane, int a);
int get_plane(struct game *game);
int get_tower(struct game *game);
void create_plane(struct plane *plane, struct game *game);
void create_tower(struct tower *tower, struct game *game);
void create_bg(struct bg *bg);
void window_op(sfRenderWindow *window, struct bg *bg);
void display_a(struct plane *plane, sfRenderWindow *window, int a);
void display_t(struct tower *tower, sfRenderWindow *window, int t);
int space(struct game *game, int i);
int get_nb_details(struct game *game, int pos_p);
int get_nb_details_p(struct game *game, int pos_p);
int get_len_p(struct game *game, int pos_p);
void get_details_p(struct game *game, struct plane *plane, int pos_p, int nb_b);
void get_details_t(struct game *game, struct tower *tower, int pos_t, int nb_t);
int get_nb_details_t(struct game *game, int pos_t);
int get_len_t(struct game *game, int pos_t);
int buff_more(struct game *game, struct stat info, int fd);
void destroy(struct plane *plane, struct tower *tower, struct game *game);
void destroy_2(struct bg *bg, sfRenderWindow *window);
sfVector2f vector_direction(struct plane *plane, int nb_p);
void create_inits(struct plane *plane, struct game *game,
struct tower *tower, struct bg *bg);
int error(int ac, int fd, struct game *game, struct stat info);
int help(int ac, char **av);
void more_square(struct plane *plane, int i, sfRenderWindow *window);

#endif /* MY_RADAR */
