all: programa clean executar

programa: main.o dominios.o entidades.o testes.o
	g++ main.o dominios.o testes.o -o executavel

main.o: dominios.o entidades.o testes.o
	g++ -c -Wall -ansi main.cpp

dominios.o:
	g++ -c -Wall -ansi dominios.cpp

entidades.o: dominios.o
	g++ -c -Wall -ansi testes.cpp

testes.o: dominios.o entidades.o
	g++ -c -Wall -ansi testes.cpp

clean:
	if [ "`ls -1 *.o 2>/dev/null | wc -l`" != 0 ]; then rm *.o; fi 

executar:
	./executavel

clear:
	clear
