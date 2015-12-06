#include <stdio.h>    //LOS ERRORES EN MAYÚSCULAS      //en minúsculas comentarios sobre e supues (no) funcionamiento del código.

typedef struct TipoPila{
    int posicion;
    int valor;
    void apilar();
    void desapilar();
};


void TipoPila::apilar(){
    printf("\nInserte el valor a apilar: ");
    scanf("%d",&valor);
    for(int i=1;i<=10;i++){ //sumamos 1 a la posición del resto de elementos apilados.
        if(elemento[i].posicion!=0){  //AQUÍ ME SALE UN ERROR AL COMPILAR, DEBIDO A QUE LLAMO A ELEMENTO... COMO PUEDO MODIFICAR LA POSICIÓN DE CADA ELEMENTO ENTONCES :/
            elemento[i].posicion--;
        }
    }
    posicion = 1; //ponemos el elemento recién apilado en primera posición.
}

void TipoPila::desapilar(){
    for(int i=1;i<=10;i++){ //restamos 1 a la posición de todos los elementos apilados.
        if(elemento[i].posicion!=0){  //MISMO ERROR
            elemento[i].posicion--;
        }
    }
}

int main(){

    typedef TipoPila elemento[10];
    char tecla;
    bool variablecontrol=true;

    while(tecla!='C'){
        printf("\nApilar = A, Desapilar = D, Cerrar = C: ");
        while((tecla!= 'A')&&(tecla!= 'D'&&(tecla!= 'C'))){
            scanf("%c",&tecla);
        }

        if(tecla=='A'){
            for(int i=0;i<=10;i++){ //buscamos una celda vacía (posision=0).
                if(elemento[i].posicion==0&&variablecontrol==true){ //ERROR:EXPECTED PRIMARY-EXPRESION BEFORE '[' TOKEN... QUE?               //debido a que c+- no acepta una sentencia break dentro del for, uso un booleano para cortar el if.
                    elemento[i].apilar(); //ERROR:EXPECTED UNQUALIFIED-ID BEFORE '[' TOKEN. TIENE ERROR CADA VEZ QUE OPERA CON EL ARRAY.                //si existe apilamos en ella.
                    variablecontrol = false;
                }
            }
            printf("\nTodas las celdas de la pila están llenas. Desapila primero."); //si no la encontramos informamos.
        }
        if(tecla=='D'){
            elemento[1].desapilar(); //ERROR:EXPECTED UNQUALIFIED-ID BEFORE '[' TOKEN.        //da igual sobre que elemento desapilar. El resultado es indiferente. Desapilamos siempre con array.
          }
    }
    return 0;
}
