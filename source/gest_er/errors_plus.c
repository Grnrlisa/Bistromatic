/*
** EPITECH PROJECT, 2021
** start.c
** File description:
** main project
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"

void my_putstr(char const *str);
int my_strlen(char const *str);
int my_atoi(char const *str);
char *get_expr(unsigned int size);
void len_crash(char *op);
void check_ops(char const *ops);
void check_base(char const *base);
void check_expr_pls(char const *str);
void check_expr(char const *str);
void my_putchar(char c);
void check_ops_v1(char const *ops);
void check_ops_v2(char const *ops);

char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+-*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops_v1(av[2]);
    check_ops_v2(av[2]);
    len_crash(av[2]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    check_expr_pls(expr);
    check_expr(expr);
    my_putstr(eval_expr(av[1], av[2], expr, size));
    return (EXIT_SUCCESS);
}
