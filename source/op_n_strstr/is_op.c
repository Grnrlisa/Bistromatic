/*
** EPITECH PROJECT, 2021
** test_evalexp
** File description:
** my_isop.c
*/

int is_op(char str)
{
    if (str == '+' || str == '-' || str == '*' || str == '/' || str == '%')
        return 1;
    else
        return 0;
}