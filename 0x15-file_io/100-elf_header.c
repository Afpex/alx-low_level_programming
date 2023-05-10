#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(char* msg)
	{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
	}

void print_header(Elf64_Ehdr header)
	{
		printf("ELF Header:\n");
		printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("None\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
	}
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("None\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
	}
	printf("  Version:                           %d\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX System V ABI\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX ABI\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD ABI\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux ABI\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris ABI\n");
			break;
		case ELFOSABI_AIX:
			printf("AIX ABI\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX ABI\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD ABI\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64 UNIX ABI\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell Modesto ABI\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("OpenBSD ABI\n");
			break;
		default:
			printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
	}
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header.e_type)
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
			printf("<unknown: %x>\n", header.e_type);
	}
	printf(" Entrypoint address: %#lx\n", header.e_entry);
	printf(" Start of program headers: %ld (bytes into file)\n", header.e_phoff);
	printf(" Start of section headers: %ld (bytes into file)\n", header.e_shoff);
	printf(" Flags: %#x\n", header.e_flags);
	printf(" Size of this header: %d (bytes)\n", header.e_ehsize);
	printf(" Size of program headers: %d (bytes)\n", header.e_phentsize);
	printf(" Number of program headers: %d\n", header.e_phnum);
	printf(" Size of section headers: %d (bytes)\n", header.e_shentsize);
	printf(" Number of section headers: %d\n", header.e_shnum);
	printf(" Section header string table index: %d\n", header.e_shstrndx);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error("Wrong number of arguments");
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		print_error("Cannot open file");
	}

	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));

	if (bytes_read != sizeof(header))
	{
		print_error("Cannot read header");
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_error("Not an ELF file");
	}

	print_header(header);

	close(fd);
	return (0);
}
