#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	*ft_strdup(char *src);

typedef struct	s_test
{
	char	*desc;
	char	*src;
	char	*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strdup(\"\")",
			.src = "",
			.expected = "",
		},
		{
			.desc = "ft_strdup(\"hello\")",
			.src = "hello",
			.expected = "hello",
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_strdup(tests[i].src);
		if (strcmp(output, tests[i].expected) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%s"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%s\n"DEFAULT, output);
			return (-1);
		}
		if (output == tests[i].src)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(YELLOW"Pointers should be different\n"DEFAULT);
			return (-1);
		}
		i++;
	}
	return (0);	
}
