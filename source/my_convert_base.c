/*
** EPITECH PROJECT, 2021
** my_convert_base.c
** File description:
** converti une base en une autre
*/
#include <stdlib.h>
int my_strlen(char const *str);
char *my_revstr(char *str);

int my_checkinext(char *str, char *base)
{
    int i = 0;
    int j = 0;

    if (str[0] == '\0' || base[0] == '\0')
        return (1);
    while (str[i] != '\0' && base[j] != '\0') {
        if (str[i] == base[j] || str[i] == '+' || str[i] == '-')
            break;
        if (base[j + 1] == '\0')
            return (1);
        j++;
        j = 0;
        i++;
    }
    return (0);
}

int my_checkerrors(char *str, char *base)
{
    int i = 0;
    int j = 0;

    if (my_checkinext(str, base))
        return (0);
    while (base[i] != '\0' && base[j] != '\0') {
        if (base[i] == base[j] && i != j)
            return (1);
        j++;
        j = 0;
        i++;
    }
    return (0);
}

int my_check_neg(char *str)
{
    int i = 0;
    int neg = 0;

    while ((str[i] == '+' || str[i] == '-') && str[i] != '\0') {
        if (str[i] == '-')
            neg++;
        i++;
    }
    if (neg % 2 == 0)
        return (1);
    return (-1);
}

int my_getnbr_base(char *str, char *base)
{
    int negative;
    int nb = 0;
    int lenght = my_strlen(base);
    int i = 0;
    int j;

    if (my_checkerrors(str, base))
        return (0);
    negative = my_check_neg(str);
    while (str[i] != '\0') {
        j = 0;
        while (j < lenght && base[j] != str[i])
            j++;
        nb = nb * lenght + j;
        i++;
    }
    return (negative * nb);
}

char *my_convert_base(char *nbr, char *base_from, char *base_to)
{
    int i = 0;
    int nb = my_getnbr_base(nbr, base_from);
    char *res = malloc(sizeof(char) * 300);

    while (nb > 0) {
        res[i] = base_to[nb % my_strlen(base_to)];
        nb = nb / my_strlen(base_to);
        i = i + 1;
    }
    res[i] = '\0';
    res = my_revstr(res);
    return (res);
}
