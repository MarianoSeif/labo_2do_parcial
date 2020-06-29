#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "vuelo.h"


int parser_flightFromText(FILE* pFile , LinkedList* pList)
{
	int datos, retorno;
	char idVuelo[5], idAvion[5], idPiloto[5], fecha[11], destino[50], cantPasajeros[5], horaDespegue[5], horaLlegada[5];
	eVuelo* pVuelo;

	retorno=-1;

	//Leo el encabezado

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);

	while(!feof(pFile)){
		if(feof(pFile)){
			break;
		}
		datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
		if(datos==8){
			pVuelo = vuelo_newParametros(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
			ll_add(pList, pVuelo);
			retorno=1;
		}
	}

    return retorno;
}
