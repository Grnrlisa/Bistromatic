/*
** EPITECH PROJECT, 2021
** revstr
** File description:
** retourne une string
*/
int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char tmp;
    int i = 0;
    int len = my_strlen(str) - 1;

    for (; i <= len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - i];
        str[len - i] = tmp;
    }
    return (str);
}
