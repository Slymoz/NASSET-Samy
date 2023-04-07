/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell1-samy.nasset
** File description:
** error.c
*/

#include <stdio.h>

int error(int ac, char **env)
{
    if (ac != 1)
        return 84;
    if (env[0] == NULL)
        return 84;
    return 0;
}
