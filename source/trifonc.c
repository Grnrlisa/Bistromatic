/*
** EPITECH PROJECT, 2021
** fonc base & tri
** File description:
** tri les op a faire
*/
#include <stdlib.h>

char *my_convert_base(char *nbr, char *base_from, char *base_to);
char *my_infin_add(char *nbr1, char *nbr2);
char *trans_op(char *str);
char **alloc_expr(char *str);
char *my_convert_base(char *nbr, char *base_from, char *base_to);
char *mult(char *nb1, char *nb2);
char *infisup(char *nb1, char *nb2);
char *my_div(char *nb1, char *nb2);
char *my_modulo(char *nb1, char *nb2);
int my_strlencomp(int i, int j);
int my_strlen(char const *str);

char *eval_expr(char const *base, char const *operateur,
                char const *expr, unsigned int size)
{
    char **nbr = alloc_expr(expr);
    char *op = trans_op(expr);
    int len1 = my_strlen(nbr[0]);
    int len2 = my_strlen(nbr[1]);
    char *result;

    for (int idx = 0; op[idx] != '\0'; idx++) {
        if (op[idx] == '+') {
            result = malloc(sizeof(char) * (my_strlencomp(len1, len2) + 2));
            result = my_infin_add(nbr[0], nbr[1]);
        }
        if (op[idx] == '-') {
            result = malloc((sizeof(char) * (my_strlencomp(len1, len2) + 1)));
            result = infisup(nbr[0], nbr[1]);
        }
        if (op[idx] == '*') {
            result = malloc(sizeof(char) * (len1 + len2 + 1));
            result = mult(nbr[0], nbr[1]);
        }
        if (op[idx] == '/') {
            result = malloc(sizeof(char) * (len1 + 1));
            result = my_div(nbr[0], nbr[1]);
        }
        if (op[idx] == '%') {
            result = malloc(sizeof(char) * (len1 + 1));
            result = my_modulo(nbr[0], nbr[1]);
        }
        return (result);
    }
}
