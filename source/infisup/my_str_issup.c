/*
** EPITECH PROJECT, 2021
** infisup
** File description:
** my_str_issup.c
*/

#include <stdio.h>

int my_strlen(char const *str);

int my_str_issup(char *str1, char *str2)
{
    if (my_strlen(str1) > my_strlen(str2))
        return 1;
    else if (my_strlen(str1) < my_strlen(str2))
        return 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return 0;
    }
}