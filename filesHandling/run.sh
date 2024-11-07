#!/bin/zsh

# Compile and run the filesHandling program
# run this file is more easier than each time write the commands 
#(automate the process)
mode=$1
src=$1
dest=$2

gcc files.c ../libs/mylib.c -g -o files.exe

if [ $? -eq 0 ]; then
    if [ "$mode" = "-d" ]; then  # Use = instead of ==
        valgrind ./files.exe
    else
        ./files.exe $src $dest
    fi
else
    echo "We tried to compile the file, but it failed. Source: run.sh"
fi
