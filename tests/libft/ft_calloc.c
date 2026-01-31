#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"

#include "libft.h"

typedef struct	s_test
{
	char	*desc;
	size_t	n;
	size_t	size;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_calloc(10, 1)",
			.n = 10,
			.size = sizeof(unsigned char),
		},
		{
			.desc = "ft_calloc(10, 4)",
			.n = 10,
			.size = sizeof(int),
		},
		{
			.desc = "ft_calloc(10, 8)",
			.n = 10,
			.size = sizeof(double),
		},
		{
			.desc = "ft_calloc(0, 1)",
			.n = 0,
			.size = sizeof(unsigned char),
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		unsigned char *output = (unsigned char *) ft_calloc(tests[i].n, tests[i].size); 
		size_t j = 0;
		while (j < tests[i].n * tests[i].size)
		{
			if (output[j] != 0)
			{
				printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
				printf(CYAN "Expected "YELLOW"0"DEFAULT);
				printf(CYAN" got "YELLOW"%d\n"DEFAULT, output[j]);
				return (-1);
			}
			j++;
		}
		free(output);
		i++;
	}
	return (0);	
}
