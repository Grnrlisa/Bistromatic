/*
** EPITECH PROJECT, 2021
** check expr
** File description:
** checking expr
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"

void my_putstr(char const *str);
void my_putchar(char c);

void check_expr(char const *str)
{
    int par1 = 0;
    int par2 = 0;

    for (int buffer = 0; str[buffer] != '\0'; buffer++) {
        if (str[buffer] == ' ') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(INV_EXPR_SPACE);
        }
        if (str[buffer] == '+' && str[buffer + 1] == '*') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(INV_EXPR_TWO_OP);
        }
        if (str[buffer] == '(')
            par1++;
        if (str[buffer] == ')')
            par2++;
    }
    if (par1 != par2 || par2 != par1) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(INV_EXPR_PAR);
    }
}
