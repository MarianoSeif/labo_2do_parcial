/*
 * vuelo.c
 *
 *  Created on: 27 jun. 2020
 *      Author: mfs
 */

/*	FUNCION PARA FILTER DEVULVE 0 O 1
int e_n(void* element)
{
	int retorno = 0;
	e* elemento;
	if(element!=NULL){
		elemento = (e*) element;
		if((elemento->a - elemento->b)<3){
			retorno = 1;
		}
	}
	return retorno;
}


//FUNCION PARA COUNT
int e_n(void* element)
{
	int retorno = -1;
	if(element!=NULL){
		retorno = ((e*) element)->cantPasajeros;
	}
	return retorno;
}

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelo.h"
#include "piloto.h"

eVuelo* vuelo_new()
{
	return (eVuelo*) malloc(sizeof(eVuelo));
}


eVuelo* vuelo_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr, char* destinoStr, char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr)
{
	eVuelo* pVuelo = vuelo_new();

	vuelo_setIdVuelo(pVuelo, atoi(idVueloStr));
	vuelo_setIdAvion(pVuelo, atoi(idAvionStr));
	vuelo_setIdPiloto(pVuelo, atoi(idPilotoStr));
	vuelo_setFecha(pVuelo, fechaStr);
	vuelo_setDestino(pVuelo, destinoStr);
	vuelo_setCantPasajeros(pVuelo, atoi(cantPasajerosStr));
	vuelo_setHoraDespegue(pVuelo, atoi(horaDespegueStr));
	vuelo_setHoraLlegada(pVuelo, atoi(horaLlegadaStr));
	/*
	pVuelo->idVuelo = atoi(idVueloStr);
	pVuelo->idAvion = atoi(idAvionStr);
	pVuelo->idPiloto = atoi(idPilotoStr);
	strcpy(pVuelo->fecha, fechaStr);
	strcpy(pVuelo->destino, destinoStr);
	pVuelo->cantPasajeros = atoi(cantPasajerosStr);
	pVuelo->horaDespegue = atoi(horaDespegueStr);
	pVuelo->horaLlegada = atoi(horaLlegadaStr);
*/
	return pVuelo;
}

int vuelo_listOne(eVuelo* this, int header, char* nombrePiloto)
{
	int retorno=-1;
	int idVuelo, idAvion, cantPasajeros, horaDespegue, horaLlegada;
	char fecha[11], destino[128];

	if(this!=NULL){
		vuelo_getIdVuelo(this, &idVuelo);
		vuelo_getIdAvion(this, &idAvion);
		//vuelo_getIdVuelo(this, &idPiloto);
		vuelo_getFecha(this, fecha);
		vuelo_getDestino(this, destino);
		vuelo_getCantPasajeros(this, &cantPasajeros);
		vuelo_getHoraDespegue(this, &horaDespegue);
		vuelo_getHoraLlegada(this, &horaLlegada);

		if(header){
			printf("\n%10s%10s%20s%25s%25s%10s%10s%10s", "idVuelo", "idAvion", "idPiloto", "fecha", "destino", "cantPasajeros", "horaDespegue", "horaLlegada");
		}

		printf("\n%10d%10d%20s%25s%25s%10d%10d%10d", idVuelo, idAvion, nombrePiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
	}
	return retorno;
}

int vuelo_cantidadDePasajeros(void* element)
{
	int retorno = -1;
	int cantPasajeros;
	eVuelo* pVuelo;

	if(element!=NULL){
		pVuelo = (eVuelo*) element;
		vuelo_getCantPasajeros(pVuelo, &cantPasajeros);
		retorno = cantPasajeros;
	}
	return retorno;
}

int vuelo_cantidadDePasajerosIrlanda(void* element)
{
	int retorno = -1;
	int cantPasajeros;
	eVuelo* pVuelo;
	char destino[128];

	if(element!=NULL){
		pVuelo = (eVuelo*) element;
		vuelo_getDestino(pVuelo, destino);

		if(strcmp(destino, "Irlanda")==0){
			vuelo_getCantPasajeros(pVuelo, &cantPasajeros);
			retorno = cantPasajeros;
		}
	}
	return retorno;
}

int vuelo_vuelosCortos(void* element)
{
	int retorno = 0;
	eVuelo* elemento;
	if(element!=NULL){
		elemento = (eVuelo*) element;
		if((elemento->horaLlegada - elemento->horaDespegue)<3){
			retorno = 1;
		}
	}
	return retorno;
}

int vuelo_vuelosAPortugal(void* element)
{
	int retorno = 0;

	if(element!=NULL){
		if(strcmp(((eVuelo*) element)->destino, "Portugal")==0){
			retorno = 1;
		}
	}
	return retorno;
}

int vuelo_vuelosNoLifeson(void* element)
{
	int retorno = 0;

	if(element!=NULL){
		if((((eVuelo*) element)->idPiloto)!=1){
			retorno = 1;
		}
	}
	return retorno;
}

int vuelo_vuelosPorPiloto(void* element, int piloto)
{
	int retorno = 0;
	int idPiloto;
	eVuelo* pVuelo;

	if(element!=NULL){
		pVuelo = (eVuelo*) element;
		vuelo_getIdPiloto(pVuelo, &idPiloto);

		if(piloto==idPiloto){
			retorno = 1;
		}
	}
	return retorno;
}


int vuelo_vuelosPorDestinoYPasajeros(void* element1, void* element2)
{
	int retorno = -1;
	eVuelo* vuelo1 = (eVuelo*) element1;
	eVuelo* vuelo2 = (eVuelo*) element2;

	if(element1!=NULL && element2!=NULL){
		if(strcmp(vuelo1->destino, vuelo2->destino)<0 || (strcmp(vuelo1->destino, vuelo2->destino)==0 && vuelo1->cantPasajeros<vuelo2->cantPasajeros)){
			retorno = 1;
		}
	}
	return retorno;
}


int vuelo_setIdVuelo(eVuelo* this, int idVuelo)
{
	int retorno=-1;

	if(this!=NULL){
		this->idVuelo = idVuelo;
		retorno = 0;
	}
	return retorno;
}


int vuelo_getIdVuelo(eVuelo* this, int* idVuelo)
{
	int retorno = -1;

	if(this!=NULL){
		*idVuelo = this->idVuelo;
		retorno = 0;
	}
	return retorno;
}

int vuelo_setIdAvion(eVuelo* this, int idAvion)
{
	int retorno=-1;

	if(this!=NULL){
		this->idAvion = idAvion;
		retorno = 0;
	}
	return retorno;
}


int vuelo_getIdAvion(eVuelo* this, int* idAvion)
{
	int retorno = -1;

	if(this!=NULL){
		*idAvion = this->idAvion;
		retorno = 0;
	}
	return retorno;
}

int vuelo_setIdPiloto(eVuelo* this, int idPiloto)
{
	int retorno=-1;

	if(this!=NULL){
		this->idPiloto = idPiloto;
		retorno = 0;
	}
	return retorno;
}


int vuelo_getIdPiloto(eVuelo* this, int* idPiloto)
{
	int retorno = -1;

	if(this!=NULL){
		*idPiloto = this->idPiloto;
		retorno = 0;
	}
	return retorno;
}


int vuelo_setFecha(eVuelo* this,char* fecha)
{
	int retorno = -1;

	if(this!=NULL && strlen(fecha)>0){
		strcpy(this->fecha, fecha);
		retorno = 0;
	}
	return retorno;
}


int vuelo_getFecha(eVuelo* this,char* fecha)
{
	int retorno = -1;

	if(this!=NULL){
		strcpy(fecha,this->fecha);
		retorno = 0;
	}
	return retorno;
}

int vuelo_setDestino(eVuelo* this,char* destino)
{
	int retorno = -1;

	if(this!=NULL && strlen(destino)>0){
		strcpy(this->destino, destino);
		retorno = 0;
	}
	return retorno;
}


int vuelo_getDestino(eVuelo* this,char* destino)
{
	int retorno = -1;

	if(this!=NULL){
		strcpy(destino,this->destino);
		retorno = 0;
	}
	return retorno;
}


int vuelo_setCantPasajeros(eVuelo* this, int cantPasajeros)
{
	int retorno=-1;

	if(this!=NULL){
		this->cantPasajeros = cantPasajeros;
		retorno = 0;
	}
	return retorno;
}


int vuelo_getCantPasajeros(eVuelo* this, int* cantPasajeros)
{
	int retorno = -1;

	if(this!=NULL){
		*cantPasajeros = this->cantPasajeros;
		retorno = 0;
	}
	return retorno;
}

int vuelo_setHoraDespegue(eVuelo* this, int horaDespegue)
{
	int retorno=-1;

	if(this!=NULL){
		this->horaDespegue = horaDespegue;
		retorno = 0;
	}
	return retorno;
}


int vuelo_getHoraDespegue(eVuelo* this, int* horaDespegue)
{
	int retorno = -1;

	if(this!=NULL){
		*horaDespegue = this->horaDespegue;
		retorno = 0;
	}
	return retorno;
}

int vuelo_setHoraLlegada(eVuelo* this, int horaLlegada)
{
	int retorno=-1;

	if(this!=NULL){
		this->horaLlegada = horaLlegada;
		retorno = 0;
	}
	return retorno;
}


int vuelo_getHoraLlegada(eVuelo* this, int* horaLlegada)
{
	int retorno = -1;

	if(this!=NULL){
		*horaLlegada = this->horaLlegada;
		retorno = 0;
	}
	return retorno;
}
