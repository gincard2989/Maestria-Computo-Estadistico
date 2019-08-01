/*Programaci�n y An�lisis de Algoritmos
**TAREA 4: OPERACI�N CON N�MEROS COMPLEJOS.
**HAIRO ULISES MIRANDA BELMONTE
**VERSION 1.0
**05 DE SEPTIEMBRE DEL 2018*/

#include<stdio.h>

typedef struct{ /* estructura*/
	
	int real;
	int imaginario;
	
}operaciones;

/* Prototipos de las funciones*/
void pedirNumeros(operaciones *complejo1,  operaciones *complejo2); /* pide n�meros imaginarios por teclado*/
void suma(operaciones *complejo1, operaciones *complejo2); /* suma n�meros complejos*/
void resta(operaciones *complejo1,operaciones *complejo2); /* resta n�meros complejos*/
void multiplicacion(operaciones *complejo1,operaciones *complejo2); /* multiplica n�meros */
void division(operaciones *complejo1,operaciones *complejo2); /* divide n�meros complejos*/

int main()
{
	/*Declarando estructura*/
	operaciones complejo1, complejo2;
	
	/*Funciones*/
	pedirNumeros(&complejo1, &complejo2); /* pide n�meros complejos*/
	suma(&complejo1, &complejo2); /* suma n�meros complejos*/
	printf("\n");
	resta(&complejo1, &complejo2); /* resta n�meros complejos*/
	printf("\n");
	multiplicacion(&complejo1, &complejo2); /* multiplicacion n�meros complejos*/
	printf("\n");
	division(&complejo1, &complejo2); /* division n�meros complejos*/
	
	return 0;
} // end main

/*
 * Funci�n: pedirNumeros
 * ----------------------------
 *   Paso por referencia estructura. Pide n�meros complejos
 *	
 *   operaciones *racional1: complejo que puede ser numero real o numero imaginario 
 *   operaciones *racional2: complejo que puede ser numero real o numero imaginario  
 *
 *   Funci�n tipo void.
 */

void pedirNumeros(operaciones *complejo1, operaciones *complejo2 )
{ // pide n�mero complejos por teclado
	
	/* Primer n�mero imaginario*/
	printf("Introduzca el primero numero complejo:\n");
	printf("Parte real:\n");
	scanf("%d", &complejo1->real);
	printf("Parte imaginario:\n");
	scanf("%d", &complejo1->imaginario);
	
	/* Segundo n�mero imaginario*/
	printf("Introduzca el segundo numero complejo:\n");
	printf("Parte real:\n");
	scanf("%d", &complejo2->real);
	printf("Parte imaginario:\n");
	scanf("%d", &complejo2->imaginario);
		
}// end pedirNumeros

/*
 * Funci�n: suma
 * ----------------------------
 *   Paso por referencia estructura. Suma n�meros complejos
 *	
 *   operaciones *racional1: complejo que puede ser numero real o numero imaginario 
 *   operaciones *racional2: complejo que puede ser numero real o numero imaginario  
 *
 *   Funci�n tipo void.Imprime el resultado de la suma de n�meros complejos
 */

void suma(operaciones *complejo1,operaciones *complejo2)
{ /* suma n�meros imaginarios*/
		
	printf("La suma de los numeros complejos es: (%d %di)\n", complejo1->real + complejo2->real, 
	complejo1->imaginario + complejo2->imaginario); /* suma partes reales y partes complejas*/
	
}// end suma

/*
 * Funci�n: resta
 * ----------------------------
 *   Paso por referencia estructura. Resta n�meros complejos
 *	
 *   operaciones *racional1: complejo que puede ser numero real o numero imaginario 
 *   operaciones *racional2: complejo que puede ser numero real o numero imaginario  
 *
 *   Funci�n tipo void.Imprime el resultado de la resta de n�meros complejos
 */

void resta(operaciones *complejo1,operaciones *complejo2)
{ /*resta n�mero imaginarios*/
		
	printf("La resta de los numeros complejos es: (%d %di)\n", complejo1->real - complejo2->real, 
	complejo1->imaginario - complejo2->imaginario); /* resta partes reales y partes complejas*/
	
}// end resta

/*
 * Funci�n: multiplica
 * ----------------------------
 *   Paso por referencia estructura. Multiplica n�meros complejos
 *	
 *   operaciones *racional1: complejo que puede ser numero real o numero imaginario 
 *   operaciones *racional2: complejo que puede ser numero real o numero imaginario  
 *
 *   Funci�n tipo void.Imprime el resultado de la multiplicai�n de n�meros complejos
 */

void multiplicacion(operaciones *complejo1,operaciones *complejo2)
{ /* Multiplicaci�n de n�meros complejos*/
	
	/* variables auxiliares*/
	int real= 0;
	int imaginario = 0;
	
	/*Multiplicaci�n por propiedad distributiva*/
	real = complejo1->real*complejo2->real;
	imaginario = complejo1->real*complejo2->imaginario;
	imaginario += complejo1->imaginario*complejo2->real;
	real += (complejo1->imaginario*complejo2->imaginario)*(-1); /* i al cuadrado es igual a -1*/
	
	printf("La multiplicacion de los numeros complejos es: (%d %di)\n", real, imaginario);
	
}// end multiplicaci�n

/*
 * Funci�n: division
 * ----------------------------
 *   Paso por referencia estructura. Suma n�meros complejos
 *	
 *   operaciones *racional1: complejo que puede ser numero real o numero imaginario 
 *   operaciones *racional2: complejo que puede ser numero real o numero imaginario  
 *
 *   Funci�n tipo void.Imprime el resultado de la divisi�n de n�meros complejos
 */

void division(operaciones *complejo1,operaciones *complejo2)
{ /* Divisi�n de n�meros complejos*/
	
	/* variables auxiliares*/
	int realNum = 0;
	int realDen = 0;
	int imaginarioNum = 0;
	int imaginarioDen = 0;
	
	/* numerador Primer numero compleho por numerador del conjugado*/
	realNum = complejo1->real*complejo2->real;
	imaginarioNum = complejo1->real*((-1)*complejo2->imaginario);
	imaginarioNum += complejo1->imaginario*complejo2->real;
	realNum += (complejo1->imaginario*((-1)*complejo2->imaginario))*(-1); // i al cuadrado es igual a -1
	/* denominador Segundo numero compleho por denominador del conjugado*/
	realDen = complejo2->real*complejo2->real;
	imaginarioDen = complejo2->real*((-1)*complejo2->imaginario);
	imaginarioDen += complejo2->imaginario*complejo2->real;
	realDen += (complejo2->imaginario*((-1)*complejo2->imaginario))*(-1); // i al cuadrado es igual a -1
	realDen = realDen+imaginarioDen; //por el conjugado, ambos quedan como reales
	
	printf("La division de los numeros complejos es: ((%d %di)/%d)\n", realNum, imaginarioNum, realDen);
	
}// end division
