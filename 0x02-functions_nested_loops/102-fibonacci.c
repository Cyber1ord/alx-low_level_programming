#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0
 *
 */
int main(void) {
	unsigned long fib[50] = {1, 2};

	for (size_t i = 2; i < 50; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	for (size_t i = 0; i < 49; i++) {
		printf("%lu, ", fib[i]);
	}

	printf("%lu\n", fib[49]);

	return 0;
}
