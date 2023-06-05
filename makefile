all:funcoes.o
	gcc -g funcoes.o main.c -o main

funcoes.o: ordenacoes.h
	gcc -c -g  funcoes.c 