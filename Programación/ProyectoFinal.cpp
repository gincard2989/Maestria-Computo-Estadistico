/*Programaci�n y An�lisis de Algoritmos
**PROYECTO FINAL: Rcpp y C. APLICACI�N
** A T�CNICA DE REMUESTREO BOOTSTRAP
**HAIRO ULISES MIRANDA BELMONTE
**VERSION 1.0
**20 DE NOVIEMBRE DEL 2018*/


/* Headers necesarios para el funcionamiento*/
#include <Rcpp.h>
using namespace Rcpp;

/*
 * Funci�n: quicksort
 * ----------------------------
 *   Algoritmo de ordenamiento Quicksort
 *	 Ordenamiento de menos a mayor.
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)
 * 			 l  -> Entero que recibe el 0
 *			n1  -> Tama�o de muestra menos uno.
 *  
 *   Return: - 
 *
 *   Funci�n tipo Void.
 */
 
/* Header para la exportacion */
// [[Rcpp::export]]
void quicksort(NumericVector xx1, int l, int r)
{
	/*Variables*/
	double v,i,j,t;
	
	/*Ordenamiento*/
	if (r > l){
    	v = xx1[r];
    	i= l-1;
    	j = r;
    	for(;;){
       		while(xx1[++i] < v);
        	while(xx1[--j] > v);

        	if(i >= j)
            break;
        	t=xx1[i];
        	xx1[i]=xx1[j];
        	xx1[j]=t;
    	}/*end for*/

    	t=xx1[i];
    	xx1[i]=xx1[r];
    	xx1[r] = t;

    	quicksort(xx1,l,i-1);
    	quicksort(xx1,i+1,r);
    	
	}/*end if*/
	
} // end quicksort

/*
 * Funci�n: media
 * ----------------------------
 *   Estima media muestra�
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)

 *   Return: variable double con media muestral 
 *
 *   Funci�n tipo double.
 */

/* Header para la exportacion */
// [[Rcpp::export]]
double  media(NumericVector xx1)
{
	/**Variables*/
	int i = 0;
	double auxSuma = 0.0;
	double mediaBostrap = 0.0;
	
	/*Tama�o de muestra*/
	int n1 = xx1.size();
	
    /*Media*/                 
	for (i = 0; i < n1; i++) {
 		auxSuma = auxSuma + xx1[i];
	}/*end for*/
	
 	mediaBostrap = auxSuma / n1;
 	
	return mediaBostrap; /*Regresa Media*/
                     
} // end media

/*
 * Funci�n: varianza
 * ----------------------------
 *   Estima varianza muestral.
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)
 *
 *   Return: variable double con varianza muestral 
 *
 *   Funci�n tipo double.
 */

/* Header para la exportacion */
// [[Rcpp::export]]

double varianza(NumericVector xx1)
{	
	/*Variables*/	
 	double mediaBostrap = 0.0; int i = 0;
 	double auxVar = 0.0; double varBostrap = 0.0;
 	/*Tama�o de muestra*/
 	int n1 = xx1.size();
 	/*Media Datos*/
 	mediaBostrap = media(xx1);
 	
 	/*Suma diferencia de cuadrados*/
 	for (i = 0; i < n1; i++){
		auxVar = auxVar + pow((xx1[i] - mediaBostrap), 2);
  	}/*end for*/
  	
  	
 	varBostrap = auxVar / ((double)n1-1);
 	
  	return varBostrap; /*Regresa Varianza*/
  	
} // end varianza

/*
 * Funci�n: sd
 * ----------------------------
 *   Estima desviaci�n est�ndar muestral.
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)
 *
 *   Return: variable double con desviaci�n est�ndar muestral 
 *
 *   Funci�n tipo double.
 */

/* Header para la exportacion */
// [[Rcpp::export]]

double sd(NumericVector xx1)
{	
 	/*Utiliza funci�n Varianza*/
  	return sqrt(varianza(xx1)); /*Regresa Desviaci�n est�ndar*/
  	
} // end varianza

/*
 * Funci�n: mediana
 * ----------------------------
 *   Estima mediana muestral.
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)
 *
 *   Return: variable double con mediana muestral 
 *
 *   Funci�n tipo double.
 */
 
/* Header para la exportacion */
// [[Rcpp::export]]
double  mediana(NumericVector xx1)
{
	/*Tama�o de muestra*/
	int n1 = xx1.size();
	/*Algoritmo de ordenamiento Quicksort*/
	quicksort(xx1, 0, n1-1);
	/*Mediana. Tama�o de muestra par e impar*/
	if(n1%2==0) {
	return((xx1[n1/2] + xx1[n1/2 - 1]) / 2.0);
	} else {
	return xx1[n1/2];
	} /*end else*/    
	             
} // end mediana

/*
 * Funci�n: bootstrapVarianza
 * ----------------------------
 *   Estima error est�ndar del est�distico de la varianza  muestral.
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)
 *			 B  -> Variable tipo entero con el n�mero de simulaci�n
 *
 *   Return: Lista con dos outputs.
 *			 1) Error est�ndar estimado del estad�stico 
 *			 1) Estad�sticos bootstrap generado por remuestreo bootstrap
 *
 *   Funci�n tipo List.
 */

// Rcpp wrapper for C++ function
// [[Rcpp::export]]
                        
 List bootstrapVarianza(NumericVector x1, int B)
 { 
 	/*Variables*/
	int n1 = 0;  int simulacion = 0; int i = 0; int j = 0; 
	double auxSuma = 0.0; double mediaBostrap = 0.0;
	double auxVar = 0.0; double varBostrap = 0.0; 
	double sdBostrap = 0;
    /*Tama�o de Muestra*/                     
	n1 =  x1.size(); 
	/*N�mero de simulaci�n*/  
	simulacion = B; 
	/*Vector guarda remuestreo*/
	NumericVector xx1(n1);
	/*vector guarda las B estimaciones del estad�stico*/
	NumericVector estBoot(B);

	time_t t;
	srand((unsigned)time(&t));
	
	/*Re-muestreo boostrapt tama�o n1, B veces*/
	for (i = 0; i < simulacion; i++){
		for(j=0;j< n1;j++){
			xx1[j] = x1[rand()%n1];
 		} /*end for*/
 		estBoot[i] = varianza(xx1);
	}/*end for*/
	
	/*Media de los B estad�sticos*/ 
 	for (i = 0; i < simulacion; i++){
		auxSuma = auxSuma + estBoot[i];
 	}
	
	mediaBostrap = auxSuma / simulacion;
 
	/*Suma de cuadrados de los B estad�sticos*/ 
	for (i = 0; i < simulacion; i++){
		auxVar = auxVar + pow((estBoot[i] - mediaBostrap), 2);
 	}
 	
 	/*Varianza estimada por bootsrap*/ 
	varBostrap = auxVar / (simulacion);
 	/*error est�ndar estimado por bootsrap*/
	sdBostrap = sqrt(varBostrap);
 	/*Regresa lista con error estandar del estad�stico y estad�sticos del remuestreo*/
	 return Rcpp::List::create(Rcpp::Named("se") = sdBostrap,
                          Rcpp::Named("tboot") = estBoot); 

 }/*end bootstrapVarianza*/
 
 /*
 * Funci�n: bootstrapSD
 * ----------------------------
 *   Estima error est�ndar del est�distico de la desviaci�n est�ndar  muestral.
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)
 *			 B  -> Variable tipo entero con el n�mero de simulaci�n
 *
 *   Return: Lista con dos outputs.
 *			 1) Error est�ndar estimado del estad�stico 
 *			 1) Estad�sticos bootstrap generado por remuestreo bootstrap
 *
 *   Funci�n tipo List.
 */

// Rcpp wrapper for C++ function
// [[Rcpp::export]]
                        
 List bootstrapSD(NumericVector x1,  int B)
 { 
 	/*Variables */
	int n1 = 0;  int simulacion = 0; int i = 0; int j = 0; 
	double auxSuma = 0.0; double mediaBostrap = 0.0;
	double auxVar = 0.0; double varBostrap = 0.0; 
	double sdBostrap = 0.0;
    /*Tama�o de la muestra*/                     
	n1 =  x1.size();   
	/*Tama�o de la simulaci�*/ 
	simulacion = B; 
	/*Vector remuestreo*/ 
	NumericVector xx1(n1);
	/*Vecttor estad�sitcos bootstrap*/ 
	NumericVector estBoot(B);  
	
	time_t t;
	srand((unsigned)time(&t));
	/*Bootstrap*/ 
	for (i = 0; i < simulacion; i++){
		for(j=0;j< n1;j++){
			xx1[j] = x1[rand()%n1];
	} /*end for*/
 	
	estBoot[i] = sd(xx1);
	}/*end for*/
	
	/*Medias bootstrap*/ 
 	for (i = 0; i < simulacion; i++){
		auxSuma = auxSuma + estBoot[i];
	}/*end for*/
	
	mediaBostrap = auxSuma / simulacion;
	/*Suma de cuadrados bootstrap*/ 
	for (i = 0; i < simulacion; i++){
		auxVar = auxVar + pow((estBoot[i] - mediaBostrap), 2);
 	}/*end for*/
 	/*Varianza estimada por bootsrap*/
 	varBostrap = auxVar / (simulacion);
 	/*error est�ndar estimado por bootsrap*/
	sdBostrap = sqrt(varBostrap);
 	/*Regresa lista con error estandar del estad�stico y estad�sticos del remuestreo*/
	return Rcpp::List::create(Rcpp::Named("se") = sdBostrap,
                          Rcpp::Named("tboot") = estBoot);

 } /*end bootstrapSD*/
 
  /*
 * Funci�n: bootstrapMediana
 * ----------------------------
 *   Estima error est�ndar del est�distico de la mediana  muestral.
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)
 *			 B  -> Variable tipo entero con el n�mero de simulaci�n
 *
 *   Return: Lista con dos outputs.
 *			 1) Error est�ndar estimado del estad�stico 
 *			 1) Estad�sticos bootstrap generado por remuestreo bootstrap
 *
 *   Funci�n tipo List.
 */
 
 // Rcpp wrapper for C++ function
// [[Rcpp::export]]
                        
 List bootstrapMediana(NumericVector x1, int B)
 { 
	/*Variables*/
	int n1 = 0;  int simulacion = 0; int i = 0; int j = 0; 
	double auxSuma = 0.0; double mediaBostrap = 0.0;
	double auxVar = 0.0; double varBostrap = 0.0; 
	double sdBostrap = 0.0;
    /*Tama�o de Muestra*/                      
	n1 =  x1.size();
	   
	simulacion = B; 
	/*N�mero de simulaci�n*/  
	NumericVector xx1(n1);
	/*Vector guarda remuestreo*/
	NumericVector estBoot(B); 
	
	time_t t;
	srand((unsigned)time(&t));
	/*Re-muestreo boostrapt tama�o n1, B veces*/
	for (i = 0; i < simulacion; i++){
		for(j=0;j< n1;j++){
		xx1[j] = x1[rand()%n1];
	} /*end for*/

 	estBoot[i] = mediana(xx1); /*ingresa una media por cada simulaci�n*/
	} /*end for*/
	
 	/*Media de los B estad�sticos*/
 	for (i = 0; i < simulacion; i++){	
		auxSuma = auxSuma + estBoot[i];
 	} /*end for*/
 	
	mediaBostrap = auxSuma / simulacion;
 	/*Suma de cuadrados de los B estad�sticos*/
	for (i = 0; i < simulacion; i++){
		auxVar = auxVar + pow((estBoot[i] - mediaBostrap), 2);
 	}
 	/*Varianza estimada por bootsrap*/
 	varBostrap = auxVar / (simulacion);
 	/*error est�ndar estimado por bootsrap*/
 	sdBostrap = sqrt(varBostrap);
 	
	/*Regresa lista con error estandar del estad�stico y estad�sticos del remuestreo*/
 	return Rcpp::List::create(Rcpp::Named("se") = sdBostrap,
                          Rcpp::Named("tboot") = estBoot);
 } /*end bootstrapMediana*/
 
   /*
 * Funci�n: bootstrapMedia
 * ----------------------------
 *   Estima error est�ndar del est�distico de la media  muestral.
 *
 *	 Input: xx1 -> Vector N�merico Double (Datos)
 *			 B  -> Variable tipo entero con el n�mero de simulaci�n
 *
 *   Return: Lista con dos outputs.
 *			 1) Error est�ndar estimado del estad�stico 
 *			 1) Estad�sticos bootstrap generado por remuestreo bootstrap
 *
 *   Funci�n tipo List.
 */
 
 
 // Rcpp wrapper for C++ function
// [[Rcpp::export]]
                        
 List bootstrapMedia(NumericVector x1, int B)
 { 
	/*Variables*/
	int n1 = 0;  int simulacion = 0; int i = 0; int j = 0; /*Variables de apoyo*/
	double auxSuma = 0.0; double mediaBostrap = 0.0;
	double auxVar = 0.0; double varBostrap = 0.0; 
	double sdBostrap = 0.0;
    /*Tama�o de Muestra*/                 
	n1 =  x1.size();   
	/*N�mero de simulaci�n*/
	simulacion = B; 
	/*Vector guarda remuestreo*/
	NumericVector xx1(n1);
	/*vector guarda las B estimaciones del estad�stico*/
	NumericVector estBoot(B);
	
	time_t t;
	srand((unsigned)time(&t));
	/*Re-muestreo boostrapt tama�o n1, B veces*/
	for (i = 0; i < simulacion; i++){
		for(j=0;j< n1;j++){
			xx1[j] = x1[rand()%n1];
 	} /*end for*/

 	estBoot[i] = media(xx1);
	}/*end for*/
 	/*Media de los B estad�sticos*/ 
 	for (i = 0; i < simulacion; i++){
	auxSuma = auxSuma + estBoot[i];
 	}/*end for*/

	mediaBostrap = auxSuma / simulacion;
 	/*Suma de cuadrados de los B estad�sticos*/
	for (i = 0; i < simulacion; i++){
		auxVar = auxVar + pow((estBoot[i] - mediaBostrap), 2);
 	}/*end for*/
 	
 	/*Varianza estimada por bootsrap*/
	varBostrap = auxVar / (simulacion);
 	/*error est�ndar estimado por bootsrap*/
 	
	sdBostrap = sqrt(varBostrap);
 	/*Regresa lista con error estandar del estad�stico y estad�sticos del remuestreo*/
	return Rcpp::List::create(Rcpp::Named("se") = sdBostrap,
                          Rcpp::Named("tboot") = estBoot);

 }/*end bootstrapMedia*/
