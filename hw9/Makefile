CFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CXXCFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings
all: main

main:
	g++  -ggdb	-std=c++11 ${CFLAGS}  main.cpp  -o  main
clean:
	rm -f main