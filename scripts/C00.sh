#!/bin/bash

RED="\033[1;31m"
GREEN="\033[1;32m"
CYAN="\033[1;36m"
YELLOW="\033[1;33m"
NC="\033[0m"

CC="cc -Wall -Wextra -Werror"

test() {
	ex=$1
	dir_path="${PWD}/$ex"
	if [ ! -d "$dir_path" ]; then
		echo -e "${YELLOW}$ex${NC} ${RED}not found${NC}"
		return;
	fi
	
	echo -e "Testing ${YELLOW}$1${NC}"
	temp_dir=$(mktemp -d)
	case "$ex" in
		"ex00")
			file="ft_putchar.c"
			;;
		"ex01")
			file="ft_print_alphabet.c"
			;;
		"ex02")
			file="ft_print_reverse_alphabet.c"
			;;
		"ex03")
			file="ft_print_numbers.c"
			;;
		"ex04")
			file="ft_is_negative.c"
			;;
		"ex05")
			file="ft_print_comb.c"
			;;
		"ex06")
			file="ft_print_comb2.c"
			;;
		"ex07")
			file="ft_putnbr.c"
			;;
		"ex08")
			file="ft_print_combn.c"
			;;
		*)
			echo -e "${RED}Invalid exercise${NC}: Exiting..."
			exit 1
			;;
	esac
	$CC "${HOME}/coolinette/tests/C00/${ex}.c" "${dir_path}/${file}" -o "${temp_dir}/prog.bin"
	"${temp_dir}/prog.bin" > "${temp_dir}/prog-out"
	
	if cmp -s "${temp_dir}/prog-out" "${HOME}/coolinette/tests/C00/${ex}-out"; then
		echo -e "${YELLOW}${ex}${NC} ${GREEN}Correct${NC}"
	else
		echo -e "${YELLOW}${ex}${NC} ${RED}Incorrect${NC}"
	fi
	rm -rf $temp_dir
}

if [ -z "$1" ]; then
	test ex00
	test ex01
	test ex02
	test ex03
	test ex04
	test ex05
	test ex06
	test ex07
	test ex08
else
	n=$1
	ex=$(printf "ex%02d" "$n")
	test $ex
fi
