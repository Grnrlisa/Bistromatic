/*
** EPITECH PROJECT, 2021
** infisup
** File description:
** my_strcomp.c
*/

int my_strlencomp(int i, int j)
{
    if (i > j)
        return i;
    else if (j > i)
        return j;
    else
        return i;
}