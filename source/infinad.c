/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** Performs an infinite addition
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
char *my_strcat(char *dest, char const *src);
char *ret_add(char *result);

static char *str_zero(char *nbr, int x)
{
    int len = my_strlen(nbr);
    char *zero = "0";
    char *stock_zero = malloc(sizeof(char) * x);
    char *stock = malloc(sizeof(char) * (len + x));
    int i = 0;
    int j = 0;

    for (int buffer = 0; buffer < x; buffer++)
        stock_zero[buffer] = zero[0];
    while (i != (x + len)) {
        stock = my_strcat(stock_zero, nbr);
        i++;
        j++;
    }
    stock[i] = '\0';
    return (stock);
}

static int compare(int i, int j)
{
    if (i > j)
        return (i);
    else if (j > i)
        return (j);
    return (i);
}

static void longest(char **nbr1, char **nbr2, int *i, int *j)
{
    int x = 0;
    int i_bis = (*i);
    int j_bis = (*j);

    if (i_bis > j_bis) {
        x = i_bis - j_bis;
        (*nbr2) = str_zero((*nbr2), x);
        j_bis = my_strlen((*nbr2)) - 1;
    } else if (i_bis < j_bis) {
        x = j_bis - i_bis;
        (*nbr1) = str_zero((*nbr1), x);
        i_bis = my_strlen((*nbr1)) - 1;
    }
    (*i) = i_bis;
    (*j) = j_bis;
}

char *stock_hold(int stock, int *hold, char *result, int count)
{
    int hold_bis = (*hold);

    if (stock > 9) {
        result[count] = ((stock % 10) + '0');
        hold_bis = 1;
    } else {
        result[count] = (stock + '0');
        hold_bis = 0;
    }
    (*hold) = hold_bis;
    return (result);
}

char *my_infin_add(char *nbr1, char *nbr2)
{
    int stock = 0;
    int hold = 0;
    int i = my_strlen(nbr1) - 1;
    int j = my_strlen(nbr2) - 1;
    int k = compare(i, j);
    char *result = malloc(sizeof(char) * (k + 1));
    int count = k;

    longest(&nbr1, &nbr2, &i, &j);
    for (; count >= 0; j--, i--, count--) {
        stock = (nbr1[i] - '0') + (nbr2[j] - '0');
        stock += hold;
        result = stock_hold(stock, &hold, result, count);
    }
    if (hold == 1)
        result = ret_add(result);
    result[count] = '\0';
    return (result);
}
