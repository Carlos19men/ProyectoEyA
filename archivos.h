#include <stdio.h> 
#include <LibPeliculas.h>


Pelicula* ExtraerDatos(char* cadena){
	int i = 0; 
	
	for(i = 0; i < strlen(cadena); i++){
		
	}
}




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
    
        guardar_pelicula(tabla, ExtraerDatos(linea););
    }
    
    fclose(archivo);
}


