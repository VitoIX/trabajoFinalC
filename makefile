todo: jueguito
	echo "soy jueguito"
jueguito: tablero.o cubilete.o
	gcc -W -Wall -o jueguito tablero.o cubilete.o

tablero.o: inclusion.h tablero.c
	gcc -W -Wall -c tablero.c

cubilete.o: inclusion.h cubilete.h cubilete.c
	gcc -W -Wall -c cubilete.c

borra:
	rm *.o