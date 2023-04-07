/*
** EPITECH PROJECT, 2022
** my
** File description:
** my
*/

#include "../my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}
