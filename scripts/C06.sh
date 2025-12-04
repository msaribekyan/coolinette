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
	case "$ex" in
		"ex00")
			file="ft_print_program_name.c"
			;;
		"ex01")
			file="ft_print_params.c"
			;;
		"ex02")
			file="ft_rev_params.c"
			;;
		"ex03")
			file="ft_sort_params.c"
			;;
		*)
			echo -e "${RED}Invalid exercise${NC}: Exiting..."
			exit 1
			;;
	esac
	$CC "${dir_path}/${file}" -o "./prog.bin"
	"${HOME}/coolinette/tests/C06/${ex}.sh"
	if [ "$?" == "0" ]; then
		echo -e "${YELLOW}${ex}${NC} ${GREEN}Correct${NC}"
	else
		echo -e "${YELLOW}${ex}${NC} ${RED}Incorrect${NC}"
	fi
	rm prog.bin output
}

if [ -z "$1" ]; then
	test ex00
	test ex01
	test ex02
	test ex03
else
	n=$1
	ex=$(printf "ex%02d" "$n")
	test $ex
fi
