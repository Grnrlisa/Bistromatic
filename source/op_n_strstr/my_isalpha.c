/*
** EPITECH PROJECT, 2021
** infinadd_en_mieux
** File description:
** my_isalpha.c
*/

int my_isalpha(char str)
{
    if (str >= '0' && str <= '9')
        return 1;
    else
        return 0;
}
