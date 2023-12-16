#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


Pelicula* ExtraerDatos(char* cadena){
	
	char* token = NULL; 
	Pelicula* newp = malloc(sizeof(Pelicula)); 
	
	
	
	//Extraemos cada campo de y lo asignamos a la estructura
	token = strtok(cadena,"/"); 

	strcpy(newp->titulo,token); 

	token = strtok(NULL,"/"); 
	
	strcpy(newp->estreno,token); 
	
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
	QuitarSalto(newp->sinopsis); 
	
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

    while (fgets(linea, sizeof(linea), archivo)){
        GuardarPelicula(tabla, ExtraerDatos(linea));
    }
    
    fclose(archivo);
}


