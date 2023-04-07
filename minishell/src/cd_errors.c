/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell2-samy.nasset
** File description:
** cd_errors.c
*/

#include <sys/stat.h>
#include "../include/my.h"

int errors_pwd(char **tab_cd)
{
    struct stat stat_buffer;
    stat(tab_cd[1], &stat_buffer);
    if (!S_ISDIR(stat_buffer.st_mode)) {
        write(2, tab_cd[1], my_strlen(tab_cd[1]));
        write(2, ": Not a directory.\n", 19);
        return 1;
    }
    if (access(tab_cd[1], X_OK) == -1 || access(tab_cd[1], F_OK) == -1) {
        write(2, tab_cd[1], my_strlen(tab_cd[1]));
        write(2, ": Permission denied.\n", 21);
        return 1;
    }
    return 0;
}
