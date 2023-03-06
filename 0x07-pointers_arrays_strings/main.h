#ifndef _MAIN_H_
#define _MAIN_H_
/**
 *_memset - fills memory with a constant byte
 * @s: character 1
 * @b: character 2
 * @n: unsigned integer
 * Return: 1 or 0
 */
char *_memset(char *s, char b, unsigned int n);


/**
 * _memcpy - function that copies n bytes from memory area src to memory area dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 *
 * Return: a pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n);


char *_strchr(char *s, char c);

#endif
