#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - function that prints numbers
 * @separator: string to be printed
 * @n: number of integers passed to the function
 * Return: nothing
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list list_args;
	unsigned int i;

	va_start(list_args, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(list_args, int));
		if (i < n - 1 && separator)
			printf("%s", separator);
	}
	va_end(list_args);

	printf("\n");
}
