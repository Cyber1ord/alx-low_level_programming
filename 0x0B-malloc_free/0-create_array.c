#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes it with a specific char
 * @size: size of array to create
 * @c: char to initialize array with
 *
 * Return: pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
        char *arr = malloc(sizeof(char) * size);
        unsigned int i;

        if (size == 0 || arr == NULL)
                return (NULL);

        for (i = 0; i < size; i++)
                arr[i] = c;

        return (arr);
}
