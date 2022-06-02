/*
** EPITECH PROJECT, 2021
** infisup
** File description:
** calc_else.c
*/

char calc_else_sup(char *nb, int t, int ret)
{
    if ((nb[t] - ret) < '0')
        return (nb[t] - ret + 10);
    else
        return (nb[t] - ret);
}