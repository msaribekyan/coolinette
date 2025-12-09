#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

typedef struct	s_test
{
	char		*desc;
	char		dest[20];
	char		*src;
	unsigned int	size;
	char		*expected;
	unsigned int	expected_size;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strlcpy(dest[20], \"Hello World!\", 20)",
			.dest = {0},
			.src = "Hello World!",
			.size = 20,
			.expected = "Hello World!",
			.expected_size = 12,
		},
		{
			.desc = "ft_strlcpy(dest[20], \"Hello World!\", 10)",
			.dest = {0},
			.src = "Hello World!",
			.size = 10,
			.expected = "Hello Wor",
			.expected_size = 12,
		},
		{
			.desc = "ft_strlcpy(dest[20], \"Hello World!\", 5)",
			.dest = {0},
			.src = "Hello World!",
			.size = 5,
			.expected = "Hell",
			.expected_size = 12,
		},
		{
			.desc = "ft_strlcpy(dest[20], \"Hello World!\", 0)",
			.dest = {0},
			.src = "Hello World!",
			.size = 0,
			.expected = "",
			.expected_size = 12,
		},
		{
			.desc = "ft_strlcpy(dest[20], \"Hello World!\", 1)",
			.dest = {0},
			.src = "Hello World!",
			.size = 1,
			.expected = "",
			.expected_size = 12,
		},
		{
			.desc = "ft_strlcpy(dest[20], \"\", 20)",
			.dest = {0},
			.src = "",
			.size = 20,
			.expected = "",
			.expected_size = 0,
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		unsigned int output = ft_strlcpy(tests[i].dest, tests[i].src, tests[i].size);	
		if (output != tests[i].expected_size)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%d"DEFAULT, tests[i].expected_size);
			printf(CYAN" got "YELLOW"%d\n"DEFAULT, output);
			return (-1);
		}
		if (strcmp(tests[i].dest, tests[i].expected) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%s"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%s\n"DEFAULT, tests[i].dest);
			return (-1);
		}
		i++;
	}
	return (0);	
}
