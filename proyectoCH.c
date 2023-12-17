#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
void ver(char* cadena){   //funcion para detener el codigo 
	printf("ojo: %s  %ld\n",cadena,strlen(cadena)); 
	getchar(); 
}

void ver1(int i){
	printf("ojo1: %d \n",i); 
	getchar(); 
}
void punto(int valor){
	printf("\nLLEGUE %d\n",valor); 
	getchar(); 
}


#include "LibPeliculas.h"
#include "archivos.h"


/*

void generarRecomendaciones(HashTable *tabla, char *genero, int anio, char *director, char *actores) {
    // Aquí puedes añadir código para generar y mostrar las recomendaciones de películas
}
*/

int existe(TablaHash* tabla){
	for(int i = 0; i<tabla->capacidad; i++){
		if(tabla->tabla[i].cabecera !=NULL)
			return 1; 
	}
	
	return 0; 
}

int main(){
	//Creamos la tabla 	
	TablaHash* tabla = CrearTabla(5); 
	//Cargamos las peliculas del archivo 
	InicializarTabla(tabla); 
	
	int n; //varible de control 
	
	do{
		//Menu
		system("clear"); 
		printf("Seleccione una opcion:  "); 
		printf("\n1- Registrar nueva pelicula: \n2- Modificar una pelicula: \n3- Eliminar una pelicula: \n4- Consultar informacion de una pelicula: \n5- Calificar una pelicula existente: \n6- Listar todas las pelicuas:  \n7- recomendar:  \n0- Salir\n\n");
		fflush(stdin); 
		printf("->: "); 
		scanf("%d",&n); 
		system("clear"); 

		//Funciones principales 
		switch(n){
			case(0): 
				break; 
			case(1): 
				GuardarPelicula(tabla,RegistrarPelicula()); 
				printf("Pelicula registrada con exito\n"); 
				getchar(); 
				break; 
			case(2): 
				ModificarPelicula(tabla); 
				break; 
			case(3): 
				EliminarPelicula(tabla); 
				break; 
			case(4):
				ConsultarPelicula(tabla); 
				break; 
			case(5): 
				CalificarPelicula(tabla); 
			break; 
			case(6): 
				ListarPeliculas(tabla); 
				getchar(); 
			break; 
			case(7): 
				RecomendarPelicuas(tabla); 
			break; 
			default:
				printf("Opcion no valida..."); 
				getchar(); 
			break; 
		}
		getchar(); 
		
	}while(n != 0); 
	
	GuardarEnArchivo(tabla); 
return 0; 
}
