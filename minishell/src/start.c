/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell1-samy.nasset
** File description:
** start.c
*/

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../include/my.h"

int start(char **tab, char **env, char *command_final)
{
    pid_t pid_child = 0;
    int status = 0;

    pid_child = fork();
    if (pid_child == 0) {
        execve(command_final, tab, env);
    } else if (pid_child > 0) {
        waitpid(pid_child, &status, 0);
    }
    id_seg(status);
    return status;
}

int exit_case(char *buffer)
{
    char **tab_exit = NULL;

    tab_exit = my_str_to_word_array(buffer);
    if (my_strcmp(tab_exit[0], "exit") == 0) {
        return 1;
    }
    free(tab_exit);
    return 0;
}

int free_exit(char *buffer)
{
    free(buffer);
    write(1, "exit\n", 5);
    return 0;
}
