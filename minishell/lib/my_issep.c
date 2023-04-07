/*
** EPITECH PROJECT, 2022
** my_issep.c
** File description:
** my_issep.c
*/

#include "../include/my.h"

int my_issep(const char c)
{
    if (c == '\0' || c == '\n' || c == '\t' || c == ' ' || c == ';') {
        return 0;
    }
    return 1;
}

int my_separator(const char c)
{
    if (c == '\0' || c == ';') {
        return 0;
    }
    return 1;
}

int my_issep_path(const char c)
{
    if (c == '\0' || c == '\n' || c == '\t' ||
    c == ' ' || c == ':' || c == '=') {
        return 0;
    }
    return 1;
}

int tab_handling(const char *str, int j)
{
    while (str[j] != '\0' && my_issep(str[j]) == 0) {
        j++;
    }
    return j;
}
