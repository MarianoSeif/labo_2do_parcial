/*
 * piloto.c
 *
 *  Created on: 27 jun. 2020
 *      Author: mfs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piloto.h"
#include "LinkedList.h"

ePiloto* piloto_new()
{
	return (ePiloto*) malloc(sizeof(ePiloto));
}

ePiloto* piloto_newParametros(char* idStr,char* nombreStr)
{
	ePiloto* pPiloto = piloto_new();

	piloto_setId(pPiloto, atoi(idStr));
	piloto_setNombre(pPiloto, nombreStr);

	return pPiloto;
}

int piloto_hardcodearPilotos(LinkedList* pListPilots)
{
	int i;
	ePiloto* pPiloto;
	int retorno = -1;
	int id[]={1,2,3,4,5};
	char nombres[][50]={"Alex Lifeson", "Richard Bach", "John Kerry", "Erwin Rommel", "Stephen Coonts"};

	if(pListPilots!=NULL){
		for(i=0;i<5;i++){
			pPiloto = piloto_new();
			pPiloto->id = id[i];
			strcpy(pPiloto->nombre, nombres[i]);
			ll_add(pListPilots, pPiloto);
		}
		retorno = 0;
	}
	return retorno;
}


int piloto_findPilotoById(LinkedList* pListPilotos, int id)
{
	int len, index, i;
	ePiloto* pPiloto;
	index=-1;

	if(pListPilotos!=NULL){
		len=ll_len(pListPilotos);

		for(i=0;i<len;i++){
			pPiloto = (ePiloto*) ll_get(pListPilotos, i);
			//getter del id
			if(pPiloto->id==id){
				index=i;
				break;
			}
		}
	}

	return index;
}

int getNombrePiloto(LinkedList* pListPilotos, int id, char* nombrePiloto)
{
	ePiloto* pPiloto;
	int index;
	int retorno = -1;

	if(pListPilotos!=NULL){
		index = piloto_findPilotoById(pListPilotos, id);
		if(index!=-1){
			pPiloto = (ePiloto*) ll_get(pListPilotos, index);
			piloto_getNombre(pPiloto, nombrePiloto);
			//strcpy(nombrePiloto, pPiloto->nombre);
			retorno = 0;
		}
	}

	return retorno;
}

int getIdPilotoPorNombre(LinkedList* pListPilotos, char* nombrePiloto)
{
	ePiloto* pPiloto;
	int i,len, id;
	int retorno = -1;
	char nombre[128];

	if(pListPilotos!=NULL){
		len = ll_len(pListPilotos);
		for(i=0;i<len;i++){
			pPiloto = (ePiloto*) ll_get(pListPilotos, i);
			piloto_getNombre(pPiloto, nombre);

			if(strcmp(nombrePiloto, nombre)==0){
				piloto_getId(pPiloto, &id);
			}
		}
		retorno = id;
	}

	return retorno;
}

//SETTERS Y GETTERS

int piloto_setId(ePiloto* this,int id)
{
	int retorno=-1;

	if(this!=NULL && id>-1){
		this->id = id;
		retorno = 0;
	}

	return retorno;
}


int piloto_getId(ePiloto* this,int* id)
{
	int retorno = -1;

	if(this!=NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}


int piloto_setNombre(ePiloto* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && strlen(nombre)>0){
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}


int piloto_getNombre(ePiloto* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL){
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

