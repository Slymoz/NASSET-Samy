/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell2-samy.nasset
** File description:
** my_str_to_word_array2.c
*/

#include "../include/my.h"

char **my_tab2(const char *str, char **tab, int nb_word)
{
    int i = 0;
    int j = 0;
    int k = 0;

    j = tab_handling(str, j);
    while (i < nb_word) {
        tab[i] = malloc(my_lenword_separator(str, j) + 1);
        k = 0;
        while (my_separator(str[j]) == 1) {
            tab[i][k] = str[j];
            j = j + 1;
            k = k + 1;
        }
        j = tab_handling(str, j);
        tab[i][k] = '\0';
        i = i + 1;
    }
    tab[i] = NULL;
    return tab;
}

char **my_str_to_word_array2(char const *str)
{
    int nb_word = my_nbword_sep(str);
    char **tab = NULL;

    if ((tab = malloc(sizeof(char *) * (nb_word + 1))) == NULL) {
        return NULL;
    }

    tab = my_tab2(str, tab, nb_word);
    return tab;
}
