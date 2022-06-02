/*
** EPITECH PROJECT, 2021
** test_mult
** File description:
** my_strisequal.c
*/

int is_equal(char *nb1, char *nb2)
{
    for (int i = 0; nb1[i] != '\0'; i++) {
        if (nb1[i] != nb2[i]) {
            return 0;
        }
    }
    return 1;
}