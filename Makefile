all: playground
	gcc -Wno-nullability-completeness -o playground playground.c
