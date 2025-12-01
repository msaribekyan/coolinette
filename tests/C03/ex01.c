#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


int	ft_strncmp(char *dest, char *src, unsigned int n);

typedef struct	s_test
{
	char		*desc;
	char		*s1;
	char		*s2;
	unsigned int	n;
	int		expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strncmp(\"Hello World!\", \"Hello\", 20)",
			.s1 = "Hello World!",
			.s2 = "Hello",
			.n = 20,
			.expected = 32
		},
		{
			.desc = "ft_strncmp(\"Hello\", \"Hello World!\", 5)",
			.s1 = "Hello",
			.s2 = "Hello World!",
			.n = 5,
			.expected = 0
		},
		{
			.desc = "ft_strncmp(\"\", \"\", 1)",
			.s1 = "",
			.s2 = "",
			.n = 1,
			.expected = 0
		},
		{
			.desc = "ft_strncmp(\"\", \"Hello World!\", 20)",
			.s1 = "",
			.s2 = "Hello World!",
			.n = 20,
			.expected = -72
		},
		{
			.desc = "ft_strncmp(\"Hello World!\", \"\", 20)",
			.s1 = "Hello World!",
			.s2 = "",
			.n = 20,
			.expected = 72
		},
		{
			.desc = "ft_strncmp(\"Hello World!\", \"\", 0)",
			.s1 = "Hello",
			.s2 = "World",
			.expected = 0
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);
		if (output != tests[i].expected)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%d"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%d\n"DEFAULT, output);
			return (-1);
		}
		i++;
	}
	return (0);	
}
