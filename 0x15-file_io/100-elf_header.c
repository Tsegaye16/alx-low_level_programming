#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void check_elf(unsigned char *p_ident);
void print_magic(unsigned char *p_ident);
void print_class(unsigned char *p_ident);
void print_data(unsigned char *p_ident);
void print_version(unsigned char *p_ident);
void print_abi(unsigned char *p_ident);
void print_osabi(unsigned char *p_ident);
void print_type(unsigned int p_type, unsigned char *p_ident);
void print_entry(unsigned long int p_entry, unsigned char *p_ident);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @p_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *p_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (p_ident[index] != 127 &&
		    p_ident[index] != 'E' &&
		    p_ident[index] != 'L' &&
		    p_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @p_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *p_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", p_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_version - Prints the version of an ELF header.
 * @p_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *p_ident)
{
	printf("  Version:                           %d",
	       p_ident[EI_VERSION]);

	switch (p_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @p_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *p_ident)
{
	printf("  OS/ABI:                            ");

	switch (p_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", p_ident[EI_OSABI]);
	}
}

/**
 * print_type - Prints the type of an ELF header.
 * @p_type: The ELF type.
 * @p_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int p_type, unsigned char *p_ident)
{
	if (p_ident[EI_DATA] == ELFDATA2MSB)
		p_type >>= 8;

	printf("  Type:                              ");

	switch (p_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", p_type);
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

	check_elf(header->p_ident);
	printf("ELF Header:\n");
	print_magic(header->p_ident);
	print_class(header->p_ident);
	print_data(header->p_ident);
	print_version(header->p_ident);
	print_osabi(header->p_ident);
	print_abi(header->p_ident);
	print_type(header->p_type, header->p_ident);
	print_entry(header->p_entry, header->p_ident);

	free(header);
	close_elf(o);
	return (0);
}
