CC=-Wall -Werror -Wpedantic -pthread -l c

test :	sort.c
	clang $(CC) -o sort sort.c

make clean:
	rm -rf sort sort.o
