#!/bin/bash

touch "./output"
"./prog.bin" >> "./output"
"./prog.bin" "hello" >> "./output"
"./prog.bin" "test" "123" "and" "four">> "./output"
if cmp -s "./output" "${HOME}/coolinette/tests/C06/ex02-out" ; then
	exit 0
else
	exit -1
fi
