/*
** EPITECH PROJECT, 2022
** functions
** File description:
** functions
*/

#include "../my.h"

void check(char *buffer, char *new)
{
    int key = getch();
    int l = len_line(buffer) + 1;
    int pos = get_player(buffer);

    if (key == KEY_UP && buffer[pos - l] != '#')
        condition_up(buffer, l, pos);
    if (key == KEY_DOWN && buffer[pos + l] != '#')
        condition_down(buffer, l, pos);
    if (key == KEY_RIGHT && buffer[pos + 1] != '#')
        condition_right(buffer, pos);
    if (key == KEY_LEFT && buffer[pos - 1] != '#')
        condition_left(buffer, pos);
    if (key == 32) {
        endwin();
        window_map(my_strcpy(buffer, new), new);
    }
}

int error_buff(char *buffer)
{
    int p = 0, o = 0, x = 0, w = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'P')
            p++;
        if (buffer[i] == 'O')
            o++;
        if (buffer[i] == 'X')
            x++;
        if (buffer[i] != 'P' && buffer[i] != 'O' && buffer[i] != 'X'
        && buffer[i] != '#' && buffer[i] != ' ' && buffer[i] != '\n'
        && buffer[i] != '\0')
            return 84;
    }
    if (p != 1 || o > x || x == 0 || o == 0)
        return 84;
    return 0;
}

int get_player(char *buffer)
{
    int pos_p = 0;

    while (buffer[pos_p] != 'P')
        pos_p++;
    return pos_p;
}

int window_map(char *buffer, char *new)
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    refresh();
    while (1) {
        mvaddstr(0, 0, buffer);
        if (check_win(buffer, new) == 0) {
            endwin();
            return 0;
        }
        check(buffer, new);
        compare_map(buffer, new);
    }
    return 0;
}

int compare_map(char *buffer, char *new)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ' && new[i] == 'O')
            buffer[i] = 'O';
    }
}
