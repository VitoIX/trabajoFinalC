#!/bin/bash
#script para limpiar los semaforos al termianr de juagr
NOMBRE_SEMAFORO_INICIO="inicia"
VALOR_SEMAFORO_INICIA=0
NOMBRE_SEMAFORO_CUBILETE="cubilete"
VALOR_SEMAFORO_CUBILETE=1

./ejecutables/elimina_sem $NOMBRE_SEMAFORO_INICIO
./ejecutables/elimina_sem $NOMBRE_SEMAFORO_CUBILETE