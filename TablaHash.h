#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


//Estructura de una pelicula 
typedef char palabras[100]; 


typedef struct peliculas{
	palabras titulo, estreno, genero, duracion, director; 
	char sinopsis[150],actores[150],clasificacion[2]; 
	
	float CalifiTotal; 
	int votos; 
}Pelicula; 



//lista simple 
typedef struct nodoLista{
	Pelicula* peli; 
	struct nodoLista* next; 
}NodeLista; 

//Nuevo nodo
NodeLista* new_item(Pelicula* valor){
	NodeLista* newp = (NodeLista* )malloc(sizeof(NodeLista)); 
	
	newp->peli = valor; 
	newp->next = NULL; 
	
	return newp; 
}

//agregar al final 
NodeLista* agg_end(NodeLista* listp, NodeLista* newp){

	NodeLista* p = listp; 
	
	if(!p){	return newp; }

	//recorremos la lista 
	for(; p->next != NULL; p = p->next);
	
	p->next = newp; 
	 
	return listp; 
}



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
int FuncionHash(int capacidad, char* cadena) {

	int suma = 0; 
	
	//recorremos la cadena 
	for( int i = 0; i < strlen(cadena); i++){
		suma = suma + tolower(cadena[i]); 
	}

	//inidice de nuestra tabla 	
	return suma % capacidad; 
}

//función crear tabla hash 
TablaHash* CrearTabla(int capacidad) {

	TablaHash *tablah = malloc(sizeof(TablaHash)); 
	
	tablah->capacidad = capacidad; 
	
	tablah->tabla = malloc(sizeof(ElementoTabla) * capacidad); 

	//Todos los Elemento apuntan a nulo
	for( int i = 0; i < capacidad; i++){
		tablah->tabla[i].cabecera = NULL; 
	}
	return tablah; 
} 



