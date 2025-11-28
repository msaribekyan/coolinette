int	ft_str_is_alpha(char *str);

#include <stdio.h>

int main()
{
	char str1[20] = "HelloWorld";
	char str2[20] = "Hell0 World!";
	char str3[20] = "hello\tworld";
	char str4[20] = "1234567890";
	char str5[20] = "\n";

	printf("%d\n", ft_str_is_alpha(str1));
	printf("%d\n", ft_str_is_alpha(str2));
	printf("%d\n", ft_str_is_alpha(str3));
	printf("%d\n", ft_str_is_alpha(str4));
	printf("%d\n", ft_str_is_alpha(str5));
}
