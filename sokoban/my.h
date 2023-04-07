/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#ifndef MY_H
    #define MY_H

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
int window_map(char *buffer, char *new);
int count_n(char *buffer);
int len_line(char *buffer);
int help(int ac, char **av);
void check(char *buffer, char *new);
int get_player(char *buffer);
int move_up(char *buffer, int pos);
int move_down(char *buffer, int pos);
int move_right(char *buffer, int pos);
int move_left(char *buffer, int pos);
int condition_up(char *buffer, int l, int pos);
int condition_down(char *buffer, int l, int pos);
int condition_right(char *buffer, int pos);
int condition_left(char *buffer, int pos);
int compare_map(char *buffer, char *new);
int error_buff(char *buffer);
int check_win(char *buffer, char *new);

#endif /* MY_H */
