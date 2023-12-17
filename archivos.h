#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


Pelicula* ExtraerDatos(char* cadena, int registro){
	
	char* token = NULL; 
	Pelicula* newp = malloc(sizeof(Pelicula)); 
	
	
	
	//Extraemos cada campo de y lo asignamos a la estructura
	token = strtok(cadena,"/"); 

	strcpy(newp->titulo,token); 

	token = strtok(NULL,"/"); 
	
	newp->estreno = atoi(token); 
	
	token = strtok(NULL,"/"); 
	
	
	strcpy(newp->genero,token); 
	
	token = strtok(NULL,"/"); 
	
	strcpy(newp->duracion,token); 
	
	token = strtok(NULL,"/"); 
	
	strcpy(newp->director,token);
	 
	token = strtok(NULL,"/"); 
	
	strcpy(newp->actores,token); 
	
	token = strtok(NULL,"/"); 
	
	strcpy(newp->sinopsis,token); 
	
	token = strtok(NULL,"/"); 

	strcpy(newp->clasificacion,token); 
	
	token = strtok(NULL,"/"); 
	
	newp->CalifiTotal = strtof(token,NULL); 
	
	newp->votos = 1; 
	
	newp->registro = registro; 
	return newp; 
}




//recibe la tabla ya creada   
void InicializarTabla(TablaHash *tabla) {

    // Aquí puedes añadir código para cargar las películas desde el archivo proporcionado por el docente
    FILE *archivo;
    char linea[1000];
    
    archivo = fopen("peliculas.txt", "r");

    if(archivo == NULL){
       printf("No se pudo abrir el archivo.\n");
       return;
    }
    
    int i = 0; 

    while (fgets(linea, sizeof(linea), archivo)){
        GuardarPelicula(tabla, ExtraerDatos(linea,++i));
    }
    
    fclose(archivo);
}

void GuardarEnArchivo(TablaHash* tabla){
	
	//Creamos un nuevo archivo 
	
	FILE* archivo = fopen("peliculas.txt","w"); 
	
	//verificamos si el archivo existe
	if(!archivo){
		printf("error de apertura\n"); 
		return; 
	}
	
	//recorremos la tabla 
	for(int i = 0; i < tabla->capacidad; i++){
		
		//recorremos las listas 
		NodeLista *p = tabla->tabla[i].cabecera; 
		while(p){
			char clasificacion[5]; 
			char estreno[6]; 
			sprintf(estreno,"%d",p->peli->estreno); 
			sprintf(clasificacion,"%.1f",(p->peli->CalifiTotal/p->peli->votos)); 
			
			//Escribos la estrucutra de las peliculas en el archivo 
			fprintf(archivo,"%s/%s/%s/",p->peli->titulo,estreno,p->peli->genero); 
			fprintf(archivo,"%s/%s/%s/",p->peli->duracion,p->peli->director,p->peli->actores); 
			fprintf(archivo,"%s/%s/%s\n",p->peli->sinopsis,p->peli->clasificacion,clasificacion); 
			p = p->next; 
		}
	}
	
	fclose(archivo); 
}
			
			
	
	
	
	
	
	
	
	

