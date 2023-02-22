#include <stdio.h>
/**
 *main - main block
 *Return: Always zero (success)
 */
int main(void)
{
	unsigned long int l, m, n, m_one, m_two, n_one, n_two;

	m = 1;
	n = 2;

	printf("%lu", m);
	for (l = 1; l < 91; l++)
	{
		printf(", %lu", n);
		n = n + m;
		m = n - m;
	}
	m_one = m / 1000000000;
	m_two = m % 1000000000;
	n_one = n / 1000000000;
	n_two = n % 1000000000;

	for (l = 92; l < 99; ++l)
	{
		printf(", %lu", n_one + (n_two / 1000000000));
		printf("%lu", n_two % 1000000000);
		n_one = n_one + m_one;
		m_one = n_one - m_one;
		n_two = n_two + m_two;
		m_two = n_two - m_two;
	}
	printf("\n");
	return (0);
}


