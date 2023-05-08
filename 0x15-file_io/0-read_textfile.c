#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: k- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffur;
	ssize_t fd;
	ssize_t k;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffur = malloc(sizeof(char) * letters);
	t = read(fd, buffur, letters);
	w = write(STDOUT_FILENO, buffur, t);

	free(buffur);
	close(fd);
	return (k);
}
