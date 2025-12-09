#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	*ft_strncpy(char *dest, char *src, unsigned int n);

typedef struct	s_test
{
	char		*desc;
	char		dest[20];
	char		*input;
	unsigned int	n;
	char		*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strncpy(dest[20], \"Hello World!\", 12)",
			.dest = {0},
			.input = "Hello World!",
			.n = 12,
			.expected = "Hello World!"
		},
		{
			.desc = "ft_strncpy(dest[20], \"Hello World!\", 20)",
			.dest = {0},
			.input = "Hello World!",
			.n = 20,
			.expected = "Hello World!"
		},
		{
			.desc = "ft_strncpy(dest[20], \"Hello World!\", 5)",
			.dest = {0},
			.input = "Hello World!",
			.n = 5,
			.expected = "Hello"
		},
		{
			.desc = "ft_strncpy(dest[20], \"Hello\", 4)",
			.dest = "World",
			.input = "Hello",
			.n = 4,
			.expected = "Helld"
		},
		{
			.desc = "ft_strncpy(dest[20], \"\", 5)",
			.dest = {0},
			.input = "",
			.n = 5,
			.expected = ""
		},
		{
			.desc = "ft_strncpy(dest[20], \"Hello World!\", 0)",
			.dest = "hello",
			.input = "Hello World!",
			.n = 0,
			.expected = "hello"
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_strncpy(tests[i].dest, tests[i].input, tests[i].n);
		if (strcmp(output, tests[i].expected) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%s"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%s\n"DEFAULT, output);
			return (-1);
		}
		i++;
	}
	return (0);	
}
