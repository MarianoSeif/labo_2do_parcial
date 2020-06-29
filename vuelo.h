/*
 * vuelo.h
 *
 *  Created on: 27 jun. 2020
 *      Author: mfs
 */

#ifndef VUELO_H_
#define VUELO_H_

typedef struct
{
	int idVuelo;
	int idAvion;
	int idPiloto;
	char fecha[11];
	char destino[128];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;

}eVuelo;

eVuelo* vuelo_new();
eVuelo* vuelo_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr, char* destinoStr, char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr);
int vuelo_listOne(eVuelo* this, int header, char* nombrePiloto);

int vuelo_cantidadDePasajeros(void* element);
int vuelo_cantidadDePasajerosIrlanda(void* element);
int vuelo_vuelosCortos(void* element);
int vuelo_vuelosAPortugal(void* element);
int vuelo_vuelosNoLifeson(void* element);
int vuelo_vuelosPorDestinoYPasajeros(void* element1, void* element2);
int vuelo_vuelosPorPiloto(void* element, int piloto);
int vuelo_vuelosPorNombreDestino(void* element, char* destino);


int vuelo_setIdVuelo(eVuelo* this, int idVuelo);
int vuelo_getIdVuelo(eVuelo* this, int* idVuelo);
int vuelo_setIdAvion(eVuelo* this, int idAvion);
int vuelo_getIdAvion(eVuelo* this, int* idAvion);
int vuelo_setIdPiloto(eVuelo* this, int idPiloto);
int vuelo_getIdPiloto(eVuelo* this, int* idPiloto);
int vuelo_setFecha(eVuelo* this,char* fecha);
int vuelo_getFecha(eVuelo* this,char* fecha);
int vuelo_setDestino(eVuelo* this,char* destino);
int vuelo_getDestino(eVuelo* this,char* destino);
int vuelo_setCantPasajeros(eVuelo* this, int cantPasajeros);
int vuelo_getCantPasajeros(eVuelo* this, int* cantPasajeros);
int vuelo_setHoraDespegue(eVuelo* this, int horaDespegue);
int vuelo_getHoraDespegue(eVuelo* this, int* horaDespegue);
int vuelo_setHoraLlegada(eVuelo* this, int horaLlegada);
int vuelo_getHoraLlegada(eVuelo* this, int* horaLlegada);

#endif /* VUELO_H_ */
