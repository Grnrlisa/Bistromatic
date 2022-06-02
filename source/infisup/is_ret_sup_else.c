/*
** EPITECH PROJECT, 2021
** infisup
** File description:
** is_ret_else.c
*/

int my_strlen(char const *str);

int is_ret_sup_else(char *nb, int t, int comp2, int ret)
{
    if ((nb[t] - ret) < '0')
        return 1;
    else
        return 0;
}