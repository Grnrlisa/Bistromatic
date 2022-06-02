/*
** EPITECH PROJECT, 2021
** infisup
** File description:
** infisup.c
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
int my_strlencomp(int i, int j);
int my_str_issup(char *str1, char *str2);
int is_ret_sup(char *nb1, char *nb2, int comp, int comp2);
char *corec_rep(char *rep);
int is_ret_sup_else(char *nb, int t, int comp2, int ret);
char calc_else_sup(char *nb, int t, int ret);
int is_equal(char *nb1, char *nb2);

char *infisup_neg(char *rep)
{
    char *rtn = malloc(sizeof(char) * my_strlen(rep) + 2);
    int comp = 0;

    rtn[comp] = '-';
    comp++;
    for (int i = 0; rep[i] != '\0'; i++, comp++) {
        rtn[comp] = rep[i];
    }
    rtn[comp] = '\0';
    return rtn;
}

char calc_if_ret_sup(char *nb1, char *nb2, int comp, int comp2)
{
    int ret = 0;
    char rtn;
    int i = my_strlen(nb1) - comp - 1;
    int j = my_strlen(nb2) - comp - 1;

    if (nb1[i] - nb2[j] + '0' < '0') {
        ret = 1;
        rtn = nb1[i] - nb2[j] + '0' + 10;
    } else {
        if (nb1[i + 1] - nb2[j + 1] + '0' < '0')
            ret = 1;
        rtn = nb1[i] - nb2[j] + '0' - ret;
    }
    return rtn;
}

char *infisup_pos(char *nb1, char *nb2, int k, char *rep)
{
    int ret = 0;
    int comp2 = k - 1;
    int i = my_strlen(nb1) - 1;
    int j = my_strlen(nb2) - 1;

    for (int comp = 0; comp != k; comp++, i--, j--, comp2--) {
        if (i >= 0 && j >= 0) {
            ret = is_ret_sup(nb1, nb2, comp, comp2);
            rep[comp2] = calc_if_ret_sup(nb1, nb2, comp, comp2);
        } else if (i >= 0 && j < 0) {
            rep[comp2] = calc_else_sup(nb1, i, ret);
            ret = is_ret_sup_else(nb1, i, comp2, ret);
        } else {
            rep[comp2] = calc_else_sup(nb2, j, ret);
            ret = is_ret_sup_else(nb2, j, comp2, ret);
        }
    }
    return rep;
}

char *infisup(char *nb1, char *nb2)
{
    int k = my_strlencomp(my_strlen(nb1), my_strlen(nb2));
    int i = my_strlen(nb1) - 1;
    int j = my_strlen(nb2) - 1;
    int comp2 = k - 1;
    char *rep = malloc(sizeof(char) * k + 1);
    
    rep[k + 1] = '\0';
    if (my_strlen(nb1) > my_strlen(nb2) || my_str_issup(nb1, nb2) == 1) {
        rep = infisup_pos(nb1, nb2, k, rep);
        rep = corec_rep(rep);
        return rep;
    }
    else if (my_strlen(nb1) < my_strlen(nb2) || my_str_issup(nb1, nb2) == 0) {
        if (is_equal(nb1, nb2) == 1) 
            return "0";
        rep = infisup_pos(nb2, nb1, k, rep);
        rep = corec_rep(rep);
        rep = infisup_neg(rep);
        return rep;
    }
}
