#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


//Estructura de una pelicula 
typedef char palabras[100]; 


typedef struct peliculas{
	palabras titulo, genero, duracion, director; 
	int estreno; 
	char sinopsis[150],actores[150],clasificacion[4]; 
	
	float CalifiTotal; 
	int votos; 
	int registro; //linea de la pelicula en el archivo 
}Pelicula; 

//Estructura de recomendaciones 
typedef struct{
	palabras genero,director; 
	char actores[200]; 
	int estreno; 
}Recomendaciones; 

//lista simple 
typedef struct nodoLista{
	Pelicula* peli; 
	struct nodoLista* next; 
}NodeLista; 

//Estructura de buscadores de peliculas 
typedef struct{
	Pelicula* espia; 
}Buscador; 

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

//Agregar al frente 
NodeLista* agg_front(NodeLista* listp, NodeLista* newp){
	newp->next = listp; 
	return newp; 
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


//Arreglos Dinamicos 
Buscador* CrearArreglo(int tamano){

	Buscador* arreglo = calloc(tamano,sizeof(Buscador)); 
	
	//inicializamos todos los apuntadores 
	for(int i = 0; i < tamano; i++){
		arreglo[i].espia = NULL; 
	}
	return arreglo; 
}

int CantidadElementos(Buscador *arreglo){
	return sizeof(arreglo)/sizeof(arreglo[0]); 
}

void AmpliarArreglo(Buscador* arreglo, int cantidad){

	Buscador* new_arreglo = calloc(CantidadElementos(arreglo),sizeof(Buscador)); 
	
	//copiamos toda la información 
	for(int i = 0; i < CantidadElementos(arreglo); i++){
		new_arreglo[i].espia = arreglo[i].espia; 
		arreglo[i].espia = NULL; 
	}
	free(arreglo); 
	
	//Devolvemos los valores al arreglo 
	for(int i = 0; i < CantidadElementos(new_arreglo); i++){
		arreglo[i].espia = new_arreglo[i].espia;
		new_arreglo[i].espia = NULL;  
	}
	free(new_arreglo); 
}
	









