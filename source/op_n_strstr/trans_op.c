/*
** EPITECH PROJECT, 2021
** test_evalexp
** File description:
** trans_op.c
*/

#include <stdlib.h>
#include <stdio.h>

int my_isalpha(char str);
int is_op(char str);

char *trans_op(char *str)
{
    char *op;
    int comp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_op(str[i]) == 1) {
            comp++;
        }
    }
    op = malloc(sizeof(char) * comp + 1);
    comp = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalpha(str[i]) == 0) {
            op[comp] = str[i];
            comp++;
        }
    }
    return op;
}
