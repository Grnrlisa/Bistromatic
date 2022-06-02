/*
** EPITECH PROJECT, 2021
** infisup
** File description:
** is_ret.c
*/

int my_strlen(char const *str);

int is_ret_sup(char *nb1, char *nb2, int comp, int comp2)
{
    int ret = 0;
    int i = my_strlen(nb1) - comp - 1;
    int j = my_strlen(nb2) - comp - 1;

    if (nb1[i] - nb2[j] + '0' < '0') {
        ret = 1;
    }
    return ret;
}