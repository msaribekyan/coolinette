#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


int ft_ultimate_range(int **range, int min, int max);

typedef struct	s_test
{
	char	*desc;
	int	min;
	int	max;
	int	*dest;
	int	expected[20];
	int	expected_size;
}	t_test;

int main()
{
	int	i;
	int	j;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_ultimate_range(\"dest, 0, 10\")",
			.min= 0,
			.max = 10,
			.dest = (int *)1,
			.expected_size = 10,
			.expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		},
		{
			.desc = "ft_ultimate_range(\"dest, 10, 20\")",
			.min= 10,
			.max = 20,
			.dest = (int *)1,
			.expected_size = 10,
			.expected = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
		},
		{
			.desc = "ft_ultimate_range(\"dest, 10, 10\")",
			.min= 10,
			.max = 10,
			.dest = (int *)1,
			.expected_size = 0,
			.expected = {0},
		},
		{
			.desc = "ft_ultimate_range(\"dest, 10, 0\")",
			.min= 10,
			.max = 0,
			.dest = (int *)1,
			.expected_size = 0,
			.expected = {0},
		},

	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_ultimate_range((int **)&tests[i].dest, tests[i].min, tests[i].max);
		if (tests[i].min >= tests[i].max && (output != 0 || tests[i].dest != 0))
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(YELLOW "Output should be NULL\n"DEFAULT);
			return (-1);
		}
		if (tests[i].expected_size != output)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(YELLOW "Output should be NULL\n"DEFAULT);
			return (-1);
		}
		j = 0;
		while (j < tests[i].expected_size)
		{
			if (tests[i].expected[j] != tests[i].dest[j])
			{
				printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
				printf(YELLOW"Outputs is incorrect\n"DEFAULT);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);	
}
