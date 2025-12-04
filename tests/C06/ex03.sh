#!/bin/bash

touch "./output"
"./prog.bin" >> "./output"
"./prog.bin" "1" >> "./output"
"./prog.bin" "3" "1" "2" "11" "20" "10" "30" "40" "32" >> "./output"
if cmp -s "./output" "${HOME}/coolinette/tests/C06/ex03-out" ; then
	exit 0
else
	exit -1
fi
