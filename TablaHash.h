#include <stdio.h> 
#include <stdlib.h> 


//Estrutara de la tabla hash 

//ElementoTabla: cabeceras de las listas 
typedef struct {
	NodeLista* cabecera; 
}ElementoTabla; 



//Estructura de la tabla 
typedef struct {
    int capacidad;
    ElementoTabla *tabla;
} TablaHash;

//Funcion hash
int funcionHash(int capacidad, char* cadena) {

	int suma = 0; 
	
	//recorremos la cadena 
	for( int i = 0; i < strlen(cadena); i++){
		suma = suma + cadena[i]; 
	}

	//inidice de nuestra tabla 	
	return suma % capacidad; 
}

//función crear tabla hash 
TablaHash* crear_tabla_hash(int capacidad) {

	TablaHash *tablah = malloc(sizeof(TablaHash)); 
	
	tablah->capacidad = capacidad; 
	
	tablah->tabla = malloc(sizeof(ElementoTabla) * capacidad); 

	//Todos los Elemento apuntan a nulo
	for( int = 0; i < capacidad; i++){
		tablah->tabla[i].cabecera = NULL; 
	}
	
	return tablah; 
} 


