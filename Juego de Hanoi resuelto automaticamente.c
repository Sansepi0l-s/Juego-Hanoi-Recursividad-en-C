#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
void presentar(int *ptr,int fils,int cols,int nf){
	int f,c,i,x;
	int G=218;
	for(c=cols-1;c>=0;c--){
		for(f=0;f<fils;f++){
			x=(nf-ptr[cols*f+c])/2;
			for(i=0;i<x;i++){
				printf(" ");
			}
			for(i=0;i<ptr[cols*f+c];i++){
				printf("%c",G);
			}
			for(i=0;i<x;i++){
				printf(" ");
			}
			printf("\t");
		};
		printf("\n");
	};
}
void desplazamiento(int *ptr2,int fil,int col,int numerofinal, int filorigen, int fildestino){
	int cOrigen=col-1,cDestino=col-1;
	while(cOrigen>=0 && ptr2[col*filorigen+cOrigen]==0){
		cOrigen--;
	}
	if(cOrigen<0){
		cOrigen=0;
	}
	while(cDestino>=0 && ptr2[col*fildestino+cDestino]==0){
		cDestino--;
	}
	ptr2[col*fildestino+cDestino+1]= ptr2[col*filorigen+cOrigen];
	ptr2[col*filorigen+cOrigen]=0;
	
	presentar(ptr2,fil,col,numerofinal);
}
void Juego(int *ptr3,int fila,int columna,int disco, int nfinal, int O,int A, int D){
	if(disco==1){
		system("cls");
		printf("\t---Simulacion en curso---...\n");
		desplazamiento(ptr3,fila,columna,nfinal,O,D);
		if(columna<=5 && columna>7)sleep(1);
		else if(columna<=10)sleep(1);
		else if(columna<=15)sleep(0.9);
		else if(columna>15)sleep(0.9); 
	}
	else{
		Juego(ptr3,fila,columna,disco-1,nfinal,O,D,A);
		system("cls");
		printf("\t---Simulacion en curso---...\n");
		desplazamiento(ptr3,fila,columna,nfinal,O,D);
		if(columna<=5)sleep(1);
		else if(columna<=10)sleep(1);
		else if(columna<=15)sleep(0.9);
		else if(columna>15) sleep(0.9);
		Juego(ptr3,fila,columna,disco-1,nfinal,A,O,D);
	}
}
int main() {
	int fil=3,col,*tab=NULL;
	int f,c,disc=1,un;
	int movimientos;
	printf("\t***--Simulacion--***\n");
	printf("      Diga el numero de Discos:");
	scanf("%i",&col);
	while(col==0){
		printf("\t   Sin Discos!\n");
		printf("   Intente con otro valor mayor que 0\n");
		printf("      Diga el numero de Discos:");
		scanf("%i",&col);
	}
	while(col<0){
		printf("Este Valor numerico es invalido para el juego!\n");
		printf("Condicion: (Discos>=1), intente con otro valor\n");
		printf("      Diga el numero de Discos:");
		scanf("%i",&col);
	}
	while(col>=12){
		printf("\n Pantalla insuficiente para esta simulacion!\n");
		printf("   maximo para simulacion: 11 Discos\n");
		printf("      Diga el numero de Discos:");
		scanf("%i",&col);
	}
	
	tab=(int*)malloc(sizeof(int)*fil*col);
	for(f=0;f<fil;f++)
		for(c=col-1;c>=0;c--)
			if(f==0){
				tab[col*f+c]=disc;
				disc+=2;
			}
			else{
				tab[col*f+c]=0;
				
			}
			un=disc;
			presentar(tab,fil,col,un);
			printf("\tResolviendo...");
			sleep(2);
			Juego(tab,fil,col,col,un,0,1,2);
			printf("\n");
	
	
	printf("\t  --JUEGO RESUELTO-- :)\n");
	movimientos=pow(2,col)-1;
	printf("El numero de movimientos realizados por la simulacion es: %d",movimientos);
}

