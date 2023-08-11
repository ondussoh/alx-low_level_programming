#include "main.h"
#include <stdio.h>
char *create_buffer(void);
void close_fd(int fd);
/**
  * close_fd-  prints error when cannot close fd
  * @fd: fd unable to close
  * Return: nothing
  */
void close_fd(int fd)
{
	int a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
  * main - copies from one file to another
  * @argc: argument count
  * @argv: arguments
  * Return: Always 0
  * Description:
  * exit code 97 - argument count incorrect
  * exit code 98 - file_from doesn't exist or cannot be read
  * exit code 99 - file_to cannot be created or writted to
  * exit code 100 - file cannot be closed
  */
int main(int argc, char *argv[])
{
	int fd1, fd2, red, wr;
	char *temp_s;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0774);
	temp_s = create_buffer();
	red = read(fd1, temp_s, 1024);
	for (; red > 0;)
	{
		if (fd1 == -1 || red == -1)
		{	dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
			free(temp_s);
			exit(98);
		}

		wr = write(fd2, temp_s, red);
		if (fd2 == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(temp_s);
			exit(99);
		}
		red = read(fd1, temp_s, 1024);
		fd2 = open(argv[2], O_WRONLY | O_APPEND);
	}
	free(temp_s);
	close_fd(fd1);
	close_fd(fd2);
	return (0);
}

/**
  * create_buffer- creates buffer and allocates 1024 bytes
  *
  * Return: returns buffer
  */
char *create_buffer()
{
	char *store;


	store = malloc(sizeof(char) * 1024);

	if (store == NULL)
	{
		return (NULL);
	}
	return (store);
}
