/*Tarea 3
*Version 1
*Ejercicio 5
*Solicitar un numero entero, Calcula el Cuadrado y el Cubo de los 5 siguientes n�meros.
*/
#include<stdio.h>
#include<math.h>
void exponential();


int main (){

	exponential();

}

void exponential(){
	int n,sum,sum2,cuad,cub,i,j;
		printf("digite un entero positivo para elevarlo al cuadrado y al cubo:");
		scanf("%i", &n);
	for(i=1;i<=5;i++){
		sum=n+i;
		cuad=pow(sum,2);
	    	printf("%i,",cuad);
	}
			printf("\n");
		for(j=1;j<=5;j++){
		sum2=n+j;
		cub=pow(sum2,3);
			printf("%i,",cub);
	}
}


