#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
* \brief Pregunta al usuario si desea continar y recibe la respuesta
* \return devuelve 1 para continuar 0 para abortar
*/
int fcontinuar(void)
{
	char opcion;
	int retorno=0;
	do{
		printf("\nDesea continuar(S/N)?: ");
		__fpurge(stdin);
		scanf("%c", &opcion);
		opcion = tolower(opcion);
	}while(opcion!='s' && opcion!='n');

	if(opcion=='s'){
		retorno = 1;
	}
	return retorno;
}


/*
* \brief Obtiene y valida un entero
* \param mensaje - mensaje a mostrar al usuario
* \return devuelve el valor ingresado en el caso que sea válido
*/
int getInt(char mensaje[])
{
	int i, sizeBuffer, fail;
	sizeBuffer = 10;
	char buffer[sizeBuffer];

	fail=0;

	do{
		if(fail==1){
			printf("\nError!");
			fail=0;
		}
		printf("\n%s", mensaje);

		__fpurge(stdin);
		fgets(buffer, sizeBuffer+1, stdin);

		if(strlen(buffer)==1){
		    fail=1;
		}else{
		    buffer[strlen(buffer)-1] = '\0';
            if(buffer[0]=='-' || buffer[0]=='+'){
    		    i=1;
    		}else{
    		    i=0;
    		}

    		for(;i<strlen(buffer);i++){
    			if(buffer[i]<'0' || buffer[i]>'9'){
    				fail = 1;
    			}
    		}
		}

	}while(fail==1);

	return atoi(buffer);
}


/*
* \brief Obtiene un conjunto de palabras
* \param mensaje: el mensaje a mostrar al usuario
* \param string: puntero a cadena donde se almacenará el string ingresado
* \param size: tamaño del string
* \return 0 en caso de éxito
*/
int getString(char mensaje[], char string[], int size)
{
	int i, fail;

	fail=0;

	do{
		if(fail==1){
			printf("\nError!");
			fail=0;
		}
		printf("\n%s", mensaje);

		__fpurge(stdin);
		fgets(string, size+1, stdin);

		if(strlen(string)==1){
		    fail=1;
		}else{
            string[strlen(string)-1] = '\0';
            for(i=0;i<strlen(string);i++){
    		    if(!((string[i]>='a' && string[i]<='z') || (string[i]>='A' && string[i]<='Z') || string[i]==' ')) {
    			    fail = 1;
    		    }
    		}
    	}

	}while(fail==1);

	return 0;
}

int getFileName(char mensaje[], char string[], int size)
{
	/*
	printf("\n%s", mensaje);
	__fpurge(stdin);
	fgets(string, size+1, stdin);
	string[strlen(string)-1] = '\0';

	//  \ / : * ? " < > |

	*/
	int i, fail;

	fail=0;

	do{
		if(fail==1){
			printf("\nError!");
			fail=0;
		}
		printf("\n%s", mensaje);

		__fpurge(stdin);
		fgets(string, size+1, stdin);

		if(strlen(string)==1){
		    fail=1;
		}else{
            string[strlen(string)-1] = '\0';
            for(i=0;i<strlen(string);i++){
    		    if(string[i]=='\\' || string[i]=='/' || string[i]==':' || string[i]=='*' || string[i]=='?' || string[i]=='"' || string[i]=='<' || string[i]=='>' || string[i]=='|') {
    			    fail = 1;
    		    }
    		}
    	}

	}while(fail==1);

	return 0;
}

/*
* \brief Muestra un menu en pantalla y lee la opción elegida por el usuario
* \return Devuelve una opción válida elegida por el usuario
*/
int menuPrincipal(){
	int opcion;

	do{
		printf("\n\nMenu:");
		printf("\n==================================================");
		printf("\n1. Cargar archivo");
		printf("\n2. Imprimir vuelos");
		printf("\n3. Cantidad de pasajeros");
		printf("\n4. Canidad de pasajeros a Irlanda");
		printf("\n5. Filtrar vuelos cortos");
		printf("\n6. Listar vuelos a Portugal");
		printf("\n7. Filtrar a Alex Lifeson");
		printf("\n8. Filtrar por nombre de piloto");
		printf("\n9. Filtrar por destino");
		printf("\n10. Salir");

		opcion = getInt("Ingrese opcion: ");

		if (opcion<1 || opcion>10)
		{
			printf("\nOpcion incorrecta. Ingrese nuevamente: ");
			opcion = getInt("Ingrese opcion: ");
		}
	}while(opcion<1 || opcion>10);

	return opcion;
}

/*
* \brief Muestra un menu para modifcar empleado y lee la opción elegida por el usuario
* \return Devuelve una opción válida elegida por el usuario
*/
int menuModificar(){
	int opcion;

	do{
		printf("\n\nModificar empleado:");
		printf("\n==================================");
		printf("\n1- Modificar nombre");
		printf("\n2- Modificar horas trabajadas");
		printf("\n3- Modificar sueldo");
		printf("\n4- Cancelar modificación");
		printf("\n5- Guardar y salir");

		opcion = getInt("Ingrese opcion: ");

		if (opcion<1 || opcion>5)
		{
			printf("\nOpcion incorrecta. Ingrese nuevamente: ");
			opcion = getInt("Ingrese opcion: ");
		}
	}while(opcion<1 || opcion>5);

	return opcion;
}



/*
* \brief Muestra un menu para elegir el criterio de ordenamiento de empleados y lee la opción elegida por el usuario
* \return Devuelve una opción válida elegida por el usuario
*/
int menuOrdenar(){
	int opcion;

	do{
		printf("\n\nOrdenar empleados:");
		printf("\n==================================");
		printf("\n1- Ordenar por Id (Ascendente)");
		printf("\n2- Ordenar por Id (Descendente)");
		printf("\n3- Ordenar por nombre (Ascendente)");
		printf("\n4- Ordenar por nombre (Descendente)");
		printf("\n5- Ordenar por cantidad de horas trabajadas (Ascendente)");
		printf("\n6- Ordenar por cantidad de horas trabajadas (Descendente)");
		printf("\n7- Ordenar por sueldo (Ascendente)");
		printf("\n8- Ordenar por sueldo (Descendente)");
		printf("\n9- Salir");

		opcion = getInt("Ingrese opcion: ");

		if (opcion<1 || opcion>9)
		{
			printf("\nOpcion incorrecta. Ingrese nuevamente: ");
			opcion = getInt("Ingrese opcion: ");
		}
	}while(opcion<1 || opcion>9);

	return opcion;
}
