jugador_path := ./jugador/
tablero_path := ./mesa/
puntosO_path := ./puntosO/
salida_path := ./ejecutables/
reglas_path := ./comoJugar/

todo: jueguito jugador
	echo "soy jueguito"
jueguito: $(puntosO_path)tablero.o $(puntosO_path)usaCubilete.o $(puntosO_path)dibujaDado.o
	gcc -W -Wall -o $(salida_path)jueguito $(puntosO_path)tablero.o $(puntosO_path)usaCubilete.o $(puntosO_path)dibujaDado.o	

$(puntosO_path)tablero.o: $(tablero_path)inclusion.h $(tablero_path)tablero.c
	gcc -W -Wall -c $(tablero_path)tablero.c -o $(puntosO_path)tablero.o

$(puntosO_path)usaCubilete.o: $(tablero_path)inclusion.h $(tablero_path)usaCubilete.h $(tablero_path)usaCubilete.c
	gcc -W -Wall -c $(tablero_path)usaCubilete.c -o $(puntosO_path)usaCubilete.o

$(puntosO_path)dibujaDado.o: $(tablero_path)dibujaDado.h $(tablero_path)dibujaDado.c
	gcc -W -Wall -c $(tablero_path)dibujaDado.c -o $(puntosO_path)dibujaDado.o




jugador: $(puntosO_path)jugador.o $(puntosO_path)reglas.o
	gcc -W -Wall -o $(salida_path)jugador $(puntosO_path)jugador.o $(puntosO_path)reglas.o
$(puntosO_path)jugador.o: $(jugador_path)jugador.h $(jugador_path)jugador.c
	gcc -W -Wall -c $(jugador_path)jugador.c -o $(puntosO_path)jugador.o 



$(puntosO_path)reglas.o: $(reglas_path)reglas.h $(reglas_path)reglas.c
	gcc -W -Wall -c $(reglas_path)reglas.c -o $(puntosO_path)reglas.o



borra:
	rm $(puntosO_path)*.o