#!/bin/bash

if [ -z "$1" ]; then
	n=0
else
	n=$1
fi

ex=$(printf "ex%02d" "$n")

echo -n "Now checking "
echo $ex

dirname="/home/mher/Downloads/coolinette/C01/"
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
