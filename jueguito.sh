#!/bin/bash
#script para jugar a los dados
echo Ejecutando el Makefile
make
NOMBRE_SEMAFORO_INICIO="inicia"
VALOR_SEMAFORO_INICIA=0
NOMBRE_SEMAFORO_CUBILETE="cubilete"
VALOR_SEMAFORO_CUBILETE=1

./ejecutables/elimina_sem $NOMBRE_SEMAFORO_INICIO
./ejecutables/elimina_sem $NOMBRE_SEMAFORO_CUBILETE

./ejecutables/crea_sem $NOMBRE_SEMAFORO_INICIO $VALOR_SEMAFORO_INICIA
./ejecutables/crea_sem $NOMBRE_SEMAFORO_CUBILETE $VALOR_SEMAFORO_CUBILETE

#xterm -hold -e ejecutables/tablero $NOMBRE_SEMAFORO_INICIO
#ejecutables/tablero $NOMBRE_SEMAFORO_INICIO
#ejecutables/jugador $NOMBRE_SEMAFORO_INICIO