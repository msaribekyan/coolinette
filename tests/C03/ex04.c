#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	*ft_strstr(char *dest, char *src);

typedef struct	s_test
{
	char	*desc;
	char	*str;
	char	*to_find;
	char	*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strstr(\"Hello World!\", \"Hello\")",
			.str = "Hello World!",
			.to_find = "Hello",
			.expected = "Hello World!"
		},
		{
			.desc = "ft_strstr(\"Hello World!\", \"W\")",
			.str = "Hello World!",
			.to_find = "W",
			.expected = "World!"
		},
		{
			.desc = "ft_strstr(\"Hello World!\", \"Hola\")",
			.str = "Hello World!",
			.to_find = "Hola",
			.expected = 0
		},
		{
			.desc = "ft_strstr(\"Hello World!\", \"Hello World!1234\")",
			.str = "Hello World!",
			.to_find = "Hello World!1234",
			.expected = 0
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_strstr(tests[i].str, tests[i].to_find);
		if (output == 0 || tests[i].expected == 0)
		{
			if (output != tests[i].expected)
			{
				printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
				printf(CYAN "Expected "YELLOW"%p"DEFAULT, tests[i].expected);
				printf(CYAN" got "YELLOW"%p\n"DEFAULT, output);
			return (-1);
			}
		}
		else if (strcmp(output, tests[i].expected) != 0)
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
