#ifndef _MAIN_H_
#define _MAIN_H_
/**
 * create_array - function that creates array of chars
 * @size: size of the array to be created
 * @c: char to initialize with
 * Return: Pointer to the array
 */
char *create_array(unsigned int size, char c);

/**
 * _strdup - function that returns a pointer to a newly allocated space
 * in memory which contains a copy of the string given as a parameter.
 * @str: string to copy
 * Return: pointer to the duplicated string.
 */
char *_strdup(char *str);

/**
 * str_concat - function that concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * Return: concatenated string
 */
char *str_concat(char *s1, char *s2);

/**
 * alloc_grid - function that returns a pointer to a 2dimensional array of int
 * @width: width of the array
 * @height: height of the array
 * Return: pointer to the grid
 */
int **alloc_grid(int width, int height);

/**
 * free_grid -  function that frees a 2 dimensional grid previously created
 * @grid: grid to check
 * @height: height of the grid
 */
void free_grid(int **grid, int height);

/**
 * argstostr - function that concatenates all the arguments of program
 * @ac: argument count
 * @av: array of arguments
 * Return: pointer to new string
 */
char *argstostr(int ac, char **av);

/**
 * strtow - splits a string into words.
 * @str: string to be splitted
 * Return: pointer to an array of strings (words) or null
 **/
char **strtow(char *str);

#endif

