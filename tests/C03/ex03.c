#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	*ft_strncat(char *dest, char *src, unsigned int nb);

typedef struct	s_test
{
	char		*desc;
	char		dest[50];
	char		*src;
	unsigned int	nb;
	char		*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strncat(\"Hello\", \"  World!\", 20)",
			.dest = "Hello",
			.src = " World!",
			.nb = 20,
			.expected = "Hello World!"
		},
		{
			.desc = "ft_strncat(\"Hello\", \"  World!\", 3)",
			.dest = "Hello",
			.src = " World!",
			.nb = 3,
			.expected = "Hello Wo"
		},
		{
			.desc = "ft_strncat(\"\", \"Hello\", 0)",
			.dest = "",
			.src = "Hello",
			.nb = 0,
			.expected = ""
		},
		{
			.desc = "ft_strncat(\"Hello\", \"\", 0)",
			.dest = "Hello",
			.src = "",
			.nb = 0,
			.expected = "Hello"
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_strncat(tests[i].dest, tests[i].src, tests[i].nb);
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
