jugador_path := ./jugador/
tablero_path := ./mesa/
puntosO_path := ./puntosO/
salida_path := ./ejecutables/

todo: jueguito
	echo "soy jueguito"
jueguito: $(puntosO_path)tablero.o $(puntosO_path)cubilete.o $(puntosO_path)jugador.o
	gcc -W -Wall -o $(salida_path)jueguito $(puntosO_path)tablero.o $(puntosO_path)cubilete.o
	gcc -W -Wall -o $(salida_path)jugador $(puntosO_path)jugador.o

$(puntosO_path)tablero.o: $(tablero_path)inclusion.h $(tablero_path)tablero.c
	gcc -W -Wall -c $(tablero_path)tablero.c -o $(puntosO_path)tablero.o

$(puntosO_path)cubilete.o: $(tablero_path)inclusion.h $(tablero_path)cubilete.h $(tablero_path)cubilete.c
	gcc -W -Wall -c $(tablero_path)cubilete.c -o $(puntosO_path)cubilete.o

$(puntosO_path)jugador.o: $(jugador_path)jugador.h $(jugador_path)jugador.c
	gcc -W -Wall -c $(jugador_path)jugador.c -o $(puntosO_path)jugador.o

borra:
	rm $(puntosO_path)*.o