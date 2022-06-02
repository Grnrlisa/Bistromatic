/*
** EPITECH PROJECT, 2021
** main modified
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"

void my_putstr(char const *str);
int my_strlen(char const *str);
int my_atoi(char const *str);

void len_crash(char *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

void check_ops_v1(char const *ops)
{
    int brkadd = 0;
    int brksou = 0;
    int brkmul = 0;
    int brkdiv = 0;

    for (int buffer = 0; ops[buffer] != '\0'; buffer++) {
        if (ops[buffer] == '+')
            brkadd++;
        if (ops[buffer] == '-')
            brksou++;
        if (ops[buffer] == '*')
            brkmul++;
        if (ops[buffer] == '/')
            brkdiv++;
    }
    if (brkadd == 2 || brksou == 2 || brkmul == 2 || brkdiv == 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SAME_OPS);
    }
}

void check_ops_v2(char const *ops)
{
    int brkmod = 0;
    int brkpar1 = 0;
    int brkpar2 = 0;

    for (int buffer = 0; ops[buffer] != '\0'; buffer++) {
        if (ops[buffer] == '(')
            brkpar1++;
        if (ops[buffer] == ')')
            brkpar2++;
        if (ops[buffer] == '%')
            brkmod++;
    }
    if (brkpar1 == 2 || brkpar2 == 2 ||  brkmod == 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SAME_OPS);
    }
}

void check_base(char const *base)
{
    if (my_strlen(base) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    for (int buffer = 0; base[buffer] != '\0'; buffer++) {
        if (base[buffer] == '+' || base[buffer] == '-' ||
            base[buffer] == '*' || base[buffer] == '/' ||
            base[buffer] == '%' ) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS_IN_B);
        }
    }
}

void check_expr_pls(char const *str)
{
    for (int buffer = 0; str[buffer] != '\0'; buffer++) {
        if (str[buffer] <= '0' && str[buffer] >= '9' && str[buffer] != '+' &&
            str[buffer] != '-' && str[buffer] != '*' && str[buffer] != '/' &&
            str[buffer] != '%') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_UNKNOWN_DIGIT);
        }
    }
}
