# Gabriel 301416 Makefile

etapa2: lex.yy.o main.o hash.o y.tab.o
	gcc -o etapa2 lex.yy.o main.o hash.o y.tab.o

main.o: main.c
	gcc -c main.c
hash.o: hash.c
	gcc -c hash.c

y.tab.o: y.tab.c
	gcc -c y.tab.c
		
y.tab.c: parser.y
	yacc -d parser.y

lex.yy.o: lex.yy.c y.tab.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l 

clean:
	rm *.o lex.yy.c lex.yy.h y.tab.c y.tab.h etapa2
