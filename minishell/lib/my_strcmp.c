/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "../include/my.h"

int my_strcmp(const char *strA, const char *strB)
{
    int diff = 0;

    while (*strA && *strA == *strB) {
        strA++;
        strB++;
    }
    diff = *strA - *strB;
    return diff;
}

int my_strncmp(char* s1, char* s2, int n)
{
    int i = 0;

    while (i != n) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        if (s1[i] == '\0' || s2[i] == '\0') {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}
