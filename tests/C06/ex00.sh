#!/bin/bash

touch "./output"
"./prog.bin" "hello" > "./output"
if cmp -s "./output" "${HOME}/coolinette/tests/C06/ex00-out" ; then
	exit 0
else
	exit -1
fi
