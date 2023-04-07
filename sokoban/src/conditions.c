/*
** EPITECH PROJECT, 2022
** move_x
** File description:
** move_x
*/

#include "../my.h"

int condition_up(char *buffer, int l, int pos)
{
    if (buffer[pos - l] == 'X' && buffer[pos - (l * 2)] == 'X')
        return 0;
    if (buffer[pos - l] == 'X' && buffer[pos - (l * 2)] != '#') {
        buffer[pos] = buffer[pos - l];
        buffer[pos - l] = 'P';
        buffer[pos - (l * 2)] = 'X';
        buffer[pos] = ' ';
        }
    if (buffer[pos - l] == 'X' && buffer[pos - (l * 2)] == '#') {
        buffer[pos - l] = 'X';
        buffer[pos - (l * 2)] = '#';
    } else
        move_up(buffer, pos);
}

int condition_down(char *buffer, int l, int pos)
{
    if (buffer[pos + l] == 'X' && buffer[pos + (l * 2)] == 'X')
        return 0;
    if (buffer[pos + l] == 'X' && buffer[pos + (l * 2)] != '#') {
        buffer[pos] = buffer[pos + l];
        buffer[pos + l] = 'P';
        buffer[pos + (l * 2)] = 'X';
        buffer[pos] = ' ';
    }
    if (buffer[pos + l] == 'X' && buffer[pos + (l * 2)] == '#') {
        buffer[pos + l] = 'X';
        buffer[pos + (l * 2)] = '#';
    } else
        move_down(buffer, pos);
}

int condition_right(char *buffer, int pos)
{
    if (buffer[pos + 1] == 'X' && buffer[pos + 2] == 'X')
        return 0;
    if (buffer[pos + 1] == 'X' && buffer[pos + 2] != '#') {
        buffer[pos] = buffer[pos + 1];
        buffer[pos + 1] = 'P';
        buffer[pos + 2] = 'X';
        buffer[pos] = ' ';
    }
    if (buffer[pos + 1] == 'X' && buffer[pos + 2] == '#') {
        buffer[pos + 1] == 'X';
        buffer[pos + 2] == '#';
    } else
        move_right(buffer, pos);
}

int condition_left(char *buffer, int pos)
{
    if (buffer[pos - 1] == 'X' && buffer[pos - 2] == 'X') {
        return 0;
    }
    if (buffer[pos - 1] == 'X' && buffer[pos - 2] != '#') {
        buffer[pos] = buffer[pos - 1];
        buffer[pos - 1] = 'P';
        buffer[pos - 2] = 'X';
        buffer[pos] = ' ';
    }
    if (buffer[pos - 1] == 'X' && buffer[pos - 2] == '#') {
        buffer[pos - 1] == 'X';
        buffer[pos - 2] == '#';
    } else
        move_left(buffer, pos);
}

int check_win(char *buffer, char *new)
{
    int i = 0;
    int total = 0;
    int x = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'X')
            x++;
        if (buffer[i] == 'X' && new[i] == 'O')
            total++;
        i++;
    }
    if (total == x)
        return 0;
    return 1;
}
