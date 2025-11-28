int	ft_str_is_lowercase(char *str);

#include <stdio.h>

int main()
{
	char str1[20] = "helloworld";
	char str2[20] = "hello world";
	char str3[20] = "hello\tworld";
	char str4[20] = "Hjo20Avjka3jiiAS";
	char str5[20] = "0";

	printf("%d\n", ft_str_is_lowercase(str1));
	printf("%d\n", ft_str_is_lowercase(str2));
	printf("%d\n", ft_str_is_lowercase(str3));
	printf("%d\n", ft_str_is_lowercase(str4));
	printf("%d\n", ft_str_is_lowercase(str5));
}
