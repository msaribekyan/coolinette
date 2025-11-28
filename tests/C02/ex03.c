int	ft_str_is_numeric(char *str);

#include <stdio.h>

int main()
{
	char str1[20] = "123456789";
	char str2[20] = "";
	char str3[20] = "hello\tworld";
	char str4[20] = "Hjo20Avjka3jiiAS";
	char str5[20] = "0";

	printf("%d\n", ft_str_is_numeric(str1));
	printf("%d\n", ft_str_is_numeric(str2));
	printf("%d\n", ft_str_is_numeric(str3));
	printf("%d\n", ft_str_is_numeric(str4));
	printf("%d\n", ft_str_is_numeric(str5));
}
