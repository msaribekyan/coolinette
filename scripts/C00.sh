#!/bin/bash

GREEN="\033[1;32m"
RED="\033[1;31m"
CYAN="\033[1;36m"
NC="\033[0m"

if [ -z "$1" ]; then
	n=0
else
	n=$1
fi

ex=$(printf "ex%02d" "$n")

echo -n "Now checking "
echo $ex

dirname="$COOLINETTE_DIR"
test_c="${dirname}${ex}.c"
test_o="${dirname}${ex}-out"
cp $test_c ./test.c
cp $test_o ./test-out
gcc -Wall -Wextra -Werror *.c -o prog.bin
"./prog.bin" > prog-out

if cmp -s "./prog-out" "./test-out"; then
	echo 'Correct!'
else
	echo 'Inorrect!'
fi

rm test.c test-out prog.bin prog-out
