#!/bin/bash

RED="\033[1;31m"
GREEN="\033[1;32m"
CYAN="\033[1;36m"
YELLOW="\033[1;33m"
NC="\033[0m"

CC="cc -Wall -Wextra -Werror"

test() {
	echo -e "Testing ${YELLOW}$1${NC}"
	temp_dir=$(mktemp -d)
	$CC "${HOME}/coolinette/tests/libft/${1}.c" -I. -L. libft.a -o "${temp_dir}/prog.bin"
	#fi
	"${temp_dir}/prog.bin"
	if [ "$?" == "0" ]; then
		echo -e "${YELLOW}${1}${NC} ${GREEN}Correct${NC}"
		rm -rf $temp_dir
	else
		echo -e "${YELLOW}${1}${NC} ${RED}Incorrect${NC}"
		rm -rf $temp_dir
		exit ;
	fi

}

# compile the library
echo -e "Compiling ${GREEN}libft${NC}"
make
if [ ! -f "libft.a" ]; then
	echo -e "${CYAN}libft.a${NC} ${RED}not found${NC}"
	exit ;
fi
if [ ! -f "libft.h" ]; then
	echo -e "${CYAN}libft.h${NC} ${RED}not found${NC}"
	exit ;
fi
echo -e "${CYAN}Testing part 1 (libc functions)${NC}"
test ft_isalpha
test ft_isdigit
test ft_isalnum
test ft_isascii
test ft_isprint
test ft_strlen
test ft_memset
test ft_bzero
test ft_memcpy
test ft_memmove
test ft_strlcpy
test ft_strlcat
test ft_toupper
test ft_tolower
test ft_strchr
test ft_strrchr
test ft_strncmp
test ft_memchr
test ft_memcmp
test ft_strnstr
test ft_atoi
test ft_calloc
test ft_strdup
#echo -e "${CYAN}Testing part 2 (extra functions)${NC}"
#echo -e "${CYAN}Testing part 3 (linked lists)${NC}"
# make fclean
