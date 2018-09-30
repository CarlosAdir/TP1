all: programa clean clear executar

programa: executa_testes.o dominios.o entidades.o testes.o
	g++ executa_testes.o dominios.o entidades.o testes.o -o executavel

executa_testes.o: dominios.o entidades.o testes.o
	g++ -c -Wall -ansi executa_testes.cpp

dominios.o:
	g++ -c -Wall -ansi dominios.cpp

entidades.o: dominios.o
	g++ -c -Wall -ansi entidades.cpp

testes.o: dominios.o entidades.o
	g++ -c -Wall -ansi testes.cpp

clean:
	if [ "`ls -1 *.o 2>/dev/null | wc -l`" != 0 ]; then rm *.o; fi 

executar:
	./executavel

clear:
	clear
