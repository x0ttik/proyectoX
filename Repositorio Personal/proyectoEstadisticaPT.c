// PROYECTO ESTADISTICA AVANZADA
// TORAYA GONZALEZ PAUL EDUARDO   1290319

#include <stdio.h>
#include <math.h>

// FUNCIONES

// Funcion para que el usuario introduzca un archivo existente


// Funcion para que el usuario ingrese los datos 


// Funcion MODA


// Funcion MEDIA


// Funcion MEDIANA


// Funcion MEDIA RECORTADA


int main(){

    // Variables
    int opcion = 0;
    int n = 0;
    float suma = 0;
    float arreglo[100];
    

    // Primero realizaremos una opcion al usuario para ver si quiere ingresar un archivo de texto o ingresar los valores manualmente
    
    printf("---- ¿QUE DESEA REALIZAR? ---- \n");
    printf("Ingresar archivo de texto ---- [1] \n");
    printf("Ingresar los valores manualmente ---- [2] \n");
    scanf("%d", &opcion);

    if (opcion == 1){ // Ingresar archivo de texto
        printf("Hola mundo \n");
    }
    else { // Ingresar valores manualmente 
        printf("Ingrese la cantidad de valores a ingresar: \n");
        scanf("%d" , &n);

        for (int i = 0; i < n; i++){
            printf("Ingrese el valor: \n");
            scanf("%f" , &arreglo[i]);

            suma = suma + arreglo[i];
        }

        printf("\n ---- Valores ingresados ---- \n");

        printf("\n");

        for ( int i = 0; i < n ; i++){
            printf(" %.2f - ", arreglo[i]);
        }

        printf(" \n -------------------- ");
        // printf("\n Suma: %.2f \n", suma);
        
    }

    // MODIFICAR MODA

    // MODA

    // Arreglo para guardar cantidad de veces de numero
    int arregloCantidad[100];
    int contador = 0;
    //int tamanioArreglo = 0;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(arreglo[i] == arreglo[j]){
            contador++; 
            }
        } 
        arregloCantidad[i] = contador; 
    }

    // Buscar el índice del valor más frecuente (moda)
    int maxFrecuencia = 0;
    int indiceModa = 0;

    for (int i = 0; i < n; i++) {
        if (arregloCantidad[i] > maxFrecuencia) {
            maxFrecuencia = arregloCantidad[i];
            indiceModa = i;
        }
    }


    printf(" \n -------------------- \n ");    
    printf("La moda es: %.2f \n", arreglo[indiceModa]);


    // contador 
    // ciclo for, recorrer todos los numeros 

    contador = 0;
    float media = 0;

    for(int i = 0; i < n; i++){
        if(arreglo[i] == arreglo[i + 1]){
            contador = contador + 1;
        }
    }

    // MEDIA

    media = suma / n;

    printf(" -------------------- ");
    printf("\n La media es: %.2f \n", media);
    printf(" -------------------- \n");

    // MEDIANA

    // CICLO DE BURBUJA 
    for (int i = 0; i < n - 1; i++) {
        // Últimos i elementos ya están en su lugar
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                float temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }

    for ( int i = 0; i < n ; i++){
        printf(" %.2f - ", arreglo[i]);
    }
    printf(" \n -------------------- \n");

    //  Variables

    float mediana = 0;
    int variableTemp = 0;
    
    if( n % 2 == 0){

        // n es par ya que no hay residuo 
        variableTemp = n / 2;
        // printf(" --- %f --- %f y %f --- ", arreglo[1], arreglo[variableTemp] , arreglo[variableTemp + 1]);
        mediana = ( arreglo[variableTemp ] + arreglo[variableTemp - 1] ) / 2;
        printf("\n Mediana: %.2f \n", mediana);
    }

    else{
        variableTemp = (n / 2); // Como es valor entero automaticamente se redonde a la posicion correcta
        mediana = arreglo[variableTemp];
        printf("Mediana: %.2f \n", mediana);
    }    

    printf(" -------------------- \n ");
    printf(" -------------------- \n ");

    // Variables

    opcion = 0;
    float mediaRecortada = 0, mediaRecortadaOriginal = 0;
    // float valorRecortar = 0;
    float porcentaje = 0;


    // MEDIA RECORTADA
    printf(" -------- MEDIA RECORTADA -------- \n");
    printf(" -------------------- \n ");

    printf("Desea agregar:\n");
    printf("Porcentaje ----- [1] \n");
    printf("Cantidad ------- [2] \n");
    scanf("%d", &opcion);

    switch (opcion){
        int recorte = 0;

    case 1: // Recorte por medio de porcentaje 
        printf("Ingrese el porcentaje a recortar: \n");
        scanf("%d", &recorte);
        printf(" -------------------- \n ");

        porcentaje = (float)recorte / 100;

        mediaRecortadaOriginal = n * porcentaje; 

        // TEMPORAL // Ver que media recortada se imprima bien 
        printf(" \n Porcentaje: %.2f \n", porcentaje);

        // TEMPORAL // Ver que media recortada se imprima bien 
        printf(" \n Media recortada: %.2f \n", mediaRecortadaOriginal);

        // Temporal
        mediaRecortada = mediaRecortadaOriginal / 2;
        
        // TEMPORAL // Ver que media recortada se imprima bien  
        printf(" \n Media recortada: %.2f \n", mediaRecortada);

        int nTemporal = 0;
        nTemporal = n - mediaRecortadaOriginal; // Creamos variable de nuevo (n = tamanio del arreglo - valores a recortar)

        // TEMPORAL // Ver que media recortada se imprima bien 
        printf(" \n n temporal: %d \n", nTemporal);

        mediaRecortada = mediaRecortadaOriginal / 2;

        // Ciclo para eliminar el recorte del inicio del arreglo original
        printf(" -------------------- \n ");
        for(int i = 0; i < mediaRecortada; i++){
            arreglo[i] = 0;
        }
        printf(" -------------------- \n ");

        // Ciclo para eliminar el recorte del final del arreglo original
        for(int i = n - mediaRecortada; i <  n; i++){
            arreglo[i] = 0;
        }

        suma = 0; 
        // Hacemos la suma del nuevo arreglo;
        for(int i = 0; i < n; i++){
            suma = suma + arreglo[i];
        }

        // TEMPORAL // Ver que suma se imprima bien 
        printf(" \n Suma: %.2f \n", suma);
        

        // Verificamos que se guarde correctamente el arreglo
        for(int i = 0; i < n; i++){
            printf("%.2f - ", arreglo[i]);

        }
        mediaRecortada = 0;

        mediaRecortada = suma / nTemporal;


        printf(" \n -------------------- \n ");
        printf("La media recortada a un %d porciento es: %.2f \n" , recorte, mediaRecortada);
        break;
    
    case 2: // Recorte por medio de cantidad
        printf("Ingrese la cantidad a recortar: \n");
        scanf("%d", &recorte);

        mediaRecortada = recorte / 2;

        nTemporal = 0;
        nTemporal = n - recorte; // Creamos variable de nuevo n (n = tamanio del arreglo - valores a recortar)


        // Ciclo para eliminar el recorte del inicio del arreglo original
        printf(" -------------------- \n ");
        for(int i = 0; i < mediaRecortada; i++){
            arreglo[i] = 0;
        }
        printf(" -------------------- \n ");

        // Ciclo para eliminar el recorte del final del arreglo original
        for(int i = n - mediaRecortada; i <  n; i++){
            arreglo[i] = 0;
        }

        suma = 0; 
        // Hacemos la suma del nuevo arreglo;
        for(int i = 0; i < n; i++){
            suma = suma + arreglo[i];
        }

        // TEMPORAL // Ver que suma se imprima bien 
        printf(" \n Suma: %.2f \n", suma);
        

        // Verificamos que se guarde correctamente el arreglo
        for(int i = 0; i < n; i++){
            printf("%.2f - ", arreglo[i]);

        }
        mediaRecortada = 0;

        mediaRecortada = suma / nTemporal;

        printf(" \n -------------------- \n ");
        printf("La media recortada a un %d porciento es: %.2f \n" , recorte, mediaRecortada);
        break;

    default:
        printf("Valor invalido \n");
    }
    



    return 0;
}