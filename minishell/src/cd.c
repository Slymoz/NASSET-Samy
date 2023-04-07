/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell1-samy.nasset
** File description:
** cd.c
*/

#include "../include/my.h"

void cd_case(char *buffer, char **home_final, char **env)
{
    char **tab_cd = NULL;
    char pwd[2048]; char oldpwd[2048];
    int pwd_pos = pos_pwd(env); int oldpwd_pos = pos_oldpwd(env);

    tab_cd = my_str_to_word_array(buffer);
    if (my_strcmp(tab_cd[0], "cd") == 0 && tab_cd[1] != NULL) {
        getcwd(oldpwd, 2048);
        if (errors_pwd(tab_cd) == 1) return;
        if (chdir(tab_cd[1]) != 0) {
            write(2, tab_cd[1], my_strlen(tab_cd[1]));
            write(2, ": No such file or directory.\n", 29);
        }
        start_cd(env, pwd, pwd_pos, oldpwd_pos);
        cd_pwd_condition(env, pwd_pos, pwd);
        cd_oldpwd_condition(env, oldpwd_pos, oldpwd);
    }
    if ((my_strcmp(tab_cd[0], "cd") == 0 && tab_cd[1] == NULL) ||
    (my_strcmp(tab_cd[0], "cd") == 0 && my_strcmp(tab_cd[1], "~") == 0))
        initial_cd(env, home_final, pwd_pos);
    free(tab_cd);
}

void cd_pwd_condition(char **env, int pwd_pos, char *pwd)
{
    my_strcpy(env[pwd_pos], "PWD=");
    my_strcat(env[pwd_pos], pwd);
}

void cd_oldpwd_condition(char **env, int oldpwd_pos, char *oldpwd)
{
    my_strcpy(env[oldpwd_pos], "OLDPWD=");
    my_strcat(env[oldpwd_pos], oldpwd);
}

void start_cd(char **env, char *pwd, int pwd_pos, int oldpwd_pos)
{
    env[pwd_pos] = malloc(sizeof(char) * (1000));
    getcwd(pwd, 2048);
    env[oldpwd_pos] = malloc(sizeof(char) * (1000));
}

void initial_cd(char **env, char **home_final, int pwd_pos)
{
    chdir(home_final[1]);
    env[pwd_pos] = malloc(sizeof(char) * (4 + my_strlen(home_final[1]) + 1));
    my_strcpy(env[pwd_pos], "PWD=");
    my_strcat(env[pwd_pos], home_final[1]);
}
