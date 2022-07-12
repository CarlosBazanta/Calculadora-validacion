#include <stdio.h> 
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h> //librerias
#include <ctype.h>
#define max 100

void clearBuf(void);
int validFormat(const char*, void*);
int validar=1;  //funciones 
char nom[max][20];
int text(char texto[]);

float suma (float *a, float *b);
float resta (float *a, float *b);
float multiplicacion (float *a, float *b);


int main(){
	
	char validNombre[max];
	int op,i,j,opc; //se de claran las variables
	float a=0,b=0,mat[1][3];
	 
		 op=1;//inicia el bucle
	 
	while(op==1){//bucle que repite el progrma
		
		//se le pide al usuario que ingrese los datos
	 
		verificacion3: //marca un punto en el programa para poder retornar a el
				
			do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
			
				printf("\n\tIngrese la opcion que desee realizar\n\n1.Suma\t\t2.Resta\t\t3.Multiplicacion\n");
				printf("\nSu opcion es = "); //se imprime en pantalla las opciones a ingresar
					
				if(validFormat("%i",&opc)) continue; //validformat nos sirve para ingresar los datos y validarlos
			
				validar=opc<=0;//valida la opcion y si es menor saltara un error
			
				if(validar){//if que sirve para imprimir en pantalla el error
				
					printf("\n\nIngreso un numero invalido\n");
					printf("No se aceptan valores tan bajos\n\n"); //imprime en pantalla el error
			
				}
			}while(validar); //que retorna despues de mostrar el error
			
			if(opc>=4 or opc>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
				printf("\n\nIngreso un numero demasiado alto o invalido\n");
				printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
				goto verificacion3; //da la orden para que el programa vaya a un punto de este
				
			}
	 
		//se le pide al usuario que ingrese los datos
	 
		verificacion1: //marca un punto en el programa para poder retornar a el
				
			do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
			
				printf("\nIngrese el primer valor que desee calcular\n");
				printf("\nSu valor es de = "); //se imprime en pantalla las opciones a ingresar
					
				if(validFormat("%f",&a)) continue; //validformat nos sirve para ingresar los datos y validarlos
			
				validar=a<=0;//valida la opcion y si es menor saltara un error
			
				if(validar){//if que sirve para imprimir en pantalla el error
				
					printf("\n\nIngreso un numero invalido\n");
					printf("No se aceptan valores tan bajos\n\n"); //imprime en pantalla el error
			
				}
			}while(validar); //que retorna despues de mostrar el error
			
			if(a>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
				printf("\n\nIngreso un numero demasiado alto o invalido\n");
				printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
				goto verificacion1; //da la orden para que el programa vaya a un punto de este
				
			}
			
		//se le pide al usuario que ingrese los datos
	 
		verificacion2: //marca un punto en el programa para poder retornar a el
				
			do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
			
				printf("\nIngrese el primer valor que desee calcular\n");
				printf("\nSu valor es de = "); //se imprime en pantalla las opciones a ingresar
					
				if(validFormat("%f",&b)) continue; //validformat nos sirve para ingresar los datos y validarlos
			
				validar=b<=0;//valida la opcion y si es menor saltara un error
			
				if(validar){//if que sirve para imprimir en pantalla el error
				
					printf("\n\nIngreso un numero invalido\n");
					printf("No se aceptan valores tan bajos\n\n"); //imprime en pantalla el error
			
				}
			}while(validar); //que retorna despues de mostrar el error
			
			if(b>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
				printf("\n\nIngreso un numero demasiado alto o invalido\n");
				printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
				goto verificacion2; //da la orden para que el programa vaya a un punto de este
				
			}
			
		switch(opc){//inicio de el switch case
			
			case 1://caso 1
			
				mat[0][0]=suma(&a, &b); //se realizara una suma
				
			break;//descanso
			
			case 2://caso 2
				
				mat[0][1]=resta(&a, &b);//se realizara una resta
				
			break;
			
			case 3://caso 3
				
				mat[0][2]=multiplicacion(&a, &b);//se realizara una multiplicacion
				
			break;
			
		}	
			
	
		//se le pide al usuario que ingrese los datos
	 
		verificacion: //marca un punto en el programa para poder retornar a el
				
			do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
			
				printf("\nDesea repetir el programa\n\t1.Si o 2.No\n");
				printf("\nSu opcion es = "); //se imprime en pantalla las opciones a ingresar
					
				if(validFormat("%i",&op)) continue; //validformat nos sirve para ingresar los datos y validarlos
			
				validar=op<=0;//valida la opcion y si es menor saltara un error
			
				if(validar){//if que sirve para imprimir en pantalla el error
				
					printf("\n\nIngreso un numero invalido\n");
					printf("No se aceptan valores tan bajos\n\n"); //imprime en pantalla el error
			
				}
			}while(validar); //que retorna despues de mostrar el error
			
			if(op>=3 or op>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
				printf("\n\nIngreso un numero demasiado alto o invalido\n");
				printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
				goto verificacion; //da la orden para que el programa vaya a un punto de este
				
			}
		
			system("cls");//limpia la pantalla
		
	}

	printf("\n\n\t\4Hasta la proxima\4\n");//mensaje de despedida


	getch();
	
}






int validFormat(const char* formato, void* variable){ /* Esto es para verificar variables */
	
	validar=1;//reseteamos la comprobacion de la opcion
    /* si se retorna 0 fue porque ocurrio un error*/
    
    if(!scanf(formato, variable) || (getchar() != '\n'))
    {
        
        clearBuf();/* Se utiliza para limpiar el buffer */
        
        printf("\n\n\tError\n\n");
        printf("\n\tUsted Ingreso una opcion no valida\n"); /* Se imprime en pantalla el error */
        printf("\n\tPor favor ingrese una opcion valida\n");
        system("pause");
		
        return 1;
    }
    
    return 0;
}

void clearBuf()
{
    int ch;
    /* Se utiliza para limpiar el buffer */
    while((ch = getchar()) != '\n' && ch != EOF);
}

int text(char texto[]){

	int y;//Para recorrer toda la cadena en busca de un numero
	
	for(y=0; y<strlen(texto); y++){//Para que solo acepte letras Aa-Zz
		
		if(!isalpha(texto[y]) && (texto[y]!=32)){
			
			clearBuf();

        	printf("Error: No puede ingresar numeros.\n\n");
        	system("pause");//imprime los errores en pantalla
			system("cls");
			
			return 1;
		}
	}
	
	clearBuf(); //Limpiamos el buffer 
	
	return 0;
	}
	
float suma (float *a, float *b){//funciones para realizar operaciones de suma
	
	float  suma;//se declara suma
	
	suma=*a + *b;//realiza la operacion
	
	printf("\n\n\t\4El valor de la suma es = %.2f\4\n", suma);//imprime el resultado
}

float resta (float *a, float *b){//funciones para realizar operaciones de resta
	
	float  resta;//se declara resta
	
	resta=*a - *b;//se realiza la resta
	
	printf("\n\t\4El valor de la resta es = %.2f\4\n", resta);//imprime el resultado
}

float multiplicacion (float *a, float *b){//funciones para realizar operaciones de multiplicacion
	
	float  multi;//se declara multiplicacion
	
	multi=*a * *b;//se realiza la operacion
	
	printf("\n\t\4El valor de la multiplicacion es = %.2f\4\n", multi);//imprime el resultado
}

