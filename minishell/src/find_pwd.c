/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell1-samy.nasset
** File description:
** find_pwd.c
*/

#include "../include/my.h"

int pos_pwd(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PWD=", 4) == 0) {
            return i;
        }
        i++;
    }
    return 0;
}

int pos_oldpwd(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "OLDPWD=", 7) == 0) {
            return i;
        }
        i++;
    }
    return 0;
}
