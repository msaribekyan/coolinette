char	*ft_strncpy(char *dest, char *src, unsigned int n);

#include <stdio.h>

int main()
{
	char s1[20] = "Hello World!";
	char s2[20] = {0};
	char *s3 = ft_strncpy((char *)&s2, s1, 5);
	puts(s2);
	if (s2 != s3)
	{
		printf("Wrong return value!\n");
	}
	return 0;
}
