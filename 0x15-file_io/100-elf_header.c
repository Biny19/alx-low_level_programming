#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void check_elf(unsigned char *ch);
void print_magic(unsigned char *ch);
void print_class(unsigned char *ch);
void print_data(unsigned char *ch);
void print_version(unsigned char *ch);
void print_abi(unsigned char *ch);
void print_osabi(unsigned char *ch);
void print_type(unsigned int e_type, unsigned char *ch);
void print_entry(unsigned long int e_entry, unsigned char *ch);
void close_elf(int elf);
/**
* check_elf - Checks if a file is an ELF file.
* @ch: A pointer to an array containing the ELF magic numbers.
* Description: If the file is not an ELF file - exit code 98.
*/
void check_elf(unsigned char *ch)
{
int i;
for (i = 0; i < 4; i++)
{
if (ch[i] != 127 && ch[i] != 'E' && ch[i] != 'L' && ch[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}
/**
* print_magic - Prints the magic numbers of an ELF header.
* @ch: A pointer to an array containing the ELF magic numbers.
* Description: Magic numbers are separated by spaces.
*/
void print_magic(unsigned char *ch)
{
int i;
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", ch[i]);
if (i == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}
/**
* print_class - Prints the class of an ELF header.
* @ch: A pointer to an array containing the ELF class.
*/
void print_class(unsigned char *ch)
{
printf("  Class:                             ");
switch (ch[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", ch[EI_CLASS]);
}
}
/**
* print_data - Prints the data of an ELF header.
* @ch: A pointer to an array containing the ELF class.
*/
void print_data(unsigned char *ch)
{
printf("  Data:                              ");
switch (ch[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", ch[EI_CLASS]);
}
}
/**
* print_version - Prints the version of an ELF header.
* @ch: A pointer to an array containing the ELF version.
*/
void print_version(unsigned char *ch)
{
printf("  Version: %d", ch[EI_VERSION]);
switch (ch[EI_VERSION])
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
* @ch: A pointer to an array containing the ELF version.
*/
void print_osabi(unsigned char *ch)
{
printf("  OS/ABI:                            ");
switch (ch[EI_OSABI])
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
printf("<unknown: %x>\n", ch[EI_OSABI]);
}
}
/**
* print_abi - Prints the ABI version of an ELF header.
* @ch: A pointer to an array containing the ELF ABI version.
*/
void print_abi(unsigned char *ch)
{
printf("  ABI Version: %d\n", ch[EI_ABIVERSION]);
}
/**
* print_type - Prints the type of an ELF header.
* @e_type: The ELF type.
* @ch: A pointer to an array containing the ELF class.
*/
void print_type(unsigned int e_type, unsigned char *ch)
{
if (ch[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;
printf("  Type:                              ");
switch (e_type)
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
printf("<unknown: %x>\n", e_type);
}
}
/**
* print_entry - Prints the entry point of an ELF header.
* @e_entry: The address of the ELF entry point.
* @ch: A pointer to an array containing the ELF class.
*/
void print_entry(unsigned long int e_entry, unsigned char *ch)
{
printf("  Entry point address:               ");
if (ch[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (ch[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);
else
printf("%#lx\n", e_entry);
}
/**
* close_elf - Closes an ELF file.
* @elf: The file descriptor of the ELF file.
* Description: If the file cannot be closed - exit code 98.
*/
void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
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
check_elf(header->ch);
printf("ELF Header:\n");
print_magic(header->ch);
print_class(header->ch);
print_data(header->ch);
print_version(header->ch);
print_osabi(header->ch);
print_abi(header->ch);
print_type(header->e_type, header->ch);
print_entry(header->e_entry, header->ch);
free(header);
close_elf(o);
return (0);
}
