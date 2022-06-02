/*
** EPITECH PROJECT, 2021
** infisup
** File description:
** corec_rep.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *corec_rep(char *rep)
{
    char *rtn;
    int i = 0;
    int comp = 0;
    
    if (my_strlen(rep) > 1 && rep[0] == '0') {
        if (rep[0] == '0' && rep[1] >= '1' && rep[1] <= '9') {
            i++;
            rtn = malloc(sizeof(char) * my_strlen(rep));
        }
        for (; rep[i] != '\0'; i++, comp++) {
            rtn[comp] = rep[i];
        }
    } else
        return rep;
    return rtn;
}
