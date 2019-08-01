/*Programaci�n y An�lisis de Algoritmos
**TAREA 4: CALCULAR DIAS ENTRE DOS FECHAS
**HAIRO ULISES MIRANDA BELMONTE
**VERSION 1.0
**05 DE SEPTIEMBRE DEL 2018*/

/* Limitante de c�digo
/* Este c�digo s�lo permite calcular fechas cuyo inicio es menor a la segunda fecha*/
/* Se utiliza "do while" en repetidas ocasiones, por lo tanto, sensible a un infinit loop*/

#include<stdio.h>


typedef struct { /*Estructura*/
	
	int dia;
	int mes;
	int year;
	
}calendario;

/*Prototipos de las funciones*/

void pedirFecha(calendario *fecha1, calendario *fecha2); /* ingresa dos fechas para contar los d�as entre ellas*/
void caso1(calendario *fecha1, calendario *fecha2); /*CASO 1: mes y a�o distinto entre fechas*/
void caso2(calendario *fecha1, calendario *fecha2); /*CASO 2: mismo a�o entre las dos fechas*/
void caso3(calendario *fecha1, calendario *fecha2); /*CASO 3: dia, mes y a�os distinto entre las dos fechas*/

int main()
{
	
	calendario fecha1, fecha2; /*Declarando estructura*/
	
	pedirFecha(&fecha1, &fecha2); /* ingresa dos fechas para contar los d�as entre ellas*/
	
	if(fecha1.mes==fecha2.mes && fecha1.year==fecha2.year ){ /*CASO 1: mes y a�o distinto entre fechas*/
		caso1(&fecha1, &fecha2);
	} else if (fecha1.year==fecha2.year){ /*CASO 2: mismo a�o entre las dos fechas*/
		caso2(&fecha1, &fecha2);
	} else { /*CASO 3: dia, mes y a�os distinto entre las dos fechas*/
		caso3(&fecha1, &fecha2);
	} //end if
		
	return 0;
	
} // end main

/*
 * Funci�n: caso1
 * ----------------------------
 *   Paso por referencia estructura. cuenta dias entre fechas cuando el  mes y a�o
 *	 son iguales.
 
 *   calendario *fecha1: puede ser d�a, mes y a�o 
 *   calendario *fecha2: puede ser d�a, mes y a�o
 *
 *   Funci�n tipo void. Imprime los d�as que pasaron entre dos fechas
 */

void caso1(calendario *fecha1, calendario *fecha2 )
{ /*CASO 1: mes y a�o iguales entre fechas*/
	
	printf("Dias que trascurrieron: %d", fecha2->dia - fecha1->dia); /* resta dias entre dos fechas con el mismo mes y a�o*/
	
} // end caso1

/*
 * Funci�n: caso2
 * ----------------------------
 *   Paso por referencia estructura. cuenta dias entre fechas cuando el a�o entre fechas son las mismas
 *	 
 
 *   calendario *fecha1: puede ser d�a, mes y a�o 
 *   calendario *fecha2: puede ser d�a, mes y a�o
 *
 *   Funci�n tipo void. Imprime los d�as que pasaron entre dos fechas
 */

void caso2(calendario *fecha1, calendario *fecha2)
{ /*CASO 2: mismo a�o entre las dos fechas*/

	/* variables auxiliares*/
	int i = 0;int j = 0;int aux = 0;
	/* contador de dias entre fechas*/
	int count = 0;
	/* array con fechas de finales de mes*/
	int finMes[4] = {29, 30 ,31, 28};
	
	/* Resta  d�as. dia fecha uno menos el �ltimo d�a del mes de fecha 1 */
	/* Esto hace que pasemos al proximo mes de ese mismo a�o (para fecha1)*/
	if(fecha1->mes==2){ 
		if(fecha1->mes == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){
			count = finMes[3] - fecha1->dia;	
		} else if (fecha1->mes == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){
			count = finMes[0] - fecha1->dia;	
		}
	} else if (fecha1->mes == 4  || fecha1->mes == 6 || fecha1->mes == 9 || fecha1->mes == 11){
		count = finMes[1] - fecha1->dia;
	} else {
		count = (finMes[2]-fecha1->dia);	
	} // end else
			printf("\n%d\n",count);
			
	/*Recorre meses y d�as, de fecha 1 m�s lo que ya se cont�, hasta un mes antes, �ltimo d�a, de fecha dos*/
	 
	for(j = fecha1->mes+1; j <= fecha2->mes-1; j++){ 
	
		if(fecha1->mes == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){
			for(i = 1; i<= 28; i++){
				count++;
			} // end for
		} else if (fecha1->mes == 2 && (fecha1->year % 4 != 0 && fecha1->year % 100 == 0 || fecha1->year % 400 != 0)){
			for(i = 1; i<= 29; i++){
				count++;
			}
		}else if (fecha1->mes == 4 || fecha1->mes == 6 || fecha1->mes == 9 || fecha1->mes == 11){
			for(i = 1; i <= 30; i++){ 
				count++;
			} // end for
		} else {
			for(i = 1; i <= 31; i++){
		    	count++;
			} // end for	
		} // end else	
	} // end for	
		 	
	
	/*suma del dia 1 del mes de fecha 2, al dia que quiero de la segunda fecha*/
	aux = fecha2->dia-1; 
	count += aux;
	
	printf("Dias que trascurrieron: %d\n",count); /*d�as que pasaron entre fechas*/
	
} // end caso2

/*
 * Funci�n: caso3
 * ----------------------------
 *   Paso por referencia estructura. cuenta dias entre fechas cuando el dia, mes y a�o son distintos
 *	 
 
 *   calendario *fecha1: puede ser d�a, mes y a�o 
 *   calendario *fecha2: puede ser d�a, mes y a�o
 *
 *   Funci�n tipo void. Imprime los d�as que pasaron entre dos fechas
 */

void caso3(calendario *fecha1, calendario *fecha2){ /*CASO 3: dia, mes y a�os distinto entre las dos fechas*/
	
	/* variables auxiliares*/
	int i = 0;int j = 0;int w = 0;int x = 0;
	int y = 0;int aux = 0;
	/* contador de dias entre fechas*/
	int count = 0;
	/* array con fechas de finales de mes*/
	int finMes[4] = {29, 30 ,31, 28};

	
	/* Resta  d�as. dia fecha uno menos el �ltimo d�a del mes de fecha 1 */
	/* Esto hace que pasemos al proximo mes de ese mismo a�o (para fecha1)*/	
	if(fecha1->mes==2){ 
		if(fecha1->mes == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){
			count = finMes[3] - fecha1->dia;	
		} else if (fecha1->mes == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){
			count = finMes[0] - fecha1->dia;	
		}
	} else if (fecha1->mes == 4  || fecha1->mes == 6 || fecha1->mes == 9 || fecha1->mes == 11){
		count = finMes[1] - fecha1->dia;
	} else {
		count = (finMes[2]-fecha1->dia);	
	} // end else
	
	/*Recorre meses y d�as, de fecha 1 m�s lo que ya se cont�, hasta ultimo mes de un a�o, �ltimo d�as de ese mes*/
	/*Esto con el fin de iniciar en un nuevo a�o 1/1/a�o*/
	for(j = fecha1->mes+1; j <= 12; j++){ 
	
		if(fecha1->mes == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){
			for(i = 1; i<= 28; i++){
				count++;
			} // end for
		} else if (fecha1->mes == 2 && (fecha1->year % 4 != 0 && fecha1->year % 100 == 0 || fecha1->year % 400 != 0)){
			for(i = 1; i <= 29; i++){
				count++;
			}
		}else if (fecha1->mes == 4 || fecha1->mes == 6 || fecha1->mes == 9 || fecha1->mes == 11){
			for(i = 1; i <= 30; i++){ 
				count++;
			} // end for
		} else {
			for(i = 1; i <= 31; i++){
		    	count++;
			} // end for	
		} // end else	
	} // end for	
	
		 	
	/*comienza con dia 1, mes 1, del a�o siguiente al que se declara la primera fecha,*/
	/* hasta un a�os antes de la fecha 2 �ltimo mes, �ltimo d�as*/		 
	for(j = fecha1->year+1; j <= fecha2->year-1; j++){ 
		for(i = 1; i <= 12; i++){
			if(i == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){ //ahora i es mi fecha mes
	 			for(w = 1; w <= 28; w++){
					count++;
				} // end for		
		 	} else if (i == 2 && (fecha1->year % 4 != 0 && fecha1->year % 100 == 0 || fecha1->year % 400 != 0)){ //ahora i es mi fecha mes
	 			for(w = 1; w <= 29; w++){
					count++;
				} // end for
			} else if (i == 4 || i == 6|| i == 9 || i == 11){
		 		for(x = 1; x <= 30; x++){
					count++;
				} // end for
			} else {
				for(y = 1; y <= 31; y++){
					count++;
				} // end for	
			} // end else	
		} // end else 	
	} // end for
		
	/*comienza en en el primer dia, primer mes de la segunda fecha y */
	/*cuenta hasta el mes que quiera de ese a�o */		
	for(j = 1;j <= fecha2->mes-1; j++){ 
 		if(j == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){
 			for(i = 1; i <= 28; i++){
				count++;
			} // end for
		} else if (j == 2 && (fecha1->year % 4 != 0 && fecha1->year % 100 == 0 || fecha1->year % 400 != 0)){
 			for(i = 1; i <= 29; i++){
				count++;
			} // end for
		} else if (j == 4  || j == 6 || j == 9 || j == 11){ 
			for(i = 1; i <= 30; i++){
				count++;
			} // end count
		} else {
			for(i = 1; i <= 31; i++){
				count++;
			} // end for	
		} // end else	
	} // end for 	
			
		
	/*suma del dia 1 al dia que quiero de la segunda fecha. */
	aux = (fecha2->dia) - 1;
	count = count + aux;
			
	printf("Dias que trascurrieron: %d",count); /*d�as que pasaron entre fechas*/
			
} // end caso3

/*
 * Funci�n: pedirFecha
 * ----------------------------
 *   Paso por referencia estructura. Pide n�meros racionales
 *	
 *   calendario *fecha1: puede ser d�a, mes y a�o 
 *   calendario *fecha2: puede ser d�a, mes y a�o
 *
 *   Funci�n tipo void. Imprime la fecha que ingres� el usuario en formato dd/mm/a�o
 */

void pedirFecha(calendario *fecha1, calendario *fecha2)
{  
	// restringir  a�o y if para febrero e if para los de 30 e if para los de 31
	do{
		do{
			/*Primera fecha (A�O)*/
			printf("\nProporciona una fecha de inicio (Anio a cuatro digitos):\n");
			scanf("%d", &fecha1->year);
		}while(fecha1->year <= 0 ); // end do while
		
		do{
			/*Segunda fecha(A�O)*/
			printf("Proporciona una fecha final (Anio a cuatro digitos):\n");
			scanf("%d", &fecha2->year);
		}while(fecha2->year <= 0); // end do while
		
		if(fecha1->year > fecha2->year){
			printf("La fecha de inicio debe ser mayo a la final\n");
		} // end if
	}while ( fecha1->year > fecha2->year); // end do while
	
	do{
		do{
			/*Primera fecha (MES)*/
			printf("Proporciona una fecha de inicio (Mes a un digito si es de enero a septiembre):\n");
			scanf("%d", &fecha1->mes);
		}while(fecha1->mes > 12 || fecha1->mes <= 0);
		do{
			/*Segunda fecha(MES)*/
			printf("Proporciona una fecha final (Mes a un digito si es de enero a septiembre):\n");
			scanf("%d", &fecha2->mes);
		}while(fecha2->mes > 12 || fecha2->mes <= 0);
		if(fecha1->year == fecha2->year && fecha1->mes > fecha2->mes){
			printf("La fecha de inicio debe ser mayo a la final\n");
		}
	}while(fecha1->year == fecha2->year && fecha1->mes > fecha2->mes);
	
	/*Primera fecha (DIA)*/
	if(fecha1->mes == 2 && (fecha1->year % 4 == 0 && fecha1->year % 100 != 0 || fecha1->year % 400 == 0)){
		do{
			printf("Proporciona una fecha de inicio (Dia):\n");
			scanf("%d", &fecha1->dia);
		}while(fecha1->dia > 28 || fecha1->dia <= 0); // end do while
	} else if(fecha1->mes == 2 && (fecha1->year % 4 != 0 && fecha1->year % 100 == 0 || fecha1->year % 400 != 0)){
		do{
			printf("Proporciona una fecha de inicio (Dia):\n");
			scanf("%d", &fecha1->dia);
		}while(fecha1->dia > 29 || fecha1->dia <= 0); // end do while		
	} else if (fecha1->mes == 4 || fecha1->mes == 6 || fecha1->mes == 9 || fecha1->mes== 11){
		do{
			printf("Proporciona una fecha de inicio (Dia):\n");
			scanf("%d", &fecha1->dia);
		}while(fecha1->dia > 30 || fecha1->dia <= 0); // end do while
	} else {
			do{
			printf("Proporciona una fecha de inicio (Dia):\n");
			scanf("%d", &fecha1->dia);
		}while(fecha1->dia > 31 || fecha1->dia <= 0); // end do while
	} // end else
	
	/*Segunda fecha(DIA)*/
	if(fecha2->mes == 2){
		do{
			printf("Proporciona  fecha final (Dia):\n");
			scanf("%d", &fecha2->dia);
		}while(fecha2->dia > 29 || fecha2->dia <= 0); // end do while
	} else if (fecha2->mes == 4 || fecha2->mes == 6|| fecha2->mes == 9 || fecha2->mes== 11){
		do{
			printf("Proporciona  fecha final (Dia):\n");
			scanf("%d", &fecha2->dia);
		}while(fecha2->dia > 30 || fecha2->dia <= 0); // end do while
	} else {
			do{
			printf("Proporciona  fecha final (Dia):\n");
			scanf("%d", &fecha2->dia);
		}while(fecha2->dia > 31 || fecha2->dia <= 0); // end do while
	} // end else
		
	/*Imprimiendo fechas*/
	printf("Fecha de inicio es:%d/%d/%d\n", fecha1->dia, fecha1->mes, fecha1->year); 
	printf("Fecha final es:%d/%d/%d\n", fecha2->dia, fecha2->mes, fecha2->year);
	

		
}// end pedirFecha




