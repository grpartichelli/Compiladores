# Gabriel 301416 Makefile

etapa3: lex.yy.o main.o hash.o ast.o y.tab.o
	gcc -Wall -o etapa3 lex.yy.o main.o hash.o ast.o y.tab.o

main.o: main.c
	gcc -Wall -c main.c

hash.o: hash.c
	gcc -Wall -c hash.c

ast.o: ast.c
	gcc -Wall -c ast.c

y.tab.o: y.tab.c
	gcc -Wall -c y.tab.c
		
y.tab.c: parser.y
	yacc -d parser.y

lex.yy.o: lex.yy.c y.tab.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l 

clean:
	rm *.o lex.yy.c lex.yy.h y.tab.c y.tab.h etapa3
