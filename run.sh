#!/bin/sh

cmd="clang"
[[ "$(which $cmd)" == "" ]] && cmd="gcc"
eval "$cmd -o brainfuck brainfuck.c"
./brainfuck
