all: programa clean executar

c: programa clean # compilar

programa: main.o
	g++ main.o dominios.o entidades.o controladoras.o stubs.o testes.o -o executavel

main.o: testes.o controladoras.o stubs.o
	g++ -c -Wall -ansi main.cpp

dominios.o:
	g++ -c -Wall -ansi dominios.cpp

entidades.o: dominios.o
	g++ -c -Wall -ansi entidades.cpp

testes.o: entidades.o
	g++ -c -Wall -ansi testes.cpp

controladoras.o: dominios.o
	g++ -c -Wall -ansi controladoras.cpp

stubs.o: dominios.o entidades.o
	g++ -c -Wall -ansi stubs.cpp

clean:
	if [ "`ls -1 *.o 2>/dev/null | wc -l`" != 0 ]; then rm *.o; fi 

executar:
	./executavel

clear:
	clear
