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

char *my_div(char *nb1, char *nb2)
{
    int nb_mult = my_atoi(nb2);
    char *rep = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)) + 1);
    char *rtn = malloc(sizeof(char) * my_strlen(nb1) + 1);
    int i = 0;

    rep = nb2;
    if (nb_mult == 1)
        return nb1;
    else if (nb_mult == 0)
        return "0";
    else {
        for (i = 0; my_str_issup(rep, nb1) == 0; i++) {
                rep = my_infin_add(rep, nb2);
        }
    }
    rtn = my_itoa(i);
    return rtn;
}
