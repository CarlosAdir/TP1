all: compila clean executar

c: compila clean # compilar

x: executar

compila: main.o
	g++ main.o dominios.o entidades.o controladoras.o stubs.o testes.o input_data.o servicos.o -o executavel

main.o: testes.o controladoras.o stubs.o servicos.o
	g++ -c -Wall -ansi main.cpp

dominios.o:
	g++ -c -Wall -ansi dominios.cpp

entidades.o: dominios.o
	g++ -c -Wall -ansi entidades.cpp

testes.o: entidades.o
	g++ -c -Wall -ansi testes.cpp

controladoras.o: dominios.o input_data.o
	g++ -c -Wall -ansi controladoras.cpp

stubs.o: dominios.o entidades.o input_data.o
	g++ -c -Wall -ansi stubs.cpp

servicos.o: dominios.o entidades.o input_data.o
	g++ -c -Wall -ansi servicos.cpp


input_data.o:
	g++ -c -Wall -ansi input_data.cpp

clean:
	if [ "`ls -1 *.o 2>/dev/null | wc -l`" != 0 ]; then rm *.o; fi 

executar:
	./executavel

clear:
	clear
