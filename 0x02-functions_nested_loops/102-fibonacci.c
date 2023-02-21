#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0
 *
 */
int main() {
	int a = 1, b = 2, c;
	printf("%d, %d", a, b);
	for (int i = 3; i <= 50; i++) {
		c = a + b;
		printf(", %d", c);
		a = b;
		b = c;
	}
	printf("\n");
	return (0);
}
