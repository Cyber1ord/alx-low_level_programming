#include "main.h"
#include <stdint.h>
#include <string.h>
#include <elf.h>

#define MAX_BUFFER_SIZE 4096

/**
 * read_elf_header - reads the ELF header of a file
 * @filename: the name of the file to read the header from
 * @header: a pointer to a buffer where to store the header
 * Return: 0 if successful, -1 otherwise
 */
int read_elf_header(char *filename, Elf64_Ehdr *header)
{
	int fd = open(filename, O_RDONLY);
	if (fd < 0) {
		perror("open");
		return -1;
	}

	ssize_t n = read(fd, header, sizeof(*header));
	if (n != sizeof(*header)) {
		perror("read");
		close(fd);
		return -1;
	}

	close(fd);
	return 0;
}

/**
 * print_elf_header - prints the information contained in the ELF header
 * @header: a pointer to the ELF header to print
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class:                             ");
	switch (header->e_ident[EI_CLASS]) {
		case ELFCLASSNONE: printf("none\n"); break;
		case ELFCLASS32:   printf("ELF32\n"); break;
		case ELFCLASS64:   printf("ELF64\n"); break;
		default:           printf("<unknown>\n"); break;
	}

	printf("Data:                              ");
	switch (header->e_ident[EI_DATA]) {
		case ELFDATANONE: printf("none\n"); break;
		case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
		case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
		default:          printf("<unknown>\n"); break;
	}

	printf("OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI]) {
		case ELFOSABI_NONE: printf("UNIX System V ABI\n"); break;
		case ELFOSABI_HPUX: printf("HP-UX ABI\n"); break;
		case ELFOSABI_NETBSD: printf("NetBSD ABI\n"); break;
		case ELFOSABI_LINUX: printf("Linux ABI\n"); break;
		case ELFOSABI_SOLARIS: printf("Solaris ABI\n"); break;
		case ELFOSABI_AIX: printf("AIX ABI\n"); break;
		case ELFOSABI_IRIX: printf("IRIX ABI\n"); break;
		case ELFOSABI_FREEBSD: printf("FreeBSD ABI\n"); break;
		case ELFOSABI_TRU64: printf("Tru64 UNIX ABI\n"); break;
		case ELFOSABI_ARM: printf("ARM architecture ABI\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone (embedded) ABI\n"); break;
		default: printf("<unknown>\n"); break;
	}

	printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type:                              ");
}
