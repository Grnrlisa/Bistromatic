/*
** EPITECH PROJECT, 2021
** test_mult
** File description:
** test_mult.c
*/

#include <stdlib.h>
#include <stdio.h>

int my_atoi(char const *str);
int my_strlen(char const *str);
char *my_infin_add(char *nbr1, char *nbr2);
char *my_itoa(int nb);
int my_str_issup(char *str1, char *str2);
char *infisup(char *nb1, char *nb2);

char *my_modulo(char *nb1, char *nb2)
{
    int nb_mult = my_atoi(nb2);
    char *rep = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)) + 1);
    char *rtn = malloc(sizeof(char) * my_strlen(nb1) + 1);
    int i = 0;

    rep = nb2;
    if (nb_mult == 1)
        return "0";
    else if (nb_mult == 0)
        return "0";
    else {
        for (i = 0; my_str_issup(rep, nb1) != 1; i++) {
                rep = my_infin_add(rep, nb2);
        }
    }
    rep = infisup(rep, nb2);
    rtn = infisup(nb1, rep);
    return rtn;
}