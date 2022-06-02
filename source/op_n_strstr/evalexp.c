/*
** EPITECH PROJECT, 2021
** test_evalexp
** File description:
** evalexp.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int my_isalpha(char str);
int is_op(char str);

int nb_op(char *str, int comp)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_op(str[i]) == 1) {
            comp++;
        }
    }
    return comp;
}

char **jej(char *str, char **nb)
{
    for (int i = 0, nb_char = 0, comp = 0; str[i] != '\0'; i++) {
        if (my_isalpha(str[i]) == 1) {
            nb[nb_char][comp] = str[i];
            comp++;
        } else {
            nb_char++;
            comp = 0;
        }
    }
    return nb;
}

char **alloc_expr(char *str)
{
    char **nb;
    char *op;
    int comp = 0;
    int nb_char = 0;

    comp = nb_op(str, comp);
    nb = malloc(sizeof(char *) * (comp + 2));
    for (int i = 0, comp = 0; str[i] != '\0'; i++, comp++) {
        if (my_isalpha(str[i]) == 0) {
            nb[nb_char] = malloc(sizeof(char) * comp + 1);
            comp = 0;
            i++;
            nb_char++;
        }
    }
    nb[nb_char] = malloc(sizeof(char) * (comp + 2));
    nb = jej(str, nb);
    return nb;
}