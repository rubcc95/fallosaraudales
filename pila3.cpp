#include <stdio.h>

typedef struct TipoPila{
    int elemento[11];  //si no genero un espacio de más en el array...
    int posicion;
    void apilar(int apilable);
    void desapilar();
    void mostrar();
};

void TipoPila::apilar(int apilable){
    if(posicion==10){

    }
    else{
        elemento[posicion+1] = apilable; //...aquí, para posición = 9, el programa sustituye posicion por apilable a parte de elemento[10] :/
        posicion++;
        printf("\nElemento apilado");

    }
}


void TipoPila::desapilar(){
    if(posicion==0){
        printf("\nLa pila esta vacía! Prueba a Apilar.");
    }
    else{
        posicion--;
        printf("\nElemento desapilado");
    }
}

void TipoPila::mostrar(){
    if(posicion==0){
        printf("\nLa pila esta vacía! Prueba a Apilar.");
    }
    else{
        for(int i=1;i<=posicion;i++){
        printf("\nElemento %d: %d.",i,elemento[i]);
    }
    }
}


int main(){
    TipoPila pila;
    int apilable;
    char tecla;
    pila.posicion = 0;

    while(tecla!='C'){
        tecla='K';
        printf("\nApilar = A, Desapilar = D, Mostrar = M, Cerrar = C: ");
        while((tecla!= 'A')&&(tecla!= 'D')&&(tecla!= 'C')&&(tecla!= 'M')){
            scanf("%c",&tecla);
        }

        if(tecla=='A'){
            printf("\nElemento a apilar? ");
            scanf("%d",&apilable);
            pila.apilar(apilable);
        }
        if(tecla=='D'){
            pila.desapilar();
        }
        if(tecla=='M'){
            pila.mostrar();
        }
    }
    return 0;
}
