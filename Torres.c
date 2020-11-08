#include <stdio.h>
#include <stdlib.h>   
 
 
#define TORRE_INICIAL 1
#define TORRE_AUXILIAR 2
#define TORRE_FINAL 3
 
int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal);
void muestra();
 
int t1=0,t2=0,t3=0,i,maxdiscos;
char disko='*';
 
int main()
{
    int cantDiscos, movimientos, moves;
     
    
  
    
 printf("Cantidad de discos a mover: ");
 scanf("%d", &cantDiscos);
 printf("\n_________________________________________ \n");
 
 
 t1=cantDiscos;
 maxdiscos = cantDiscos;
 printf("La Torre:\n");
 muestra();
 printf("\n_________________________________________\nLa serie de movimientos a realizar es:\n");
 movimientos = hanoi(cantDiscos, TORRE_INICIAL, TORRE_AUXILIAR, TORRE_FINAL);
 printf("\n\nSe realizaron en total %d movimientos\n", movimientos);
 printf("\n\nMovimientos calculados %i\n", moves);
 
 return 0;
}
 
int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal)
{
    static int movimientos = 0;
     
 if(numDiscos == 1) // solo hay un disco
 {
  printf("\n\n%d)Mover el disco superior de la torre %d a la torre %d\n", movimientos+1, torreInicial, torreFinal);
  movimientos++;
 
        if(torreInicial==1)
            t1--;
        if(torreInicial==2)
            t2--;
        if(torreInicial==3)
            t3--;
        if(torreFinal==1)
            t1++;
        if(torreFinal==2)
            t2++;
        if(torreFinal==3)
            t3++;
 
  muestra();
 }
 else // mas de un disco
 {
  hanoi(numDiscos - 1, torreInicial, torreFinal, torreAuxiliar);
  printf("\n\n%d)Mover el disco superior de la torre %d a la torre %d\n", movimientos+1, torreInicial, torreFinal);
  movimientos++;
 
        if(torreInicial==1)
            t1--;
        if(torreInicial==2)
            t2--;
        if(torreInicial==3)
            t3--;
        if(torreFinal==1)
            t1++;
        if(torreFinal==2)
            t2++;
        if(torreFinal==3)
            t3++;
 
  muestra();
  hanoi(numDiscos - 1, torreAuxiliar, torreInicial, torreFinal);
 }
 return movimientos;
}
 
void muestra(){
    printf("\n\tTorre1:");
 for(i=1;i<=t1;i++){
        printf("%c",disko);
 }
    printf("\n\tTorre2:");
 for(i=1;i<=t2;i++){
        printf("%c",disko);
 }
    printf("\n\tTorre3:");
 for(i=1;i<=t3;i++){
        printf("%c",disko);
 }
}

