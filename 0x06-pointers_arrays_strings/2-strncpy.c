#include <stdio.h>
#include <string.h>

char *_strncpy(char *dest, char *src, int n)
{
	int i;
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}
	return dest;
}

int main()
{
	char src[] = "hello world";
	char dest[15];
	_strncpy(dest, src, 5);
	printf("%s\n", dest);
	return (0);
}
