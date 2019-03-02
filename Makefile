all: playground
	gcc -Wall -Wno-nullability-completeness -o playground playground.c
