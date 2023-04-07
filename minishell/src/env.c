/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell1-samy.nasset
** File description:
** env.c
*/

#include <string.h>
#include <signal.h>
#include "../include/my.h"

int cpy_env(char **env, char **env_cpy)
{
    int i = 0;

    if (env == NULL) {
        write(2, "ERROR: environment is empty.\n", 29); return 84;
    }
    while (env[i] != NULL) {
        if ((env_cpy = malloc(sizeof(char *) * (i * 2))) == NULL) {
            write(2, "ERROR: malloc() failed\n", 23);
            return 84;
        }
        i++;
    }
    i = 0;
    while (env[i] != NULL) {
        env_cpy[i] = my_strdup(env[i]);
        i++;
    }
    env_cpy[i] = NULL;
    print_env(env_cpy);
    return 0;
}

int print_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_putstr(env[i]);
        my_putstr("\n");
        i++;
    }
    return 0;
}

int id_seg(int status)
{
    int seg = 0;

    if (WIFSIGNALED(status)) {
        seg = WTERMSIG(status);
        seg_args(seg);
        if (WCOREDUMP(status)) {
            write(2, " (core dumped)\n", 15);
        } else {
            write(2, "\n", 1);
        }
    }
    return status;
}

void seg_args(int seg)
{
    if (seg != 0) {
        if (my_strcmp(strsignal(seg), "Floating point exception") == 0) {
            write(2, "Floating exception", 18);
        } else {
            write(2, strsignal(seg), my_strlen(strsignal(seg)));
        }
    }
}
