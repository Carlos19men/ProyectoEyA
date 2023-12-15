#include <stdio.h> 
#include <stdlib.h>
#include <TablaHash.h> 



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

	//recorremos la lista 
	for(NodeLista* p = listp ; p->next != NULL; p = p->next);
	
	p->next = newp; 
	 
	return listp; 
}

//Estructura de una pelicula 
typedef char palabras[30]; 


typedef struct peliculas{
	palabras titulo, estreno, genero, duracion, director; 
	char sinopsis[150],actores[150],clasificacion[2]; 
	
	float total; 
	int calificacion; 	
}Pelicula; 



//estructuras para mostrar peliculas 

//mostra_pelicula
void mostrar_pelicula(Pelicula* peli){	
	printf("Titulo:%s\n",peli->titulo);
	printf("Estreno: %s\n",peli->estreno); 
	printf("Genero: %s\n",peli->genero);  
	printf("Tiempo: %s\n",peli->duracion); 
	printf("Director: %s\n",peli->director); 
	printf("Actores: %s\n",peli->actores); 
	printf("Sinopsis: %s\n",peli->sinopsis); 
	printf("Clasifición: %s\n",peli->clasificacion); 
	printf("Calificacion: %d\n\n",peli.calificacion); 
	
}


//Registrar datos de pelicula
Pelicula* registrarPelicula() {
    Pelicula* peli;
    
    //reservamos memoria para la nueva pelicula 
    
    peli = (Pelicula* )malloc(sizeof(Pelicula)); 
    
    
    printf("Ingrese el nombre de la pelicula: ");
    fgest(peli->titulo,30,stdin); 
    
    printf("Ingrese la fecha de estreno de la pelicula");
    fgest(peli->estreno,30,stdin);
    
    printf("Ingrese el tipo de genero de la pelicula");
    fgets(peli->genero,30,stdin);
    
    printf("Ingrese la duracion de la pelicula");
    fgets(peli->duracion, 30, stdin);
    
    printf("Ingrese el nombre del director de la pelicula");
    fgets(peli->directo, 30, stdin);
    
    printf("Ingrese el elenco de actores de la pelicula");
    fgets(peli->actores, 150, stdin);
    
    printf("Ingrese la sinopsis de la pelicula");
    fgets(peli->sinopsis, 150, stdin);
    
    printf("Ingrese la clasificacion de la pelicula");
    fgets(peli->clasificacion, 2, stdin);
    
    printf("Ingrese la calificacion de la pelicula");
    fgets(peli->clasificacion, 30, stdin);
    
    return peli;
}

//Mostrar todas las peliculas 
void mostrar_todo(NodeLista* listp){
	NodeLista* p = listp; 
	for(; p; p = p->next){
		mostra_pelicula(p->peli); 
	}
}


//funcion para guardar una pelicula 
void guardar_pelicula(TablaHash *tabla, Pelicula* valor) {
	//tabla cerrada 

    int indice = funcionHash(tabla->capacidad,valor->titulo);
    
    //reservamos memoria para el nuevo nodo de la lista
    NodeLista* newp = (NodeLista*)malloc(sizeof(NodeLista));
    
    newp->peli = valor;
    newp->next = NULL;
    
    //Agregar a la tabla
    tabla->tabla[indice].cabecera = add_end(tabla->tabla[indice].cabecera, newp);
}

//Buscar una pelicula en la tabla 
NodeLista* buscar_pelicula(TablaHash *tabla) {
	char titulo[30];

 	printf("Ingrese el nombre de la pelicula: ");
 	fgets(titulo, 30, stdin);
  
	int indice = funcionHash(tabla->capacidad,titulo);
	
	NodeLista* p = tabla->tabla[indice].cabecera; 
	
	for(; p ; p = p->next){
		if(strcmp(p->peli.titulo,titulo) == 0){
			return p; 
		}
	}
    
	return NULL; 
}

//Modificar una pelicula 
void modificarPelicula(TablaHash *tabla) {

	//Buscamos la ruta de la pelicula 
	NodeLista* ruta = buscar_pelicula(tabla);
  
  	//Si la ruta existe
  	if(ruta){  modificar_campo(ruta)}; 
  	
  	
  	printf("Pelicula no encontrada \n\n"); 

}

//Editar un campo de una pelicula (string)
void editar_campo(char* campo){
 	char nuevo[150]; 
 	 //Pedimos el nuevo dato 
 	fgest(nuevo,150,stdin); 
 	
 	//Editamos el nuevo dato 
 	strcpy(campo,nuevo); 
}

//función de modificar un campo 
void modificar_campo(NodeLista* ruta){
	
	int res; 
	
	do{
	
		system("clear"); 
		
		mostra_pelicula(ruta); 
		
		printf("Seleccione una opcion:  \n");
		printf("1- Modificar un campo  \n"); 
		printf("0- salir \n\n	-> "); 
		scanf("%d",&res); 
		
		if(res == 0){
			
			//opciones de la pelicula 
			printf("Seleccione uno de los campos a editar:  "); 
			printf("1-Titulo\n");
			printf("2-Anio de estreno\n");
			printf("3-Genero\n");
			printf("4-Duracion\n");
			printf("5-Director\n");
			printf("6-Actores principales\n");
			printf("7-sinopsis\n");
			printf("0-Salir ")
			printf("	->  "); 
			scanf("%d",&res); 
		
			char nuevo[150]; 
		
			switch(res){
				case 0:   
				break; 
			
				case 1: 
					printf("Ingrese un nuevo titulo para la pelicula:  "); 
					editar_campo(ruta->titulo); 
				break; 
			
				case 2:
					printf("Ingrese un nuevo genero para la pelicula:  "); 
					editar_campo(ruta->genero); 
			
				case 3: 
					printf("Ingrese una nuevo anio de estreno:   ")
					editar_campo(ruta->estreno); 
				break; 
			
				case 4: 
					printf("Ingrese una nueva duracion en minutos: "); 
					editar_campo(ruta->duracion); 
				break; 
			
				case 5: 
					printf("Ingrese un nuevo director:  "); 
					editar_campo(ruta->director); 
				break; 
			
				case 6: 
					printf("Ingrese los nuevos actores principales:  "); 
					editar_campo(ruta->actores); 
				break; 
			
				case 7:
					printf("Ingrese una nueva sinopsis:  "); 
					editar_campo(ruta->sinopsis); 
				break; 
			
				default: 
					printf("##Opcion no valida##"); 
					getchar(); 
				break; 
			}
		}
	
	}while(res != 0); 
}



void eliminarPelicula(TablaHash *tabla) {

	//buscamos la ruta de la pelicula 
    NodeLista* ruta1 = buscar_pelicula(tabla);
    
    //Si la ruta existe                                              
    if(ruta){
		int indice = funcionHash(tabla->capacidad,ruta->peli->titulo); 
		
		NodeLista* ruta2 = tabla->tabla[indice].cabecera;  // primer ElementoTabla
		
		if(ruta2 != ruta1){
			//recorremos la lista 
			for( ; ruta2->next != ruta1); 
			
			ruta2->next = ruta1->next; 
		}else{
			tabla->tabla[indice].cabecera = ruta1->next; 
		}
		
		free(ruta);  //liberamos memoria 
		printf("Pelicula eliminada con exito   "); 
		
    } else printf("Pelicula no encontrada    ")
}

void consultarPelicula(TablaHash *tabla, char *titulo) {
     //buscamos la dirección de la pelicula 
     NodeLista* ruta = buscar_pelicula(tabla); 
     
     if(ruta){
     	mostrar_pelicula(ruta->peli); 
  		printf("\n\nPrecione cualquier tecla para salir..."); 
  	
  		getchar(); 
  		system("clear");
   
     } else 	printf("###Pelicula no encontrada###"); 
 
}



