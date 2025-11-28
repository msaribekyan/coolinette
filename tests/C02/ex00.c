char	*ft_strcpy(char *dest, char *src);

#include <stdio.h>

int main()
{
	char s1[20] = "Hello World!";
	char s2[20] = {0};
	char *s3 = ft_strcpy((char *)&s2, s1);
	puts(s2);
	if (s2 != s3)
	{
		printf("Wrong return value!\n");
	}
	return 0;
}
