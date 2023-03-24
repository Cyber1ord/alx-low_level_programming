#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - function that sum of all its parameters
 * @n: number of parameters
 * Return: int result of sum of all parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ls_args;
	unsigned int i;
	int result = 0;

	if (n == 0)
		return (0);

	va_start(ls_args, n);

	for (i = 0; i < n; i++)
	{
		result += va_arg(ls_args, int);
	}

	va_end(ls_args);
	return (result);
}
