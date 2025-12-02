#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


void	ft_putnbr_base(int nbr, char *base);

typedef struct	s_test
{
	char	*desc;
	int	nb;
	char	*base;
	char	*expected;
}	t_test;

int main(int argc, char **argv)
{
	int	i;
	int	count;
	char	buffer[1024];

	if (argc < 1)
		return (1);
	t_test tests[] = {
		{
			.desc = "ft_putnbr_base(1234, \"0123456789abcdef\")",
			.nb = 1234,
			.base = "0123456789abcdef",
			.expected = "4d2",
		},
		{
			.desc = "ft_putnbr_base(1234, \"01230\")",
			.nb = 1234,
			.base = "01230",
			.expected = "",
		},
		{
			.desc = "ft_putnbr_base(1234, \"poneyvif\")",
			.nb = 1234,
			.base = "poneyvif",
			.expected = "nenn",
		},
		{
			.desc = "ft_putnbr_base(632906, \"!z#%v0M2.xE\")",
			.nb = 632906,
			.base = "!z#%v0M2.xE",
			.expected = "%E#0ME",
		},
		{
			.desc = "ft_putnbr_base(-2147483648, \"0123456789ABCDEF\")",
			.nb = -2147483648,
			.base = "0123456789ABCDEF",
			.expected = "-80000000",
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		memset(buffer, 0, 1024);
		int	std_out = dup(1);
		int 	out_file = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

		dup2(out_file, 1);
		close(out_file);

		ft_putnbr_base(tests[i].nb, tests[i].base);

		fflush(stdout);
		dup2(std_out, 1);
		close(std_out);

		FILE *fp = fopen(argv[1], "r");
		fgets(buffer, 1024, fp);
		fclose(fp);

		if (strcmp(buffer, tests[i].expected) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%s"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%s\n"DEFAULT, buffer);
			return (-1);
		}
		
		i++;
	}
	return (0);
}
