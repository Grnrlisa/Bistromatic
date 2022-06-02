/*
** EPITECH PROJECT, 2021
** return add
** File description:
** ret add
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *ret_add(char *result)
{
    char *rep = malloc(sizeof(char) * my_strlen(result) + 2);
    int i = 0;

    rep[0] = '1';
    for (; result[i] != '\0'; i++) {
        rep[i + 1] = result[i];
    }
    rep[i + 2] = '\0';
    return rep;
}
