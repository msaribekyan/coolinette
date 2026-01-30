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
	else
		echo -e "${YELLOW}${1}${NC} ${RED}Incorrect${NC}"
	fi
	rm -rf $temp_dir

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
test ft_isalpha
test ft_isdigit
test ft_isalnum
# make fclean
