/*
 * controller.c
 *
 *  Created on: 27 jun. 2020
 *      Author: mfs
 */
#include <stdio.h>
#include "LinkedList.h"
#include "vuelo.h"
#include "piloto.h"
#include "parser.h"

int controller_loadFlightFile(char* path, LinkedList* plistFlights)
{
	int retorno = -1;
	FILE* pFile;

	pFile=fopen(path, "r");

	if(pFile!=NULL){
		if(parser_flightFromText(pFile, plistFlights)==-1){
			printf("\nError. El archivo está vacio");
		}

		fclose(pFile);
		retorno = 1;
	}

	return retorno;
}

int controller_ListFlights(LinkedList* pListFlights, LinkedList* pListPilotos)
{
    int i, len, retorno;
    retorno = -1;
    eVuelo* pVuelo;
    ePiloto* pPiloto;

    if(pListFlights!=NULL){
		if(ll_isEmpty(pListFlights)){
			printf("\nNo hay nada para mostrar");
		}else{
			len = ll_len(pListFlights);
			printf("\nListar Vuelos\n========================================");
			printf("\n%10s%10s%20s%25s%25s%10s%10s%10s", "idVuelo", "idAvion", "Piloto", "fecha", "destino", "Pasajeros", "horaDes", "horaLleg");

			for(i=0;i<len;i++){
				pVuelo = (eVuelo*) ll_get(pListFlights, i);
				//printf("\nINDEX: %d", piloto_findPilotoById(pListPilotos, pVuelo->idPiloto));
				pPiloto = (ePiloto*) ll_get(pListPilotos, piloto_findPilotoById(pListPilotos, pVuelo->idPiloto));
				vuelo_listOne(pVuelo, 0, pPiloto->nombre);
			}
		}
		retorno = 0;
    }

	return retorno;
}

int controller_ListPilots(LinkedList* pListPilotos)
{
    int i, len, retorno;
    retorno = -1;

    ePiloto* pPiloto;
    //Employee* pAuxEmployee = (Employee*) malloc(sizeof(Employee));

    if(pListPilotos!=NULL){
		if(ll_isEmpty(pListPilotos)){
			printf("\nNo hay nada para mostrar");
		}else{
			len = ll_len(pListPilotos);
			printf("\nListar Pilotos\n========================================");
			printf("\n%10s%25s", "id", "Nombre");

			for(i=0;i<len;i++){
				pPiloto = (ePiloto*) ll_get(pListPilotos, i);
				printf("\n%10d%25s", pPiloto->id, pPiloto->nombre);
			}
		}
		retorno = 0;
    }

	return retorno;
}

int controller_cantPasajerosTotales(LinkedList* pListFlights)
{
	int retorno = -1;
	int cantPasajeros;

	if(pListFlights!=NULL){
		if(ll_isEmpty(pListFlights)){
			printf("\nLa lista está vacia");
		}else{
			cantPasajeros = ll_count(pListFlights, vuelo_cantidadDePasajeros);
			printf("\nLa cantidad de pasajeros totales es: %d", cantPasajeros);
			retorno = 0;
		}
	}
	return retorno;
}

int controller_cantPasajerosIrlanda(LinkedList* pListFlights)
{
	int retorno = -1;
	int cantPasajeros;

	if(pListFlights!=NULL){
		if(ll_isEmpty(pListFlights)){
			printf("\nLa lista está vacia");
		}else{
			cantPasajeros = ll_count(pListFlights, vuelo_cantidadDePasajerosIrlanda);
			printf("\nLa cantidad de pasajeros a Irlanda es: %d", cantPasajeros);
			retorno = 0;
		}
	}
	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pListFlights)
{
	int retorno = -1;
	FILE* pFile;
	int i, len;
	eVuelo* pVuelo;

	if(pListFlights!=NULL){
		pFile=fopen(path, "w");

		if(pFile!=NULL){
			len = ll_len(pListFlights);
			fprintf(pFile, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
			for(i=0;i<len;i++){
				pVuelo = (eVuelo*) ll_get(pListFlights, i);

				/*
				employee_getId(pEmployee, &id);
				employee_getNombre(pEmployee, nombre);
				employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
				employee_getSueldo(pEmployee, &sueldo);
				*/

				fprintf(pFile, "%d,%d,%d,%s,%s,%d,%d,%d\n", pVuelo->idVuelo, pVuelo->idAvion, pVuelo->idPiloto, pVuelo->fecha, pVuelo->destino, pVuelo->cantPasajeros, pVuelo->horaDespegue, pVuelo->horaLlegada);
			}
			fclose(pFile);
		}
	}

	return retorno;
}

int controller_filtrarVuelosCortos(LinkedList* pListFlights)
{
	int retorno = -1;
	if(pListFlights!=NULL){
		LinkedList* listaVuelosCortos;

		listaVuelosCortos = ll_filter(pListFlights, vuelo_vuelosCortos);
		if(listaVuelosCortos!=NULL){
			controller_saveAsText("VuelosCortos.csv", listaVuelosCortos);
			retorno = 0;
		}
	}
	return retorno;
}

int controller_filtrarVuelosAPortugal(LinkedList* pListFlights, LinkedList* PilotsList)
{
	int retorno = -1;
	if(pListFlights!=NULL){
		LinkedList* listaVuelosAPortugal;

		listaVuelosAPortugal = ll_filter(pListFlights, vuelo_vuelosAPortugal);
		controller_ListFlights(listaVuelosAPortugal, PilotsList);
		retorno = 0;

	}
	return retorno;
}

int controller_filtrarVuelosAlexLifeson(LinkedList* pListFlights, LinkedList* PilotsList)
{
	int retorno = -1;
	if(pListFlights!=NULL){
		LinkedList* listaVuelosNoLifeson;

		listaVuelosNoLifeson = ll_filter(pListFlights, vuelo_vuelosNoLifeson);

		if(listaVuelosNoLifeson!=NULL){
			//controller_saveAsText("VuelosAPortugal.csv", listaVuelosNoLifeson);
			controller_ListFlights(listaVuelosNoLifeson, PilotsList);
			retorno = 0;
		}
	}
	return retorno;
}




int controller_Seif_filtrarVuelosPorNombre(LinkedList* pListFlights, LinkedList* PilotsList)
{
	int retorno = -1;
	int idPiloto;
	char nombrePiloto[128];

	if(pListFlights!=NULL){
		getString("Ingrese nombre del piloto", nombrePiloto, 128);


		LinkedList* listaVuelosNoLifeson;

		listaVuelosNoLifeson = ll_filter2(pListFlights, vuelo_vuelosPorPiloto, idPiloto);

		if(listaVuelosNoLifeson!=NULL){
			//controller_saveAsText("VuelosAPortugal.csv", listaVuelosNoLifeson);
			controller_ListFlights(listaVuelosNoLifeson, PilotsList);
			retorno = 0;
		}
	}
	return retorno;
}



int controller_ordenar(LinkedList* pListFlights, LinkedList* PilotsList)
{
	int retorno = -1;

	if(pListFlights!=NULL){
		ll_sort(pListFlights, vuelo_vuelosPorDestinoYPasajeros, 0);

		controller_ListFlights(pListFlights, PilotsList);
		retorno = 0;
	}
	return retorno;
}
