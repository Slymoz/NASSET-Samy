/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-bsminishell1-samy.nasset
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

static int exec_conditions(char *buffer, char **env)
{
    char **tab = NULL;
    char **home_final = NULL;
    char **path_final = NULL;
    int status = 0;

    path_final = find_path(env, path_final);
    home_final = find_home(env, home_final);
    tab = my_str_to_word_array(buffer);
    if (my_strcmp(tab[0], "cd") == 0) {
        cd_case(buffer, home_final, env);
    } else
        status = test_path(tab, env, path_final);
    return status;
}

static int separators(char *buffer, char **env)
{
    char **tab = NULL;
    int status = 0;

    tab = my_str_to_word_array2(buffer);

    if (tab == NULL)
        return 1;
    for (int i = 0; tab[i] != NULL; i++) {
        status = exec_conditions(tab[i], env);
    }
    return status;
}

int main(int ac, char **av, char **env)
{
    char **tab = NULL;
    char *buffer = NULL;
    size_t i = 0;
    int status = 0;

    if (error(ac, env) == 84)
        return 84;
    write(1, "$> ", 3);
    while (getline(&buffer, &i, stdin) != EOF) {
        if (exit_case(buffer) == 1)
            break;
        status = separators(buffer, env);
        write(1, "$> ", 3);
        free(tab);
    }
    free_exit(buffer);
    return status;
}
