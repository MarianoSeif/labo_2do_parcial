/*
 * main.c
 *
 *  Created on: 27 jun. 2020
 *      Author: mfs
 *
 */

#include <stdio.h>
#include "LinkedList.h"
#include "funciones.h"
#include "controller.h"
#include "piloto.h"

int main()
{
	int opcion;
	char path[50];

	LinkedList* FlightsList = ll_newLinkedList();
	LinkedList* PilotsList = ll_newLinkedList();

	//piloto_hardcodearPilotos(PilotsList);
	controller_loadPilotosFromFile("pilotos.csv",PilotsList);
	controller_ListPilots(PilotsList);

	do{
		opcion = menuPrincipal();

		switch(opcion){
			case 1:
				getFileName("Ingrese el nombre del archivo: ", path, 50);

				if(controller_loadFlightFile(path, FlightsList)==-1){
					printf("\nEl archivo no existe");
				}else{
					printf("\nArchivo cargado con exito!");
				}
				break;
			case 2:
				controller_ListFlights(FlightsList, PilotsList);
				break;
			case 3:
				controller_cantPasajerosTotales(FlightsList);
				break;
			case 4:
				controller_cantPasajerosIrlanda(FlightsList);
				break;
			case 5:
				if(controller_filtrarVuelosCortos(FlightsList)==0){
					printf("\nSe generó un archivo de vuelos cortos");
				}else{
					printf("\nNo se pudo generar el archivo");
				}
				break;
			case 6:
				controller_filtrarVuelosAPortugal(FlightsList, PilotsList);

				break;
			case 7:
				//controller_ordenar(FlightsList, PilotsList);
				//controller_ListPilots(PilotsList);
				controller_filtrarVuelosAlexLifeson(FlightsList, PilotsList);


				break;
			case 8:
				//controller_Seif_filtrarVuelosPorNombre(FlightsList, PilotsList);
				controller_Seif_filtrarVuelosPorDestino(FlightsList, PilotsList);

				break;

		}
	}while(opcion!=9);

	ll_deleteLinkedList(FlightsList);
	ll_deleteLinkedList(PilotsList);

	return 0;
}
