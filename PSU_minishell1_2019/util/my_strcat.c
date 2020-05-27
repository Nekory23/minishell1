/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strcat concatenate two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int nbr = 0;

    while (dest[nbr] != '\0')
        nbr = nbr + 1;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[nbr] = src[i];
        nbr = nbr + 1;
    }
    dest[nbr] = '\0';
    return (dest);
}
