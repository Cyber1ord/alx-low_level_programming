/**
 * print_name - Prints a name
 *
 * @name: Pointer to the name to print
 * @f: Pointer to the function to use to print the name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

