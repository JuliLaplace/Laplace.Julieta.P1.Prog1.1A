#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
/*
1.Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y devuelva el valor del
producto con un descuento del 5%. Realizar la llamada desde el main.

2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro y un
carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena *

3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha
estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main. *
**/
typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);
int ordenarArray(eNotebook lista[], int tam);
void mostrarNotebook(eNotebook unaNotebook);
int mostrarNotebooks(eNotebook notebooks[], int tam);



int main()
{


    float precio= 100.00;
    char cadena[]="Bienvenidos";
    char caracter = 'e';
    eNotebook notebooks[TAM]={
    {2000, "Intel", "Red Dragon", 20000.00},
    {2001, "AMD", "Dell", 35000.00},
    {2002, "IBM", "Mac", 10100.00},
    {2003, "Intel", "HP", 40500.00},
    {2004, "AMD", "HP", 10000.00},
    };

     //Ejercicio 1)
    printf("Ejercicio 1): \n");
    printf("El precio de %.2f pesos con el descuento del 5% quedaria en %.2f pesos", precio, aplicarDescuento(precio));
    printf("\n\n");

    //Ejercicio 2)
    printf("Ejercicio 2): \n");
    printf("Cantidad de veces que aparece el caracter %c es %d", caracter, contarCaracteres(cadena, caracter));
    printf("\n\n");

    //Ejercicio 3)
    printf("Ejercicio 3): \n");
    mostrarNotebooks(notebooks, TAM);
    if(ordenarArray(notebooks, TAM)){
        mostrarNotebooks(notebooks, TAM);
    }else{
        printf("No se pudo realizar el ordenamiento.\n");
    }

    return 0;
}


//Ejercicio 1)
float aplicarDescuento(float precio){

    float resultado;
    resultado = precio - (precio * 5/100);
    return resultado;

}


//Ejercicio 2)
int contarCaracteres(char cadena[], char caracter){

    int contadorCaracteres=0;
    if(cadena!=NULL && strlen(cadena)>0){
        for(int i =0; i<strlen(cadena); i++){
            if(cadena[i] == caracter){
                contadorCaracteres++;
            }
        }

    }


    return contadorCaracteres;
}

//Ejercicio 3)
int ordenarArray(eNotebook lista[], int tam){
    int todoOk=0;
    eNotebook aux;
    if(lista!=NULL && tam>0){
        for(int i =0; i<tam-1; i++){
            for(int j=i+1; j<tam; j++){
                if((strcmp(lista[i].marca, lista[j].marca)>0)|| ((strcmp(lista[i].marca, lista[j].marca)==0)&& lista[i].precio>lista[j].precio)){
                    aux = lista[i];
                    lista[i]=lista[j];
                    lista[j] = aux;
                }
            }
        }
        todoOk=1;
    }


return todoOk;
}

void mostrarNotebook(eNotebook unaNotebook){

 printf("%d        %10s         %10s            %.2f \n",unaNotebook.id,  unaNotebook.marca, unaNotebook.procesador, unaNotebook.precio);


}

int mostrarNotebooks(eNotebook notebooks[], int tam){
    int todoOk=0;
    if (notebooks!= NULL && tam>0){
        printf("*************************************************************************\n");
        printf("Id               Marca         Procesador              Precio           *\n");
        printf("*************************************************************************\n");
        for(int i=0; i<tam; i++){

            mostrarNotebook(notebooks[i]);

        }
        todoOk=1;
    }

return todoOk;

}
