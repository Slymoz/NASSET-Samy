/*
** EPITECH PROJECT, 2022
** my
** File description:
** my
*/

#include "../radar.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}
