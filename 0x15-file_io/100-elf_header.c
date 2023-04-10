#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	const unsigned char elf_magic[] = {0x7F, 'E', 'L', 'F'};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != elf_magic[i])
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}


/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 *
 * Description: The class indicates whether the ELF file is 32-bit or 64-bit.
 */
void print_class(unsigned char *e_ident)
{
	const char *class_str = "";

	if (e_ident[EI_CLASS] == ELFCLASSNONE)
	{
		class_str = "none\n";
	}
	else if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		class_str = "ELF32\n";
	}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		class_str = "ELF64\n";
	}
	else
	{
		class_str = "<unknown\n>";
	}

	printf("  Class:                             %s\n", class_str);
}
/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 * Description: prints an ELF header data
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	if (e_ident[EI_DATA] == ELFDATANONE)
	{
		printf("none\n");
	}
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
	}
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
	}
	else
	{
		printf("<unknown: 0x%x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version
 * Description: ELF header version.
 */
void print_version(unsigned char *e_ident)
{
	int version = e_ident[EI_VERSION];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
	{
		printf(" (current)\n");
	}
	else
	{
		printf("\n");
	}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");


	if (e_ident[EI_OSABI] == ELFOSABI_NONE)
	{
		printf("UNIX - System V\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
	{
		printf("UNIX - HP-UX\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
	{
		printf("UNIX - NetBSD\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
	{
		printf("UNIX - Linux\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
	{
		printf("UNIX - Solaris\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
	{
		printf("UNIX - IRIX\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
	{
		printf("UNIX - FreeBSD\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
	{
		printf("UNIX - TRU64\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
	{
		printf("ARM\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
	{
		printf("Standalone App\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       ");
	if (e_ident[EI_ABIVERSION] == 0)
	{
		printf("%d\n", e_ident[EI_ABIVERSION]);
	}
	else
	{
		printf("<unknown: %d>\n", e_ident[EI_ABIVERSION]);
	}
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}

	if (e_type == ET_NONE)
	{
		printf("  Type:                              NONE (None)\n");
	}
	else if (e_type == ET_REL)
	{
		printf("  Type:                              REL (Relocatable file)\n");
	}
	else if (e_type == ET_EXEC)
	{
		printf("  Type:                              EXEC (Executable file)\n");
	}
	else if (e_type == ET_DYN)
	{
		printf("  Type:                              DYN (Shared object file)\n");
	}
	else if (e_type == ET_CORE)
	{
		printf("  Type:                              CORE (Core file)\n");
	}
	else
	{
		printf("  Type:                              <unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	e_entry = (e_ident[EI_DATA] == ELFDATA2MSB)
		? (((e_entry << 8) & 0xFF00FF00) |
				((e_entry >> 8) & 0xFF00FF) |
				(e_entry << 16) | (e_entry >> 16))
		: e_entry;

	printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
