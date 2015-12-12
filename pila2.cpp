#include <stdio.h>

typedef struct TipoPila{
    int elemento[10];
    void apilar(int apilable);
    void desapilar();
    void mostrar();
};

void TipoPila::apilar(int apilable){
    if(elemento[10]==0){
        for(int i=10;i>=1;i--){
            elemento[i] = elemento[i-1];
        }
        elemento[1] = apilable;
        printf("Elemento apilado correctamente");
    }
    else{
        printf("\nLa pila esta llena! Prueba a Desapilar.");
    }
}


void TipoPila::desapilar(){
    for(int i=1;i<=10;i++){
        elemento[i] = elemento[i+1];
    }
    elemento[10]=0;
    printf("Elemento desapilado correctamente");
}

void TipoPila::mostrar(){
    for(int i=1;i<=10;i++){
        if(elemento[i]!=0){
            printf("\nElemento %d: %d.",i,elemento[i]);
        }
    printf("\n");
    }
}


int main(){
    TipoPila pila;
    int apilable;
    char tecla;
    for(int i=1; i<=10;i++){pila.elemento[i]=0;}

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
