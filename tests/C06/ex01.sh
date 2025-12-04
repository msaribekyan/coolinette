#!/bin/bash

touch "./output"
"./prog.bin" >> "./output"
"./prog.bin" "hello" >> "./output"
"./prog.bin" "world" >> "./output"
"./prog.bin" "this" "works" >> "./output"
if cmp -s "./output" "${HOME}/coolinette/tests/C06/ex01-out" ; then
	exit 0
else
	exit -1
fi
