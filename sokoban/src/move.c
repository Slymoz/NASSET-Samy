/*
** EPITECH PROJECT, 2022
** move
** File description:
** move
*/

#include "../my.h"

int move_up(char *buffer, int pos)
{
    int lines = len_line(buffer) + 1;

    buffer[pos - lines] = 'P';
    buffer[pos] = ' ';
    return 0;
}

int move_down(char *buffer, int pos)
{
    int lines = len_line(buffer) + 1;

    buffer[pos + lines] = 'P';
    buffer[pos] = ' ';
    return 0;
}

int move_right(char *buffer, int pos)
{
    buffer[pos + 1] = 'P';
    buffer[pos] = ' ';
    return 0;
}

int move_left(char *buffer, int pos)
{
    buffer[pos - 1] = 'P';
    buffer[pos] = ' ';
    return 0;
}
