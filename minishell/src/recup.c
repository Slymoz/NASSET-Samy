/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell1-samy.nasset
** File description:
** recup.c
*/

#include <stdio.h>
#include "../include/my.h"

char **find_path(char **env, char **path_final)
{
    int i = 0;
    path_final = malloc(sizeof(env));

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            path_final = my_str_to_word_array_path(env[i]);
        }
        i++;
    }
    return path_final;
}

char **find_home(char **env, char **home_final)
{
    int i = 0;
    home_final = malloc(sizeof(env));

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            home_final = my_str_to_word_array_path(env[i]);
        }
        i++;
    }
    return home_final;
}

int test_path(char **tab, char **env, char **path_final)
{
    char *command_final = NULL; int i = 0; int status = 0;

    if (access(tab[0], F_OK) == 0) {
        status = start(tab, NULL, tab[0]); return status;
    }
    while (path_final[i] != NULL) {
        command_final = malloc(sizeof(char) *
        my_strlen(tab[0]) + my_strlen(path_final[i]) + 2);
        command_final = my_strcpy(command_final, path_final[i]);
        command_final = my_strcat(command_final, "/");
        command_final = my_strcat(command_final, tab[0]);
        if (access(command_final, F_OK) == 0) {
            status = start(tab, env, command_final);
            return status;
        }
        if (path_final[i + 1] != NULL) free(command_final);
        i++;
    }
    write_error(tab); free(command_final);
    return 0;
}

void write_error(char **tab)
{
    write(2, tab[0], my_strlen(tab[0]));
    write(2, ": Command not found.\n", 21);
}
