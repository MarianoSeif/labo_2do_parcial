/*
 * piloto.h
 *
 *  Created on: 27 jun. 2020
 *      Author: mfs
 */
#include "LinkedList.h"

#ifndef PILOTO_H_
#define PILOTO_H_

typedef struct
{
	int id;
	char nombre[128];
}ePiloto;

int piloto_hardcodearPilotos(LinkedList* pListPilots);
int piloto_findPilotoById(LinkedList* pListPilotos, int id);

int piloto_setId(ePiloto* this,int id);
int piloto_getId(ePiloto* this,int* id);
int piloto_setNombre(ePiloto* this,char* nombre);
int piloto_getNombre(ePiloto* this,char* nombre);

#endif /* PILOTO_H_ */
