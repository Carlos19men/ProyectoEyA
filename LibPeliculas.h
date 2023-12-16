#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include "TablaHash.h"


//Prototipos de las funciones 
Pelicula* RegistrarPelicula(); 
void MostrarPelicula(Pelicula* peli); 
void MostrarLista(NodeLista* listp); 
void ListarPeliculas(TablaHash *tabla); 
void GuardarPelicula(TablaHash *tabla, Pelicula* valor); 
NodeLista* BuscarPelicula(TablaHash *tabla, char* nombre); 
void ModificarPelicula(TablaHash *tabla);
NodeLista* ExtraerPelicula(TablaHash *tabla,NodeLista* ruta1); 
void EliminarPelicula(TablaHash *tabla);
void ModificarCampo(TablaHash* tabla, NodeLista* ruta);
void ConsultarPelicula(TablaHash *tabla); 



//Funcion para quitar el salto de linea en una cadena 
void QuitarSalto(char* cadena){
	int len = strcspn(cadena,"\n"); 
	
	cadena[len] = '\0'; 
}

//Compara dos cadenas sin importar las mayusculas ni minusculas 
int CompararCadenas(char* cadena1, char* cadena2){
	palabras aux1, aux2; 

	strcpy(aux1,cadena1); 
	strcpy(aux2,cadena2); 
	
	if(strlen(aux1) == strlen(aux2)){
		
		for(int i = 0; i < strlen(aux1); i++){
			if( tolower(aux1[i]) != tolower(aux2[i]))
				return 0; 
		}
		return 1; 
	}
	
	return 0; 
}


//Registrar datos de pelicula
Pelicula* RegistrarPelicula(){
    Pelicula* peli;

    //reservamos memoria para la nueva pelicula 
    
    peli = (Pelicula* )malloc(sizeof(Pelicula)); 
    getchar(); 
    
    printf("\nIngrese el nombre de la pelicula: ");
    fgets(peli->titulo,sizeof(palabras),stdin);  
    QuitarSalto(peli->titulo); 
    
    printf("\nIngrese la fecha de estreno de la pelicula:  ");
    fgets(peli->estreno,sizeof(palabras),stdin);
    QuitarSalto(peli->estreno); 
    
    printf("\nIngrese el tipo de genero de la pelicula:  ");
    fgets(peli->genero,sizeof(palabras),stdin);
    QuitarSalto(peli->genero); 
    
    printf("\nIngrese la duracion de la pelicula:  ");
    fgets(peli->duracion, sizeof(palabras), stdin);
    QuitarSalto(peli->duracion);
     
    printf("\nIngrese el nombre del director de la pelicula:  ");
    fgets(peli->director, sizeof(palabras), stdin);
    QuitarSalto(peli->director); 
    
    printf("\nIngrese el elenco de actores de la pelicula:  ");
    fgets(peli->actores, 150, stdin);
    QuitarSalto(peli->actores);
     
    printf("\nIngrese la sinopsis de la pelicula:  ");
    fgets(peli->sinopsis, 150, stdin);
    QuitarSalto(peli->sinopsis); 
    
    printf("\nIngrese la clasificacion de la pelicula:  ");
    fgets(peli->clasificacion, 2, stdin);
    
    
    peli->CalifiTotal = peli->votos = 0; 
    
    return peli;
}



//mostra_pelicula
void MostrarPelicula(Pelicula* peli){

	punto(2); 
	ver(peli->titulo); 
	printf("\n________________________________________________________________________________\n"); 
	printf("Titulo:%s\n",peli->titulo);
	printf("Estreno: %s\n",peli->estreno); 
	printf("Genero: %s\n",peli->genero);  
	printf("Tiempo: %s\n",peli->duracion); 
	printf("Director: %s\n",peli->director); 
	printf("Actores: %s\n",peli->actores); 
	printf("Sinopsis: %s\n",peli->sinopsis); 
	printf("Clasifición: %s\n",peli->clasificacion); 
	if(peli->votos != 0){
		printf("Calificacion: %.2f",peli->CalifiTotal/peli->votos); 
	}
	printf("\n________________________________________________________________________________\n"); 
	
}

//Mostrar todas las peliculas 
void MostrarLista(NodeLista* listp){
	NodeLista* p = listp; 
	for(; p; p = p->next){
		MostrarPelicula(p->peli); 
	}
}



void ListarPeliculas(TablaHash *tabla) {
    // Mostramos todas las peliculas de la tabla 
    
    //recorremos la tabla
    for(int i = 0; i < tabla->capacidad; i++){
    	MostrarLista(tabla->tabla[i].cabecera); 
    }
}


//funcion para guardar una pelicula 
void GuardarPelicula(TablaHash *tabla, Pelicula* valor) {
	//tabla cerrada 
    int indice = FuncionHash(tabla->capacidad,valor->titulo);

    //reservamos memoria para el nuevo nodo de la lista
    NodeLista* newp = (NodeLista*)malloc(sizeof(NodeLista));
    
    
    newp->peli = valor;
    newp->next = NULL;
    
    
    //Agregar a la tabla
    tabla->tabla[indice].cabecera = agg_end(tabla->tabla[indice].cabecera, newp);
}



//Buscar una pelicula en la tabla 
NodeLista* BuscarPelicula(TablaHash *tabla, char* nombre) {
	palabras cadena; 
	
	if(!nombre){	getchar(); 
 		printf("Ingrese el nombre de la pelicula: ");
 		fgets(cadena, sizeof(palabras) , stdin);
 		QuitarSalto(cadena); 
 	}else{
 		strcpy(cadena,nombre); 
 	}
 	
 	int indice = FuncionHash(tabla->capacidad,cadena);
  	
	NodeLista* p = tabla->tabla[indice].cabecera; 
	
	for(; p ; p = p->next){
		if(CompararCadenas(p->peli->titulo,cadena)){
			return p; 
		}
	}
    
	return NULL; 
}

NodeLista* ExtraerPelicula(TablaHash *tabla,NodeLista* ruta1){
	
	//Si la ruta existe
	if(ruta1){
		int indice = FuncionHash(tabla->capacidad,ruta1->peli->titulo); 
		
		NodeLista* ruta2 = tabla->tabla[indice].cabecera;  // primer Elemento de la lista
		
		if(ruta2 != ruta1){
			//recorremos la lista 
			for( ; ruta2->next != ruta1; ruta2 = ruta2->next); 
			
			//redirecinamos los nodos para sacar la pelicula
			ruta2->next = ruta1->next; 
		}else{
				tabla->tabla[indice].cabecera = ruta1->next; 
		}
		
		return ruta1; //retornamos el elementos separado de la tabla 
	}
	
	printf("Pelicula no encontrada"); 
	return NULL; 
}

void EliminarPelicula(TablaHash *tabla) {

	//buscamos la ruta de la pelicula 
	NodeLista* ruta = BuscarPelicula(tabla,NULL); 
	
	if(ruta){
		NodeLista* ruta1 = ExtraerPelicula(tabla,ruta); 
    	free(ruta); 
    	printf("Pelicula eliminada con exito!");
    }else printf("Pelicula no encontrada");  
	
}


//Modificar una pelicula 
void ModificarPelicula(TablaHash *tabla) {
	//Buscamos la ruta de la pelicula 
	NodeLista* ruta = BuscarPelicula(tabla,NULL);
  
  	//Si la ruta existe
  	if(ruta){  
  		ModificarCampo(tabla,ruta); 
  	} else {
  		printf("Pelicula no encontrada \n\n"); 
  	}

}
//función de modificar un campo 
void ModificarCampo(TablaHash* tabla, NodeLista* ruta){
	
	int res; 
	
	do{
	
		system("clear"); 
		
		MostrarPelicula(ruta->peli); 
		
		printf("Seleccione una opcion:  \n");
		printf("1- Modificar un campo  \n"); 
		printf("0- salir \n\n-> "); 
		scanf("%d",&res); 
		
		if(res == 1){
			
			//opciones de la pelicula 
			printf("\n\nSeleccione uno de los campos a editar:  \n"); 
			printf("1-Titulo\n");
			printf("2-Anio de estreno\n");
			printf("3-Genero\n");
			printf("4-Duracion\n");
			printf("5-Director\n");
			printf("6-Actores principales\n");
			printf("7-sinopsis\n");
			printf("0-Salir \n"); 
			printf("->  "); 
			scanf("%d",&res); 
			getchar(); 
			switch(res){
				case 0:   
				break; 
			
				case 1: 
					palabras nuevot; 
				
					
					printf("Ingrese un nuevo titulo para la pelicula:  "); 
					fgets(nuevot,sizeof(palabras),stdin); 
					QuitarSalto(nuevot); 
			
					strcpy(ruta->peli->titulo,nuevot); 
					
					//Creamos un nodo la nueva pelicula  
					Pelicula* nueva = (Pelicula*)malloc(sizeof(Pelicula)); 
					
					nueva = ruta->peli; 
	
					//Guardamos la pelicula con su nueva clave 
					GuardarPelicula(tabla,nueva); 
					
					//borramos la anterior 
					free(ExtreaerPelicua(tabla,ruta)); 
					
					//bucamos la nueva ruta 
					ruta = BuscarPelicula(tabla,nueva->titulo); 

				break; 
			
				case 2:
					printf("Ingrese un nuevo anio de estreno para la pelicula:  "); 
					fgets(ruta->peli->estreno,sizeof(palabras),stdin);  
					QuitarSalto(ruta->peli->estreno);
				break;  
			
				case 3: 
					printf("Ingrese el nuevo genero de la pelicula:   ");
					fgets(ruta->peli->genero,sizeof(palabras),stdin); 
					QuitarSalto(ruta->peli->genero); 
				break; 
			
				case 4: 
					printf("Ingrese una nueva duracion en minutos: "); 
					fgets(ruta->peli->duracion,sizeof(palabras),stdin); 
					QuitarSalto(ruta->peli->duracion); 
				break; 
			
				case 5: 
					printf("Ingrese un nuevo director:  "); 
					fgets(ruta->peli->director,sizeof(palabras),stdin); 
					QuitarSalto(ruta->peli->director); 
				break; 
			
				case 6: 
					printf("Ingrese los nuevos actores principales:  "); 
					fgets(ruta->peli->actores,sizeof(ruta->peli->actores),stdin); 
					QuitarSalto(ruta->peli->actores); 
				break; 
			
				case 7:
					printf("Ingrese una nueva sinopsis:  "); 
					fgets(ruta->peli->sinopsis,sizeof(ruta->peli->sinopsis),stdin); 
					QuitarSalto(ruta->peli->sinopsis);
				break; 
			
				default: 
					printf("##Opcion no valida##"); 
					getchar(); 
				break; 
			}
		}
		fflush(stdin); 
	
	}while(res != 0); 
}

//Consultar la información de una pelicula 
void ConsultarPelicula(TablaHash *tabla) {
     //buscamos la dirección de la pelicula 
     NodeLista* ruta = BuscarPelicula(tabla,NULL); 
     
     if(ruta){
     	MostrarPelicula(ruta->peli); 
  		printf("\n\nPrecione cualquier tecla para salir..."); 
  	
     } else 	printf("###Pelicula no encontrada###"); 
 
}

//Calificar una pelicula 
void CalificarPelicula(TablaHash* tabla){
	
	NodeLista *ruta = BuscarPelicula(tabla,NULL); 
	
	if(ruta){
		float califi; 
		
		MostrarPelicula(ruta->peli);
		printf("\n\nLe gusto la pelicula? \n\n¿Que calificaión le daría?   ->:  "); 
		scanf("%f",&califi); 
		
		ruta->peli->CalifiTotal += califi; 
		ruta->peli->votos++; 
	} else {
		printf("Pelicula no encontrada: "); 
		return ; 
	}
	
	system("clear"); 
	MostrarPelicula(ruta->peli);
	
	printf("La pelicula ha sido calificada con exito!"); 
	
	getchar(); 
}
	


