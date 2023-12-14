#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

//lista simple 
typedef struct nodo{
	Pelicula* peli; 
	struct nodo* next; 
}Node; 

typedef struct actores{
	char actor[30]; 
	struct actores *next; 
}Actores; 

typedef struct clasificacion{
	float valor; 
	struct clasificacion *next; 
}Clasificion; 

typedef char palabras[30]; 

//estructura de la pelicula 
typedef struct peliculas{
	palabras titulo, estreno, genero, duracion, director; 
	char sinopsis[150],clasificacion[2]; 
	
	Actores* actores; 
	Clasificion* votos;
}Pelicula; 



//estructuras para mostrar peliculas 

//mostra_pelicula
void mostrar_pelicula(Pelicula peli){	
	printf("Titulo:%s\n",peli.titulo);
	printf("Estreno: %s\n",peli.estreno); 
	printf("Genero: %s\n",peli.genero);  
	printf("Tiempo: %s\n",peli.duracion); 
	printf("Director: %s\n",peli.director); 
	printf("Actores: %s\n",peli.actores); 
	printf("Sinopsis: %s\n",peli.sinopsis); 
	printf("Clasifición: %s\n",peli.clasificacion); 
	printf("Calificacion: %d\n",peli.calificacion); 
	
}

//Mostrar 
void mostrar_todo(Node* listp){
	Node* p = listp; 
	for(; p; p = p->next){
		mostra_pelicula(p->peli); 
	}
}

//Nuevo nodo
Node* new_item(Pelicula* valor){
	Node* new = (Node* )malloc(sizeof(Node)); 
	
	new->peli = valor; 
	new->peli.clasificacion = NULL; 
	new->peli.actores = NULL; 
	new->next = NULL; 
	
	return new; 
}

//agregar al final 
Node* agg_end(Node* listp, Node* newp){

	//recorremos la lista 
	for(Node* p = listp ; p->next != NULL; p = p->next);
	
	p->next = newp; 
	 
	return listp; 
}

/*
//Funcion hash
int funcionHash(TablaHash* tabla, char* cadena) {

	int suma = 0; 
	
	//recorremos la cadena 
	for( int i = 0; i < strlen(cadena); i++){
		suma = suma + cadena[i]; 
	}

	//inidice de nuestra tabla 	
	return suma % tabla->capacidad; 
}
*/



//Funcion hash
int funcionHash(TablaHash* tabla) {
	
	//recorremos la cadena 
	for( int i = 0; i < strlen(tabla); i++){
		suma = suma + cadena[i]; 
	}

	//inidice de nuestra tabla 	
	return suma; 
}




//Estrutara de la tabla hash 

//elemento
typedef struct {
	int clave; 
	Node* cabecera; 
}Elemento; 

//Estructura de la tabla 
typedef struct {
    int capacidad;
    Elemento *tabla;
} TablaHash;

//función crear tabla hash 
TablaHash* crear_tabla_hash(int capacidad) {

	TablaHash *tablah = malloc(sizeof(TablaHash)); 
	
	tablah->capacidad = capacidad; 
	
	tablah->tabla = malloc(sizeof(Elemento) * capacidad); 

	for( int = 0; i < capacidad; i++){
		tablah->tabla[i].clave = -1; 
		tablah->tabla[i].cabecera = NULL; 
	}
	
	return tablah; 
} 

//funcion para guardar una pelicula 
void guardar_pelicula(TablaHash *tabla, Pelicula* valor) {
	//tabla cerrada 

    int indice = funcionHash(tabla,valor->titulo);
    
    //reservamos memoria para el nuevo elemento 
    Node* newp = (Node*)malloc(sizeof(Node));
    
    newp->peli = valor;
    newp->next = NULL;
    
    //Agregar a la tabla
    tabla->tabla[indice].clave = clave;
    tabla->tabla[indice].cabecera = add_end(tabla->tabla[indice].cabecera, newp);
}

//Registrar dats de pelicula
Pelicula* registrarPelicula() {
    Pelicula peli;
    
    printf("Ingrese el nombre de la pelicula: ");
    fgest(peli.titulo,30,stdin); 
    
    printf("Ingrese la fecha de estreno de la pelicula");
    fgest(peli.estreno,30,stdin);
    
    printf("Ingrese el tipo de genero de la pelicula");
    fgets(peli.genero,30,stdin);
    
    printf("Ingrese la duracion de la pelicula");
    fgets(peli.duracion, 30, stdin);
    
    printf("Ingrese el nombre del director de la pelicula");
    fgets(peli.directo, 30, stdin);
    
    printf("Ingrese el elenco de actores de la pelicula");
    fgets(peli.actores, 150, stdin);
    
    printf("Ingrese la sinopsis de la pelicula");
    fgets(peli.sinopsis, 150, stdin);
    
    printf("Ingrese la clasificacion de la pelicula");
    fgets(peli.clasificacion, 2, stdin);
    
    printf("Ingrese la calificacion de la pelicula");
    fgets(peli.clasificacion, 30, stdin);
    
    return peli;
}

//Buscar un elemento en la tabla 
Node* buscar_pelicula(TablaHash *tabla) {
	char titulo[30];

 	printf("Ingrese el nombre de la pelicula: ");
 	fgets(titulo, 30, stdin);
  
	int indice = funcionHash(tabla,titulo);
	
	Node* p = tabla->tabla[indice].cabecera; 
	
	for(; p ; p = p->next){
		if(strcmp(p->peli.titulo,titulo) == 0){
			return p; 
		}
	}
    
	return NULL; 
}

//Modificar una pelicula 
void modificarPelicula(HashTable *tabla) {

	//Buscamos la ruta de la pelicula 
	Node* ruta = buscar_pelicula(tabla);
  
  	//Si la ruta existe
  	if(ruta){ 	
  		printf("Pelicula encontrada:   \n\n"); 
  	
  		do{ //Modificamos la pelicula  
  
			mostrar_pelicula(ruta->peli); 
  		}while(modificar_campo(ruta)); 
  	}
  	
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
int modificar_campo(Node* ruta){
	
	int res = 2; 
	do{
		printf("Seleccione una opcion:  \n");
		printf("1- Modificar un campo  \n"); 
		printf("0- salir \n\n	-> "); 
		scanf("%d",&res); 
		
		if(res != 0) && (res != 1){
			system("clear"); 
			printf("##Dato no valido##"); 
		}
	}while((res != 0) && (res != 1)); 
	
	if(res = 0) return 0; //salimos  
	
	system("clear"); 
	
	if(res){
	
		//menu de campos a modificar 
		do{
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
			system("clear"); 
			
			if(res >= 1) && (res <= 7) return 1; //hemos hecho una correccion
			
			if(res = 0) return 0; //salimos
			
		}while(res < 0) || (res > 7); 	
	}
}



void eliminarPelicula(HashTable *tabla) {

	//buscamos la ruta de la pelicula 
    Node* ruta1 = buscar_pelicula(tabla);
    
    //Si la ruta existe                                              
    if(ruta){
		int clave = funcionHash(ruta->titulo); 
		int indice = clave % tabla->capacidad; 
		
		Node* ruta2 = tabla->tabla[indice].cabecera;  // primer elemento
		
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

void consultarPelicula(HashTable *tabla, char *titulo) {
     //buscamos la dirección de la pelicula 
     Node* ruta = buscar_pelicula(tabla); 
     
     if(ruta){
     	mostrar_pelicula(ruta->peli); 
  		printf("\n\nPrecione cualquier tecla para salir..."); 
  	
  		getchar(); 
  		system("clear");
   
     } else 	printf("###Pelicula no encontrada###"); 
 
}



void calificarPelicula(HashTable *tabla) {

	Node* ruta = buscar_pelicula(tabla); 
	
	if(ruta){
		printf("Pelicula:   "); 
		mostrar_pelicula(ruta->peli); 
		
		printf("Ingrese la calificación que desea agregar a la pelicula:   "); 
		
		float clasi; 
		
		scanf("%f",&clasi); 
		
		Clasificion* nueva = malloc(sizeof(Clasificion)); 
		
		Clasificion* p = ruta->votos; 
		
		//Nos movemos por la listas de los votos de la clasificacion
		
		for(; p->next != NULL; p = p->next); 
		
		p->next = nueva; 
	
	}  else  printf("Pelicula no encontrada..."); 
     
}

float calcular_clasificacion(Clasificion* lista){
	
	Clasificion* p = lista; 
	float total = 0; 
	int i = 0; 
	
	for(; p ; p = p->next){
		total += p->valor; 
		i++; 
	}
	
	return total / i; //promedio de las clasicaciones 
}

void listarPeliculas(HashTable *tabla) {
    // Aquí puedes añadir código para mostrar información de todas las películas registradas en la tabla
}

void generarRecomendaciones(HashTable *tabla, char *genero, int anio, char *director, char *actores) {
    // Aquí puedes añadir código para generar y mostrar las recomendaciones de películas
}


Pelicula 




//recibe la tabla ya creada   
void inicializarTabla(HashTable *tabla) {

    // Aquí puedes añadir código para cargar las películas desde el archivo proporcionado por el docente
    FILE *archivo;
    char linea[1000];
    
    archivo = fopen("archivo_peliculas.txt", "r");

    if(archivo == NULL){
       printf("No se pudo abrir el archivo.\n");
       return;
    }

    while (fgets(linea, sizeof(linea), archivo)){

	
        
        Pelicula nuevaPelicula = ExtraerDatos(linea);
    
        guardar_pelicula(tabla, nuevaPelicula);
    }
    
    fclose(archivo);
}



int main(){


return 0; 
}

