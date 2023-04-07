/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>

//LIB

float my_abs(float nb);
int my_lenword(const char *str, int i);
int my_lenword_separator(const char *str, int i);
int my_nbword(const char *str);
int my_nbword_sep(const char *str);
int my_nbline(const char *str);
int my_getnbr(const char *str);
int my_getnbr_char(const char str);
float my_getfloat(const char *str);
int my_isnum(const char *str);
char* my_itoa(int value, char* buffer, int base);
int my_nbrlen(long int nb);
double my_pow(double base, int exponent);
int my_putchar(char c);
int my_putlong(long int nb);
int my_putstr(const char *str);
int my_issep(const char c);
int my_separator(const char c);
int tab_handling(const char *str, int j);
int my_issep_path(const char c);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_path(char const *str);
char **my_str_to_word_array2(char const *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *strA, const char *strB);
int my_strncmp(char* s1, char* s2, int n);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const  char *src);
int my_strlen(const char *str);
void my_swap(char *strA, char *strB);
int my_atoi(char *buffer, int i);
int my_putnbr(int nb);

//==========================MINI_SHELL==========================

//START

int start(char **tab, char **env, char *command_final);
int exit_case(char *buffer);
int free_exit(char *buffer);

//RECUP

char **find_path(char **env, char **path_final);
char **find_home(char **env, char **home_final);
int test_path(char **tab, char **env, char **path_final);
void write_error(char **tab);

//ERROR

int error(int ac, char **env);

//FIND_PWD

int pos_pwd(char **env);
int pos_oldpwd(char **env);

//CD

void cd_case(char *buffer, char **home_final, char **env);
void cd_pwd_condition(char **env, int pwd_pos, char *pwd);
void cd_oldpwd_condition(char **env, int oldpwd_pos, char *oldpwd);
void start_cd(char **env, char *pwd, int pwd_pos, int oldpwd_pos);
void initial_cd(char **env, char **home_final, int pwd_pos);

//ENV

int cpy_env(char **env, char **env_cpy);
int print_env(char **env_cpy);
int id_seg(int status);
void seg_args(int status);

//CD_ERRORS

int errors_pwd(char **tab_cd);

#endif /* MINI_SHELL */
