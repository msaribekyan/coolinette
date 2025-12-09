#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	*ft_strcapitalize(char *str);

typedef struct	s_test
{
	char	*desc;
	char	input[50];
	char	*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strcapitalize(\"hi, how are you? 42words forty-two; fifty+and+one\")",
			.input = "hi, how are you? 42words forty-two; fifty+and+one",
			.expected = "Hi, How Are You? 42words Forty-Two; Fifty+And+One"
		},
		{
			.desc = "ft_strcapitalize(\"heLlo\\nwoRld\")",
			.input = "heLlo\nwoRld",
			.expected = "Hello\nWorld"
		},
		{
			.desc = "ft_strcapitalize(\"snake_case_text\tit_just_works\")",
			.input = "snake_case_text\tit_just_works",
			.expected = "Snake_Case_Text\tIt_Just_Works"
		},
		{
			.desc = "ft_strcapitalize(\"snake_case_text~it_just_works\")",
			.input = "snake_case_text~it_just_works",
			.expected = "Snake_Case_Text~It_Just_Works"
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_strcapitalize(tests[i].input);
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
