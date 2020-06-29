/*
 * controller.h
 *
 *  Created on: 27 jun. 2020
 *      Author: mfs
 */

int controller_loadFlightFile(char* path, LinkedList* plistFlights);
int controller_ListFlights(LinkedList* pListFlights, LinkedList* pListPilotos);
int controller_ListPilots(LinkedList* pListPilotos);
int controller_cantPasajerosTotales(LinkedList* pListFlights);
int controller_cantPasajerosIrlanda(LinkedList* pListFlights);
int controller_saveAsText(char* path , LinkedList* pListFlights);
int controller_filtrarVuelosCortos(LinkedList* pListFlights);
int controller_filtrarVuelosAPortugal(LinkedList* pListFlights, LinkedList* PilotsList);
int controller_filtrarVuelosAlexLifeson(LinkedList* pListFlights, LinkedList* PilotsList);
int controller_ordenar(LinkedList* pListFlights, LinkedList* PilotsList);
int controller_Seif_filtrarVuelosPorNombre(LinkedList* pListFlights, LinkedList* PilotsList);
int controller_Seif_filtrarVuelosPorDestino(LinkedList* pListFlights, LinkedList* PilotsList);
int controller_loadPilotosFromFile(char* path, LinkedList* plistFlights);
