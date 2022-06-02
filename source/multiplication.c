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

char *mult(char *nb1, char *nb2)
{
    int nb_mult = my_atoi(nb2);
    char *rep = malloc(sizeof(char) * my_strlen(nb1) + 100000);

    rep = nb1;
    if (nb_mult == 1)
        return nb1;
    else if (nb_mult == 0)
        return "0";
    else {
        for (int i = 0; i != nb_mult - 1; i++) {
            rep = my_infin_add(rep, nb1);
        }
    }
    return rep;
}
