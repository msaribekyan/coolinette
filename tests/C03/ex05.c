#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

typedef struct	s_test
{
	char		*desc;
	char		dest[50];
	char		*src;
	unsigned int	size;
	char		*expected_dest;
	unsigned int	expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strlcat(\"Hello\", \"  World!\", 20)",
			.dest = "Hello",
			.src = " World!",
			.size = 20,
			.expected_dest = "Hello World!",
			.expected = 12
		},
		{
			.desc = "ft_strlcat(\"Hello\", \"  World!\", 13)",
			.dest = "Hello",
			.src = " World!",
			.size = 13,
			.expected_dest = "Hello World!",
			.expected = 12
		},
		{
			.desc = "ft_strlcat(\"Hello\", \"  World!\", 12)",
			.dest = "Hello",
			.src = " World!",
			.size = 12,
			.expected_dest = "Hello World",
			.expected = 12
		},
		{
			.desc = "ft_strlcat(\"Hello\", \"  World!\", 11)",
			.dest = "Hello",
			.src = " World!",
			.size = 11,
			.expected_dest = "Hello Worl",
			.expected = 12
		},
		{
			.desc = "ft_strlcat(\"Hello\", \"  World!\", 6)",
			.dest = "Hello",
			.src = " World!",
			.size = 6,
			.expected_dest = "Hello",
			.expected = 12
		},
		{
			.desc = "ft_strlcat(\"Hello\", \"  World!\", 5)",
			.dest = "Hello",
			.src = " World!",
			.size = 5,
			.expected_dest = "Hello",
			.expected = 12
		},
		{
			.desc = "ft_strlcat(\"Hello\", \"  World!\", 3)",
			.dest = "Hello",
			.src = " World!",
			.size = 3,
			.expected_dest = "Hello",
			.expected = 10
		},
		{
			.desc = "ft_strlcat(\"Hello\", \"  World!\", 0)",
			.dest = "Hello",
			.src = " World!",
			.size = 0,
			.expected_dest = "Hello",
			.expected = 7
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		unsigned int output = ft_strlcat(tests[i].dest, tests[i].src, tests[i].size);
		if (output != tests[i].expected)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%d"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%d\n"DEFAULT, output);
			return (-1);
		}
		if (strcmp(tests[i].dest, tests[i].expected_dest) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%s"DEFAULT, tests[i].expected_dest);
			printf(CYAN" got "YELLOW"%s\n"DEFAULT, tests[i].dest);
			return (-1);
		}
		i++;
	}
	return (0);	
}
