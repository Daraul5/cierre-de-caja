#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define TAM 100

void turno1();

void llenarturno1();
void mostrar1();
void totales1();
void mostrarcli1();
void buscar1();
void ordenar1();
void ascendente1();
void descendente1();
void modificar1();

void turno2();

void llenarturno2();
void mostrarcli2();
void buscar2();
void ordenar2();
void ascendente2();
void descendente2();
void modificar2();

void men();

void menu1();
void menu1_1();
void menu1_2();
void menu1_3();
void menu1_4();

void menu2();

void menu3();
void menu3_1();
void menu3_2();

typedef struct
{
	char nombre[100];
	float precio;
	int cantidad;
} producto;

typedef struct
{
	char nombretipo[100];
	producto productos[TAM];
	int numproductos;

} tipoproducto;

typedef struct
{
	tipoproducto tipos[TAM];
	int numtipos;
	float suma;
	float sumapr;
	float sumase;
	float sumaci;
} clente;
typedef struct
{
	clente clientes[TAM];
	int numcli, estc;
	float tpr, ts, tci, sumt;
	char encargado[50];
} trn;
clente aux;
trn turnos[2];

int tp, cc, i, j, type, typen, h, k, sel;
int tur, n, ca, conti, cli;

int main()
{

	// INICIO CON UN MENSAJE DIRECTO DEL PROGRAMA}
	time_t k = time(NULL);
	struct tm tm = *localtime(&k);
	printf("Fecha del turno: %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("Ingrese el turno (1: matutino, 2: vespertino):\n");
	do
	{
		scanf("%i", &tur);
	} while (tur != 1 && tur != 2);

	switch (tur)
	{
	case 1:
		turno1();
		break;
	case 2:
		turno2();
		break;
	default:
		break;
	}
	return 0;
}
void turno1()
{
	system("cls");
	int op;
	do
	{
		printf("que desea hacer en el turno?\n");
		printf("1) llenar el turno\n2) mostrar los datos\n3) buscar los datos\n4) ordenar\n5) modificar\n6) salir\n");
		scanf(" %i", &op);
		switch (op)
		{
		case 1:
			llenarturno1();
			break;
		case 2:
			mostrar1();
			break;
		case 3:
			buscar1();
			break;
		case 4:
			ordenar1();
			break;
		case 5:
			modificar1();
			break;
		case 6:
			break;
		}
	} while (op != 6);
}
void llenarturno1()
{
	system("cls");
	time_t k = time(NULL);
	struct tm tm = *localtime(&k);
	system("cls");
	Sleep(1000);
	printf("Inicio el turno matutino de 7:30 am a 3:30 pm \n");
	printf("Hora del dia: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("Ingrese el nombre del encargado del dia y turno:\n");
	getchar();
	fgets(turnos[0].encargado, sizeof(turnos[0].encargado), stdin);
	turnos[0].encargado[strcspn(turnos[0].encargado, "\n")] = 0;
	system("cls");
	conti = 1;
	printf("Ingrese la estimacion de clientes del dia: \n");
	scanf(" %i", &turnos[0].estc);
	turnos[0].numcli = 0;
	turnos[0].tpr = 0;
	turnos[0].ts = 0;
	turnos[0].tci = 0;
	turnos[0].sumt = 0;
	for (i = 0; i < turnos[0].estc; i++)
	{
		turnos[0].clientes[turnos[0].numcli].suma = 0;
		turnos[0].clientes[turnos[0].numcli].sumapr = 0;
		turnos[0].clientes[turnos[0].numcli].sumaci = 0;
		turnos[0].clientes[turnos[0].numcli].sumase = 0;
		if (conti == 0)
		{
			break;
		}

		men();
		//SE PONE LA VARIABLE CC PARA INICIAR EL CICLO WHILE
		cc = 1;
		// SE INICIA EL CICLO WHILE PARA COMENZAR LA COMPRA DE LOS PRODUCTOS
		while (cc == 1)
		{
			printf("Seleccione el tipo de producto (1: Productos y Recargas, 2: Servicios, 3: Cibercafe):\n");
			do
			{
				scanf("%i", &tp);
			} while (tp < 1 || tp > 3);

			switch (tp)
			{
			case 1:
				strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].nombretipo, "productos y recargas");

				menu1();
				do
				{
					scanf("%i", &type);
				} while (type < 1 || type > 4);
				switch (type)
				{
				case 1:
					printf("ingrese que tipo de producto va a comprar\n");
					menu1_1();
					do
					{
						scanf("%i", &typen);
					} while (typen < 1 || typen > 3);

					switch (typen)
					{
					case 1:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "sabritas de $15.00");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 15.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 2:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "sabritas de $17.00");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 17.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 3:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "sabritas de $20.00");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 20.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					}
					turnos[0].clientes[turnos[0].numcli].numtipos++;
					break;
				case 2:
					printf("ingrese que tipo de producto va a comprar\n");
					menu1_2();
					do
					{
						scanf("%i", &typen);
					} while (typen < 1 || typen > 3);
					switch (typen)
					{
					case 1:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "gamesa de $12.00");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 12.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 2:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "gamesa de $18.00");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 18.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						break;
					case 3:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "gamesa de $20.00");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 20.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					}
					turnos[0].clientes[turnos[0].numcli].numtipos++;
					break;
				case 3:
					printf("ingrese que tipo de producto va a comprar\n");
					menu1_3();
					do
					{
						scanf("%i", &typen);
					} while (typen < 1 || typen > 6);
					switch (typen)
					{
					case 1:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "lapicero de $8.0");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 8.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 2:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "folders");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 4.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 3:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "curp");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 20.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 4:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "opalina delgada");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 2.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 5:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "opalina gruesa");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 3.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 6:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "papel fotografico");
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 15.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					default:
						break;
					}
					turnos[0].clientes[turnos[0].numcli].numtipos++;
					break;
				case 4:
					printf("ingrese que tipo de producto va a comprar\n");
					menu1_4();
					do
					{
						scanf("%i", &typen);
					} while (typen < 1 || typen > 4);
					switch (typen)
					{
					case 1:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "recarga telcel");
						printf("ingrese el monto de la recarga:\n");
						scanf(" %f", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio);
						printf("ingrese la cantidad de recargas puestas:\n");
						scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 2:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "recarga at&t");
						printf("ingrese el monto de la recarga:\n");
						scanf(" %f", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio);
						printf("ingrese la cantidad de recargas puestas:\n");
						scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 3:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "recarga movistar");
						printf("ingrese el monto de la recarga:\n");
						scanf(" %f", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio);
						printf("ingrese la cantidad de recargas puestas:\n");
						scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					case 4:
						strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "recarga bait");
						printf("ingrese el monto de la recarga:\n");
						scanf(" %f", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio);
						printf("ingrese la cantidad de recargas puestas:\n");
						scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
						turnos[0].clientes[turnos[0].numcli].sumapr += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
						turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
						break;
					default:
						break;
					}
					turnos[0].clientes[turnos[0].numcli].numtipos++;
					break;
				default:
					break;
				}

				break;
			case 2:
				strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].nombretipo, "servicios");

				menu2();
				printf("ingrese el servicio que va a necesitar:\n");
				do
				{
					scanf(" %i", &type);
				} while (type < 1 || type > 4);
				switch (type)
				{
				case 1:
					strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "actas");
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 170.0;
					printf("ingrese la cantidad que se compro:\n");
					scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
					turnos[0].clientes[turnos[0].numcli].sumase += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
					break;
				case 2:
					strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "rfc");
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 130.0;
					printf("ingrese la cantidad que se compro:\n");
					scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
					turnos[0].clientes[turnos[0].numcli].sumase += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
					break;
				case 3:
					strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "constancia de no inhabilitacion");
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 180.0;
					printf("ingrese la cantidad que se compro:\n");
					scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
					turnos[0].clientes[turnos[0].numcli].sumase += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
					break;
				case 4:
					strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "antecedentes no penales");
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 450.0;
					printf("ingrese la cantidad que se compro:\n");
					scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
					turnos[0].clientes[turnos[0].numcli].sumase += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
					break;
				default:
					break;
				}
				turnos[0].clientes[turnos[0].numcli].numtipos++;
				break;
			case 3:
				strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].nombretipo, "cibercafe");

				menu3();
				printf("ingrese el servicio que va a necesitar:\n");
				do
				{
					scanf(" %i", &type);
				} while (type < 1 || type > 4);
				switch (type)
				{
				case 1:
					strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "fotocopiado");
					printf("ingrese de cuanto fue la compra:\n");
					scanf(" %f", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio);
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad = 1;
					turnos[0].clientes[turnos[0].numcli].sumaci += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
					break;
				case 2:
					strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "impresion de documentos");
					printf("ingrese de cuanto fue la compra:\n");
					scanf(" %f", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio);
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad = 1;
					turnos[0].clientes[turnos[0].numcli].sumaci += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
					break;
				case 3:
					menu3_1();
					strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "renta de equipo de computo");
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 10.0;
					printf("ingrese la cantidad de horas usadas:\n");
					scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
					turnos[0].clientes[turnos[0].numcli].sumaci += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
					break;
				case 4:
					menu3_2();
					strcpy(turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "renta de consolas");
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio = 12.0;
					printf("ingrese la cantidad de horas usadas:\n");
					scanf(" %i", &turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad);
					turnos[0].clientes[turnos[0].numcli].sumaci += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].suma += turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].precio * turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].productos[turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].cantidad;
					turnos[0].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos++;
					break;
				default:
					break;
				}
				turnos[0].clientes[turnos[0].numcli].numtipos++;
				break;
			default:
				break;
			}

			printf("Desea agregar otro producto? (1: Si, 0: No):\n");
			do
			{
				scanf("%i", &cc);
				// SE USA LA FUNCION Y PARA DELIMITAR EL RANGO DE VALORES A SOLO DOS 1 Y 0 DONDE 0 ROMPE EL CICLO Y AVANZA Y 1 REINICIA EL SWITCH DE COMPRA
			} while (cc != 1 && cc != 0);
			if (cc == 0)
			{
				system("cls");
			}
		}

		printf("Desea continuar atendiendo clientes? (1: Si, 0: No):\n");
		do
		{
			scanf("%i", &conti);
			if (conti == 0)
			{
				turnos[0].estc = i + 1;
			}
			else
			{
				turnos[0].estc += 1;
			}

		} while (conti != 1 && conti != 0);
		// SE RECICLA EL VALOR DE LA VARIABLE CC PARA ASI LIMPIAR LA PANTALLA E IMPRIMIR EL CIERRE DE CAJA
		if (cc == 0)
		{
			system("cls");
		}

		turnos[0].tpr += turnos[0].clientes[turnos[0].numcli].sumapr;
		turnos[0].ts += turnos[0].clientes[turnos[0].numcli].sumase;
		turnos[0].tci += turnos[0].clientes[turnos[0].numcli].sumaci;
		turnos[0].sumt += turnos[0].clientes[turnos[0].numcli].suma;
		turnos[0].numcli++;
	}
}
void mostrar1()
{
	system("cls");
	int ti, o;
	ti = 0;
	if (ti == 0)
	{
		do
		{
			printf("que desea mostrar?\n");
			printf("1) totales del dia\n2) clientes del dia\n3)salir\n");
			scanf(" %i", &o);
			switch (o)
			{
			case 1:
				totales1();
				break;
			case 2:
				mostrarcli1();
				break;
			case 3:
				break;
			}
		} while (o != 3);
	}
}
void totales1()
{
	system("cls");
	time_t k = time(NULL);
	struct tm tm = *localtime(&k);
	printf("Que desea mostrar?\n");
	printf("1) Totales del día\n2) Clientes individuales\n");
	printf("Día: %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("Encargado: %s\n", turnos[0].encargado);
	printf("Total productos y recargas: %.2f\n", turnos[0].tpr);
	printf("Total servicios: %.2f\n", turnos[0].ts);
	printf("Total cibercafé: %.2f\n", turnos[0].tci);
	printf("Suma total: %.2f\n", turnos[0].sumt);
	printf("Ganancia del día: %.2f\n", turnos[0].tci);
}

void mostrarcli1()
{
	system("cls");
	int ci, ti;
	ti = 0;
	printf("Datos de los clientes en el turno %i:\n", ti + 1);
	for (ci = 0; ci < turnos[ti].numcli; ci++)
	{
		printf("Cliente %i:\n", ci + 1);
		for (j = 0; j < turnos[ti].clientes[ci].numtipos; j++)
		{
			printf(" Tipo: %s\n", turnos[ti].clientes[ci].tipos[j].nombretipo);
			for (k = 0; k < turnos[ti].clientes[ci].tipos[j].numproductos; k++)
			{
				printf("  Producto: %s, Precio: %.2f, Cantidad: %d\n",
					   turnos[ti].clientes[ci].tipos[j].productos[k].nombre,
					   turnos[ti].clientes[ci].tipos[j].productos[k].precio,
					   turnos[ti].clientes[ci].tipos[j].productos[k].cantidad);
			}
		}
		printf("Suma total del cliente: %.2f\n", turnos[ti].clientes[ci].suma);
		printf("____________________\n");
		Sleep(3);
	}
}
void buscar1()
{
	int clin, bus;
	bus = 0;
	printf("¿Que numero de cliente quiere buscar?\n");
	scanf("%i", &clin);

	for (i = 0; i < turnos[0].estc; i++)
	{
		if (i + 1 == clin)
		{
			printf("El cliente buscado se encontró en la posicion %i\n", i + 1);
			bus = 1;
			printf("Datos del cliente %i:\n", clin);
			for ( j = 0; j < turnos[0].clientes[i].numtipos; j++)
			{
				printf(" Tipo: %s\n", turnos[0].clientes[i].tipos[j].nombretipo);
				for (k = 0; k < turnos[0].clientes[i].tipos[j].numproductos; k++)
				{
					printf("  Producto: %s, Precio: %.2f, Cantidad: %d\n",
						   turnos[0].clientes[i].tipos[j].productos[k].nombre,
						   turnos[0].clientes[i].tipos[j].productos[k].precio,
						   turnos[0].clientes[i].tipos[j].productos[k].cantidad);
				}
			}
		}
	}
	if (!bus)
	{
		printf("Cliente no encontrado.\n");
	}
}
void ordenar1()
{
	int ption;
	printf("de que manera quiere ordenar los totales de los clientes?\n1) ascendente\n2) descendente\n");
	scanf(" %i", &ption);
	switch (ption)
	{
	case 1:
		ascendente1();
		break;
	case 2:
		descendente1();
		break;
	default:
		break;
	}
}
void ascendente1()
{

	for (i = 0; i < turnos[0].estc - 1; i++)
	{
		for (j = 0; j < turnos[0].estc - i - 1; j++)
		{
			if (turnos[0].clientes[j].suma > turnos[0].clientes[j + 1].suma)
			{
				aux = turnos[0].clientes[j];
				turnos[0].clientes[j] = turnos[0].clientes[j + 1];
				turnos[0].clientes[j + 1] = aux;
			}
		}
	}
}

void descendente1()
{
	for (i = 0; i < turnos[0].estc - 1; i++)
	{
		for (j = 0; j < turnos[0].estc - i - 1; j++)
		{
			if (turnos[0].clientes[j].suma < turnos[0].clientes[j + 1].suma)
			{
				aux = turnos[0].clientes[j];
				turnos[0].clientes[j] = turnos[0].clientes[j + 1];
				turnos[0].clientes[j + 1] = aux;
			}
		}
	}
}
void modificar1()
{
	int clim, bus = 0, ot, otion, oc;

	printf("Que cliente desea modificar?\n");
	scanf("%i", &clim);

	for (int i = 0; i < turnos[0].estc; i++)
	{
		if (i + 1 == clim)
		{
			printf("El cliente buscado se encontro en la posicion %i\n", i + 1);
			bus = 1;

			printf("Datos actuales del cliente %i:\n", clim);
			for (int j = 0; j < turnos[0].clientes[i].numtipos; j++)
			{
				printf(" Tipo: %s\n", turnos[0].clientes[i].tipos[j].nombretipo);
				for (int k = 0; k < turnos[0].clientes[i].tipos[j].numproductos; k++)
				{
					printf("  Producto: %s, Precio: %.2f, Cantidad: %d\n",
						   turnos[0].clientes[i].tipos[j].productos[k].nombre,
						   turnos[0].clientes[i].tipos[j].productos[k].precio,
						   turnos[0].clientes[i].tipos[j].productos[k].cantidad);
					printf("%f\n", turnos[0].tpr);
					printf("%f\n", turnos[0].ts);
					printf("%f\n", turnos[0].tci);
					Sleep(500);
				}
			}

			for (int j = 0; j < turnos[0].clientes[i].numtipos; j++)
			{
				for (int k = 0; k < turnos[0].clientes[i].tipos[j].numproductos; k++)
				{
					if (strcmp(turnos[0].clientes[i].tipos[j].nombretipo, "productos y recargas") == 0)
					{
						turnos[0].tpr -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
						turnos[0].sumt -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
						turnos[0].clientes[i].sumapr -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
					}
					if (strcmp(turnos[0].clientes[i].tipos[j].nombretipo, "servicios") == 0)
					{
						turnos[0].ts -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
						turnos[0].sumt -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
						turnos[0].clientes[i].sumase -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
					}
					if (strcmp(turnos[0].clientes[i].tipos[j].nombretipo, "cibercafe") == 0)
					{
						turnos[0].tci -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
						turnos[0].sumt -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
						turnos[0].clientes[i].sumaci -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
					}
				}
			}

			turnos[0].clientes[i].suma = 0;
			for (int j = 0; j < turnos[0].clientes[i].numtipos; j++)
			{
				for (int k = 0; k < turnos[0].clientes[i].tipos[j].numproductos; k++)
				{
					turnos[0].clientes[i].tipos[j].productos[k].precio = 0;
					turnos[0].clientes[i].tipos[j].productos[k].cantidad = 0;
				}
			}
			printf("Ingrese los nuevos datos para el cliente %i:\n", clim);

			for (int j = 0; j < turnos[0].clientes[i].numtipos; j++)
			{

				printf(" tipo actual: %s\n", turnos[0].clientes[i].tipos[j].nombretipo);
				men();
				printf("ingrese el nuevo tipo de producto (o el mismo):\n");
				scanf(" %i", &ot);
				switch (ot)
				{
				case 1:
					strcpy(turnos[0].clientes[i].tipos[j].nombretipo, "productos y recargas");
					break;
				case 2:
					strcpy(turnos[0].clientes[i].tipos[j].nombretipo, "servicios");
					break;
				case 3:
					strcpy(turnos[0].clientes[i].tipos[j].nombretipo, "cibercafe");
					break;
				}
				for (int k = 0; k < turnos[0].clientes[i].tipos[j].numproductos; k++)
				{
					turnos[0].clientes[i].suma = 0;
					turnos[0].clientes[i].sumapr = 0;
					turnos[0].clientes[i].sumase = 0;
					turnos[0].clientes[i].sumaci = 0;
					printf(" producto actual: %s\n", turnos[0].clientes[i].tipos[j].productos[k].nombre);
					printf("ingrese el nuevo nombre del producto (o el mismo):\n");
					if (strcmp(turnos[0].clientes[i].tipos[j].nombretipo, "productos y recargas") == 0)
					{

						menu1();
						scanf(" %i", &otion);
						switch (otion)
						{
						case 1:
							menu1_1();
							scanf(" %i", &oc);
							switch (oc)
							{
							case 1:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "sabritas de $15.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 15.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 2:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "sabritas de $17.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 17.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 3:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "sabritas de $20.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 20.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							default:
								break;
							}
							break;
						case 2:
							menu1_2();
							scanf(" %i", &oc);
							switch (oc)
							{
							case 1:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "gamesa de $12.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 12.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 2:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "gamesa de $18.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 18.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 3:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "gamesa de $20.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 20.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							default:
								break;
							}
							break;
						case 3:
							menu1_3();
							scanf(" %i", &oc);
							switch (oc)
							{
							case 1:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "lapicero de $8.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 8.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 2:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "folders de $4.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 4.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 3:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "curp de $20.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 20.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 4:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "opalina delgada de $2.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 2.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 5:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "opalina gruesa de $3.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 3.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 6:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "papel fotografico de $15.0");
								turnos[0].clientes[i].tipos[j].productos[k].precio = 15.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							default:
								break;
							}
							break;
						case 4:
							menu1_4();
							scanf(" %i", &oc);
							switch (oc)
							{
							case 1:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "recarga telcel");
								printf("ingrese el precio de la recarga\n");
								scanf(" %f", &turnos[0].clientes[i].tipos[j].productos[k].precio);
								printf("ingrese la nueva cantidad de recargas:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 2:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "recarga at&t");
								printf("ingrese el precio de la recarga\n");
								scanf(" %f", &turnos[0].clientes[i].tipos[j].productos[k].precio);
								printf("ingrese la nueva cantidad de recargas:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 3:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "recarga movistar");
								printf("ingrese el precio de la recarga\n");
								scanf(" %f", &turnos[0].clientes[i].tipos[j].productos[k].precio);
								printf("ingrese la nueva cantidad de recargas:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 4:
								strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "recarga bait");
								printf("ingrese el precio de la recarga\n");
								scanf(" %f", &turnos[0].clientes[i].tipos[j].productos[k].precio);
								printf("ingrese la nueva cantidad de recargas:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[0].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
								break;
							default:
								break;
							}
							break;
						default:
							break;
						}
					}
					if (strcmp(turnos[0].clientes[i].tipos[j].nombretipo, "servicios") == 0)
					{
						menu2();
						scanf(" %i", &otion);
						switch (otion)
						{
						case 1:
							strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "actas");
							turnos[0].clientes[i].tipos[j].productos[k].precio = 170.0;
							printf("ingrese la nueva cantidad del producto:\n");
							scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
							turnos[0].clientes[i].sumase += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 2:
							strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "rfc");
							turnos[0].clientes[i].tipos[j].productos[k].precio = 130.0;
							printf("ingrese la nueva cantidad del producto:\n");
							scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
							turnos[0].clientes[i].sumase += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 3:
							strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "constancia de no inhabilitacion");
							turnos[0].clientes[i].tipos[j].productos[k].precio = 180.0;
							printf("ingrese la nueva cantidad del producto:\n");
							scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
							turnos[0].clientes[i].sumase += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 4:
							strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "antecedentes no penales");
							turnos[0].clientes[i].tipos[j].productos[k].precio = 450.0;
							printf("ingrese la nueva cantidad del producto:\n");
							scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
							turnos[0].clientes[i].sumase += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							break;
						default:
							break;
						}
					}
					if (strcmp(turnos[0].clientes[i].tipos[j].nombretipo, "cibercafe") == 0)
					{
						menu3();
						scanf(" %i", &otion);
						switch (otion)
						{
						case 1:
							strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "fotocopiado");
							printf("ingrese la cantidad de la compra\n");
							scanf(" %f", &turnos[0].clientes[i].tipos[j].productos[k].precio);
							turnos[0].clientes[i].tipos[j].productos[k].cantidad = 1;
							turnos[0].clientes[i].sumaci += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 2:
							strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "impresion de documentos");
							printf("ingrese la cantidad de la compra\n");
							scanf(" %f", &turnos[0].clientes[i].tipos[j].productos[k].precio);
							turnos[0].clientes[i].tipos[j].productos[k].cantidad = 1;
							turnos[0].clientes[i].sumaci += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 3:
							menu3_1();
							strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "renta de equipo de computo");
							turnos[0].clientes[i].tipos[j].productos[k].precio = 10.0;
							printf("ingrese la cantidad de horas usadas:\n");
							scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
							turnos[0].clientes[i].sumaci += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 4:
							menu3_2();
							strcpy(turnos[0].clientes[i].tipos[j].productos[k].nombre, "renta de videoconsolas");
							turnos[0].clientes[i].tipos[j].productos[k].precio = 12.0;
							printf("ingrese la cantidad de horas usadas:\n");
							scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
							turnos[0].clientes[i].sumaci += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							turnos[0].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
							break;
						default:
							break;
						}
					}
					turnos[0].tpr += turnos[0].clientes[i].sumapr;
					turnos[0].ts += turnos[0].clientes[i].sumase;
					turnos[0].tci += turnos[0].clientes[i].sumaci;
					turnos[0].sumt += turnos[0].clientes[i].suma;
				}
			}
			printf("los datos del cliente %i han sido actualizados.\n", clim);
			break;
		}
	}

	if (!bus)
	{
		printf("cliente no encontrado\n");
	}
}

void turno2()
{
	system("cls");
	int op;
	do
	{
		printf("que desea hacer en el turno?\n");
		printf("1) llenar el turno\n2) mostrar los datos\n3) buscar los datos\n4) ordenar\n5) modificar\n6) salir\n");
		scanf(" %i", &op);
		switch (op)
		{
		case 1:
			llenarturno1();
			break;
		case 2:
			mostrar1();
			break;
		case 3:
			buscar1();
			break;
		case 4:
			ordenar1();
			break;
		case 5:
			modificar1();
			break;
		case 6:
			break;
		}
	} while (op != 6);
}

void llenarturno2()
{
	system("cls");
	time_t k = time(NULL);
	struct tm tm = *localtime(&k);
	system("cls");
	Sleep(1000);
	printf("Inicio el turno vespertino de 3:00 pm a 10:30 pm \n");
	printf("Hora del dia: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("Ingrese el nombre del encargado del dia y turno:\n");
	getchar();
	fgets(turnos[1].encargado, sizeof(turnos[1].encargado), stdin);
	turnos[1].encargado[strcspn(turnos[1].encargado, "\n")] = 0;
	system("cls");
	conti = 1;
	printf("Ingrese la estimacion de clientes del dia: \n");
	scanf(" %i", &turnos[1].estc);
	turnos[1].numcli = 0;
	turnos[1].tpr = 0;
	turnos[1].ts = 0;
	turnos[1].tci = 0;
	turnos[1].sumt = 0;
	for (i = 0; i < turnos[1].estc; i++)
	{
		turnos[1].clientes[turnos[1].numcli].suma = 0;
		turnos[1].clientes[turnos[1].numcli].sumapr = 0;
		turnos[1].clientes[turnos[1].numcli].sumaci = 0;
		turnos[1].clientes[turnos[1].numcli].sumase = 0;
		if (conti == 0)
		{
			break;
		}

		men();
		cc = 1;
		// SE INICIA EL CICLO WHILE PARA COMENZAR LA COMPRA DE LOS PRODUCTOS
		while (cc == 1)
		{
			printf("Seleccione el tipo de producto (1: Productos y Recargas, 2: Servicios, 3: Cibercafe):\n");
			do
			{
				scanf("%i", &tp);
			} while (tp < 1 || tp > 3);

			switch (tp)
			{
			case 1:
				strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].nombretipo, "productos y recargas");

				menu1();
				do
				{
					scanf("%i", &type);
				} while (type < 1 || type > 4);
				switch (type)
				{
				case 1:
					printf("ingrese que tipo de producto va a comprar\n");
					menu1_1();
					do
					{
						scanf("%i", &typen);
					} while (typen < 1 || typen > 3);

					switch (typen)
					{
					case 1:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "sabritas de $15.00");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 15.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 2:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "sabritas de $17.00");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 17.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 3:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "sabritas de $20.00");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 20.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					}
					turnos[1].clientes[turnos[1].numcli].numtipos++;
					break;
				case 2:
					printf("ingrese que tipo de producto va a comprar\n");
					menu1_2();
					do
					{
						scanf("%i", &typen);
					} while (typen < 1 || typen > 3);
					switch (typen)
					{
					case 1:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "gamesa de $12.00");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 12.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 2:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "gamesa de $18.00");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 18.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						break;
					case 3:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "gamesa de $20.00");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 20.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					}
					turnos[1].clientes[turnos[1].numcli].numtipos++;
					break;
				case 3:
					printf("ingrese que tipo de producto va a comprar\n");
					menu1_3();
					do
					{
						scanf("%i", &typen);
					} while (typen < 1 || typen > 6);
					switch (typen)
					{
					case 1:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "lapicero de $8.0");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 8.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 2:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "folders");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 4.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 3:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[0].numcli].tipos[turnos[0].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "curp");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 20.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 4:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[0].numcli].numtipos].numproductos].nombre, "opalina delgada");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 2.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 5:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "opalina gruesa");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 3.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 6:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "papel fotografico");
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 15.0;
						printf(" ingrese la cantidad de productos que se compro:\n");
						scanf("%i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					default:
						break;
					}
					turnos[1].clientes[turnos[1].numcli].numtipos++;
					break;
				case 4:
					printf("ingrese que tipo de producto va a comprar\n");
					menu1_4();
					do
					{
						scanf("%i", &typen);
					} while (typen < 1 || typen > 4);
					switch (typen)
					{
					case 1:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "recarga telcel");
						printf("ingrese el monto de la recarga:\n");
						scanf(" %f", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio);
						printf("ingrese la cantidad de recargas puestas:\n");
						scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 2:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "recarga at&t");
						printf("ingrese el monto de la recarga:\n");
						scanf(" %f", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio);
						printf("ingrese la cantidad de recargas puestas:\n");
						scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 3:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "recarga movistar");
						printf("ingrese el monto de la recarga:\n");
						scanf(" %f", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio);
						printf("ingrese la cantidad de recargas puestas:\n");
						scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					case 4:
						strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "recarga bait");
						printf("ingrese el monto de la recarga:\n");
						scanf(" %f", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio);
						printf("ingrese la cantidad de recargas puestas:\n");
						scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
						turnos[1].clientes[turnos[1].numcli].sumapr += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
						turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
						break;
					default:
						break;
					}
					turnos[1].clientes[turnos[1].numcli].numtipos++;
					break;
				default:
					break;
				}

				break;
			case 2:
				strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[0].numcli].numtipos].nombretipo, "servicios");

				menu2();
				printf("ingrese el servicio que va a necesitar:\n");
				do
				{
					scanf(" %i", &type);
				} while (type < 1 || type > 4);
				switch (type)
				{
				case 1:
					strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "actas");
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 170.0;
					printf("ingrese la cantidad que se compro:\n");
					scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
					turnos[1].clientes[turnos[1].numcli].sumase += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
					break;
				case 2:
					strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "rfc");
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 130.0;
					printf("ingrese la cantidad que se compro:\n");
					scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
					turnos[1].clientes[turnos[1].numcli].sumase += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
					break;
				case 3:
					strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "constancia de no inhabilitacion");
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 180.0;
					printf("ingrese la cantidad que se compro:\n");
					scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
					turnos[1].clientes[turnos[1].numcli].sumase += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
					break;
				case 4:
					strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "antecedentes no penales");
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 450.0;
					printf("ingrese la cantidad que se compro:\n");
					scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
					turnos[1].clientes[turnos[1].numcli].sumase += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
					break;
				default:
					break;
				}
				turnos[1].clientes[turnos[1].numcli].numtipos++;
				break;
			case 3:
				strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].nombretipo, "cibercafe");

				menu3();
				printf("ingrese el servicio que va a necesitar:\n");
				do
				{
					scanf(" %i", &type);
				} while (type < 1 || type > 4);
				switch (type)
				{
				case 1:
					strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "fotocopiado");
					printf("ingrese de cuanto fue la compra:\n");
					scanf(" %f", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio);
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad = 1;
					turnos[1].clientes[turnos[1].numcli].sumaci += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
					break;
				case 2:
					strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "impresion de documentos");
					printf("ingrese de cuanto fue la compra:\n");
					scanf(" %f", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio);
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad = 1;
					turnos[1].clientes[turnos[1].numcli].sumaci += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
					break;
				case 3:
					menu3_1();
					strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "renta de equipo de computo");
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 10.0;
					printf("ingrese la cantidad de horas usadas:\n");
					scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
					turnos[1].clientes[turnos[1].numcli].sumaci += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
					break;
				case 4:
					menu3_2();
					strcpy(turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].nombre, "renta de videoconsolas");
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio = 12.0;
					printf("ingrese la cantidad de horas usadas:\n");
					scanf(" %i", &turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad);
					turnos[1].clientes[turnos[1].numcli].sumaci += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].suma += turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].precio * turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].productos[turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos].cantidad;
					turnos[1].clientes[turnos[1].numcli].tipos[turnos[1].clientes[turnos[1].numcli].numtipos].numproductos++;
					break;
				default:
					break;
				}
				turnos[1].clientes[turnos[1].numcli].numtipos++;
				break;
			default:
				break;
			}

			printf("Desea agregar otro producto? (1: Si, 0: No):\n");
			do
			{
				scanf("%i", &cc);
				// SE USA LA FUNCION Y PARA DELIMITAR EL RANGO DE VALORES A SOLO DOS 1 Y 0 DONDE 0 ROMPE EL CICLO Y AVANZA Y 1 REINICIA EL SWITCH DE COMPRA
			} while (cc != 1 && cc != 0);
			if (cc == 0)
			{
				system("cls");
			}
		}

		printf("Desea continuar atendiendo clientes? (1: Si, 0: No):\n");
		do
		{
			scanf("%i", &conti);
			if (conti == 0)
			{
				turnos[1].estc = i + 1;
			}
			else
			{
				turnos[1].estc += 1;
			}

		} while (conti != 1 && conti != 0);
		// SE RECICLA EL VALOR DE LA VARIABLE CC PARA ASI LIMPIAR LA PANTALLA E IMPRIMIR EL CIERRE DE CAJA
		if (cc == 0)
		{
			system("cls");
		}

		turnos[1].tpr += turnos[1].clientes[turnos[1].numcli].sumapr;
		turnos[1].ts += turnos[1].clientes[turnos[1].numcli].sumase;
		turnos[1].tci += turnos[1].clientes[turnos[1].numcli].sumaci;
		turnos[1].sumt += turnos[1].clientes[turnos[1].numcli].suma;
		turnos[1].numcli++;
	}
}
void mostrarcli2()
{
	system("cls");
	time_t k = time(NULL);
	struct tm tm = *localtime(&k);
	int ci, ti;
	ti = 1;
	if (ti == 1)
	{
		printf("Datos de los clientes en el turno %i:\n", ti + 1);
		for (ci = 0; ci < turnos[ti].numcli; ci++)
		{
			printf("Cliente %i:\n", ci + 1);
			for (j = 0; j < turnos[ti].clientes[ci].numtipos; j++)
			{
				printf(" Tipo: %s\n", turnos[ti].clientes[ci].tipos[j].nombretipo);
				for (k = 0; k < turnos[ti].clientes[ci].tipos[j].numproductos; k++)
				{
					printf("  Producto: %s, Precio: %.2f, Cantidad: %d\n",
							turnos[ti].clientes[ci].tipos[j].productos[k].nombre,
							turnos[ti].clientes[ci].tipos[j].productos[k].precio,
							turnos[ti].clientes[ci].tipos[j].productos[k].cantidad);
				}
			}
			printf("Suma total del cliente: %.2f\n", turnos[ti].clientes[ci].suma);
		}
		printf("Dia: %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		printf("Encargado: %s\n", turnos[1].encargado);
		printf("Total productos y recargas: %.2f\n", turnos[1].tpr);
		printf("Total servicios: %.2f\n", turnos[1].ts);
		printf("Total cibercafe: %.2f\n", turnos[1].tci);
		printf("Suma total: %.2f\n", turnos[1].sumt);
		printf("Ganancia del dia: %.2f\n", turnos[1].tci);
	}
}
void buscar2()
{
	int clin, bus;
	bus = 0;
	printf("que cliente desea buscar?\n");
	scanf(" %i", &clin);
	for (i = 0; i < turnos[1].estc; i++)
	{
		if (i + 1 == clin)
		{
			printf("el cliente bucado se encontro en la posicion %i", i + 1);
			bus = 1;
			printf("Datos del cliente %i:\n", clin);
			for (int j = 0; j < turnos[1].clientes[i].numtipos; j++)
			{
				printf(" Tipo: %s\n", turnos[1].clientes[i].tipos[j].nombretipo);
				for (int k = 0; k < turnos[1].clientes[i].tipos[j].numproductos; k++)
				{
					printf("  Producto: %s, Precio: %.2f, Cantidad: %d\n",
							turnos[1].clientes[i].tipos[j].productos[k].nombre,
							turnos[1].clientes[i].tipos[j].productos[k].precio,
							turnos[1].clientes[i].tipos[j].productos[k].cantidad);
				}
			}
		}
	}
	if (!bus)
	{
		printf("cliente no encontrado\n");
	}
}
void ordenar2()
{
	int ption;
	printf("de que manera quiere ordenar los totales de los clientes?\n1) ascendente\n2) descendente\n");
	scanf(" %i", &ption);
	switch (ption)
	{
	case 1:
		ascendente2();
		break;
	case 2:
		descendente2();
		break;
	default:
		break;
	}
}
void ascendente2()
{

	for (i = 0; i < turnos[1].estc - 1; i++)
	{
		for (j = 0; j < turnos[1].estc - i - 1; j++)
		{
			if (turnos[1].clientes[j].suma > turnos[1].clientes[j + 1].suma)
			{
				aux = turnos[1].clientes[j];
				turnos[1].clientes[j] = turnos[1].clientes[j + 1];
				turnos[1].clientes[j + 1] = aux;
			}
		}
	}
}

void descendente2()
{
	for (i = 0; i < turnos[1].estc - 1; i++)
	{
		for (j = 0; j < turnos[1].estc - i - 1; j++)
		{
			if (turnos[1].clientes[j].suma < turnos[1].clientes[j + 1].suma)
			{
				aux = turnos[1].clientes[j];
				turnos[1].clientes[j] = turnos[1].clientes[j + 1];
				turnos[1].clientes[j + 1] = aux;
			}
		}
	}
}
void modificar2()
{
	int clim, bus = 0, ot, otion, oc;

	printf("Que cliente desea modificar?\n");
	scanf("%i", &clim);

	for (int i = 0; i < turnos[1].estc; i++)
	{
		if (i + 1 == clim)
		{
			printf("El cliente buscado se encontro en la posicion %i\n", i + 1);
			bus = 1;

			printf("Datos actuales del cliente %i:\n", clim);
			for (int j = 0; j < turnos[1].clientes[i].numtipos; j++)
			{
				printf(" Tipo: %s\n", turnos[1].clientes[i].tipos[j].nombretipo);
				for (int k = 0; k < turnos[1].clientes[i].tipos[j].numproductos; k++)
				{
					printf("  Producto: %s, Precio: %.2f, Cantidad: %d\n",
							turnos[1].clientes[i].tipos[j].productos[k].nombre,
							turnos[1].clientes[i].tipos[j].productos[k].precio,
							turnos[1].clientes[i].tipos[j].productos[k].cantidad);
					printf("%f\n", turnos[1].tpr);
					printf("%f\n", turnos[1].ts);
					printf("%f\n", turnos[1].tci);
					Sleep(500);
				}
			}

			for (int j = 0; j < turnos[1].clientes[i].numtipos; j++)
			{
				for (int k = 0; k < turnos[1].clientes[i].tipos[j].numproductos; k++)
				{
					if (strcmp(turnos[1].clientes[i].tipos[j].nombretipo, "productos y recargas") == 0)
					{
						turnos[1].tpr -= turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
						turnos[1].sumt -= turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
						turnos[1].clientes[i].sumapr -= turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
					}
					if (strcmp(turnos[1].clientes[i].tipos[j].nombretipo, "servicios") == 0)
					{
						turnos[1].ts -= turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
						turnos[1].sumt -= turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
						turnos[1].clientes[i].sumase -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
					}
					if (strcmp(turnos[1].clientes[i].tipos[j].nombretipo, "cibercafe") == 0)
					{
						turnos[1].tci -= turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
						turnos[1].sumt -= turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
						turnos[1].clientes[i].sumaci -= turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[0].clientes[i].tipos[j].productos[k].cantidad;
					}
				}
			}

			turnos[1].clientes[i].suma = 0;
			for (int j = 0; j < turnos[1].clientes[i].numtipos; j++)
			{
				for (int k = 0; k < turnos[1].clientes[i].tipos[j].numproductos; k++)
				{
					turnos[1].clientes[i].tipos[j].productos[k].precio = 0;
					turnos[1].clientes[i].tipos[j].productos[k].cantidad = 0;
				}
			}
			printf("Ingrese los nuevos datos para el cliente %i:\n", clim);

			for (int j = 0; j < turnos[1].clientes[i].numtipos; j++)
			{

				printf(" tipo actual: %s\n", turnos[1].clientes[i].tipos[j].nombretipo);
				men();
				printf("ingrese el nuevo tipo de producto (o el mismo):\n");
				scanf(" %i", &ot);
				switch (ot)
				{
				case 1:
					strcpy(turnos[1].clientes[i].tipos[j].nombretipo, "productos y recargas");
					break;
				case 2:
					strcpy(turnos[1].clientes[i].tipos[j].nombretipo, "servicios");
					break;
				case 3:
					strcpy(turnos[1].clientes[i].tipos[j].nombretipo, "cibercafe");
					break;
				}
				for (int k = 0; k < turnos[1].clientes[i].tipos[j].numproductos; k++)
				{
					turnos[1].clientes[i].suma = 0;
					turnos[1].clientes[i].sumapr = 0;
					turnos[1].clientes[i].sumase = 0;
					turnos[1].clientes[i].sumaci = 0;
					printf(" producto actual: %s\n", turnos[1].clientes[i].tipos[j].productos[k].nombre);
					printf("ingrese el nuevo nombre del producto (o el mismo):\n");
					if (strcmp(turnos[1].clientes[i].tipos[j].nombretipo, "productos y recargas") == 0)
					{

						menu1();
						scanf(" %i", &otion);
						switch (otion)
						{
						case 1:
							menu1_1();
							scanf(" %i", &oc);
							switch (oc)
							{
							case 1:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "sabritas de $15.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 15.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 2:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "sabritas de $17.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 17.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 3:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "sabritas de $20.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 20.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[0].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							default:
								break;
							}
							break;
						case 2:
							menu1_2();
							scanf(" %i", &oc);
							switch (oc)
							{
							case 1:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "gamesa de $12.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 12.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 2:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "gamesa de $18.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 18.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 3:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "gamesa de $20.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 20.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							default:
								break;
							}
							break;
						case 3:
							menu1_3();
							scanf(" %i", &oc);
							switch (oc)
							{
							case 1:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "lapiceros de $8.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 8.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 2:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "folders de $4.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 4.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 3:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "curp $20.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 20.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 4:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "opalina delgada de $2.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 2.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 5:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "opalina gruesa de $3.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 3.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 6:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "papel fotografico de $15.0");
								turnos[1].clientes[i].tipos[j].productos[k].precio = 15.0;
								printf("ingrese la nueva cantidad del producto:\n");
								scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							default:
								break;
							}
							break;
						case 4:
							menu1_4();
							scanf(" %i", &oc);
							switch (oc)
							{
							case 1:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "recarga telcel");
								printf("ingrese el precio de la recarga\n");
								scanf(" %f", &turnos[1].clientes[i].tipos[j].productos[k].precio);
								printf("ingrese la nueva cantidad de recargas:\n");
								scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 2:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "recarga at&t");
								printf("ingrese el precio de la recarga\n");
								scanf(" %f", &turnos[1].clientes[i].tipos[j].productos[k].precio);
								printf("ingrese la nueva cantidad de recargas:\n");
								scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 3:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "recarga movistar");
								printf("ingrese el precio de la recarga\n");
								scanf(" %f", &turnos[1].clientes[i].tipos[j].productos[k].precio);
								printf("ingrese la nueva cantidad de recargas:\n");
								scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							case 4:
								strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "recarga bait");
								printf("ingrese el precio de la recarga\n");
								scanf(" %f", &turnos[1].clientes[i].tipos[j].productos[k].precio);
								printf("ingrese la nueva cantidad de recargas:\n");
								scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
								turnos[1].clientes[i].sumapr += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
								break;
							default:
								break;
							}
							break;
						default:
							break;
						}
					}
					if (strcmp(turnos[1].clientes[i].tipos[j].nombretipo, "servicios") == 0)
					{
						menu2();
						scanf(" %i", &otion);
						switch (otion)
						{
						case 1:
							strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "actas");
							turnos[1].clientes[i].tipos[j].productos[k].precio = 170.0;
							printf("ingrese la nueva cantidad del producto:\n");
							scanf(" %i", &turnos[0].clientes[i].tipos[j].productos[k].cantidad);
							turnos[1].clientes[i].sumase += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 2:
							strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "rfc");
							turnos[1].clientes[i].tipos[j].productos[k].precio = 130.0;
							printf("ingrese la nueva cantidad del producto:\n");
							scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
							turnos[1].clientes[i].sumase += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 3:
							strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "constancia de no inhabilitacion");
							turnos[1].clientes[i].tipos[j].productos[k].precio = 180.0;
							printf("ingrese la nueva cantidad del producto:\n");
							scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
							turnos[1].clientes[i].sumase += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 4:
							strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "antecedentes no penales");
							turnos[1].clientes[i].tipos[j].productos[k].precio = 450.0;
							printf("ingrese la nueva cantidad del producto:\n");
							scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
							turnos[1].clientes[i].sumase += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							break;
						default:
							break;
						}
					}
					if (strcmp(turnos[1].clientes[i].tipos[j].nombretipo, "cibercafe") == 0)
					{
						menu3();
						scanf(" %i", &otion);
						switch (otion)
						{
						case 1:
							strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "fotocopiado");
							printf("ingrese la cantidad de la compra\n");
							scanf(" %f", &turnos[1].clientes[i].tipos[j].productos[k].precio);
							turnos[1].clientes[i].tipos[j].productos[k].cantidad = 1;
							turnos[1].clientes[i].sumaci += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 2:
							strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "impresion de documentos");
							printf("ingrese la cantidad de la compra\n");
							scanf(" %f", &turnos[1].clientes[i].tipos[j].productos[k].precio);
							turnos[1].clientes[i].tipos[j].productos[k].cantidad = 1;
							turnos[1].clientes[i].sumaci += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 3:
							menu3_1();
							strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "renta de equipo de computo");
							turnos[1].clientes[i].tipos[j].productos[k].precio = 10.0;
							printf("ingrese la cantidad de horas usadas:\n");
							scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
							turnos[1].clientes[i].sumaci += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							break;
						case 4:
							menu3_2();
							strcpy(turnos[1].clientes[i].tipos[j].productos[k].nombre, "renta de videoconsolas");
							turnos[1].clientes[i].tipos[j].productos[k].precio = 12.0;
							printf("ingrese la cantidad de horas usadas:\n");
							scanf(" %i", &turnos[1].clientes[i].tipos[j].productos[k].cantidad);
							turnos[1].clientes[i].sumaci += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							turnos[1].clientes[i].suma += turnos[1].clientes[i].tipos[j].productos[k].precio * turnos[1].clientes[i].tipos[j].productos[k].cantidad;
							break;
						default:
							break;
						}
					}
					turnos[1].tpr += turnos[1].clientes[i].sumapr;
					turnos[1].ts += turnos[1].clientes[i].sumase;
					turnos[1].tci += turnos[1].clientes[i].sumaci;
					turnos[1].sumt += turnos[1].clientes[i].suma;
				}
			}
			printf("los datos del cliente %i han sido actualizados.\n", clim);
			break;
		}
	}

	if (!bus)
	{
		printf("cliente no encontrado\n");
	}
}

void men()
{
	system("cls");
	printf("los tipos de pruductos que se maneja son 3\n");
	printf("1: productos y recargas\n");
	printf("recargas telefonicas y venta de productos de tienda y papeleria.\n");
	printf("2: servicios\n");
	printf("actualizacion de actas de nacimiento RFC y diversos documentos.\n");
	printf("3: cibercafe\n");
	printf("cobro del servico de renta de maquinas, xbox, fotocopiado e impresiones\n");
	printf("\n");
	Sleep(1000);
}
void menu1()
{
	system("cls");
	printf("productos y recargas que se ofrecen en el ciber cafe:\n");
	printf("1-sabritas\n");
	printf("2-gamesa\n");
	printf("3-papeleria\n");
	printf("4-recargas\n");
	printf("\n");
	Sleep(1000);
}
void menu1_1()
{
	system("cls");
	printf("1-sabritas de $15.00\n");
	printf("2-sabritas de $17.00\n");
	printf("3-sabritas de $20.00\n");
	printf("\n");
	Sleep(1000);
}
void menu1_2()
{
	system("cls");
	printf("1-gamesa de $12.00\n");
	printf("2-gamesa de $18.00\n");
	printf("3-gamesa de $20.00\n");
	printf("\n");
	Sleep(1000);
}
void menu1_3()
{
	system("cls");
	printf("1-lapiceros de $8.00\n");
	printf("2-folders de $4.00\n");
	printf("3-hoja de seguridad de $20.00\n");
	printf("4-opalina delgada de $2.00\n");
	printf("5-opalina gruesa de $3.00\n");
	printf("6-papel fotografico de $15.00\n");
	printf("\n");
	Sleep(1000);
}
void menu1_4()
{
	system("cls");
	printf("1-recarga telcel\n");
	printf("2-recarga at&t\n");
	printf("3-recarga movistar\n");
	printf("4-recarga bait\n");
}
void menu2()
{
	system("cls");
	printf("Los servicios ofrecidos por el ciber son los siguientes:\n");
	printf("1-actualizacion de actas de nacimiento, defuncion, matrimonio y divorcio: $170.00\n");
	printf("2-actualizacion de RFC: $130.00\n");
	printf("3-contancia de no inhabilitacion: $180.00\n");
	printf("4-antecedentes no penales: $450.00\n");
	printf("\n");
	Sleep(1000);
}
void menu3()
{
	system("cls");
	printf("el servicio de cibercafe consta de:\n");
	printf("1-fotocopiado\n");
	printf("2-impresion de documentos\n");
	printf("3-renta de equipo de computo\n");
	printf("4-renta de video consolas\n");
	printf("\n");
	Sleep(1000);
}
void menu3_1()
{
	system("cls");
	printf("el uso de computadoras se cobra la hora a 10 pesos");
	printf("\n");
	Sleep(1000);
}
void menu3_2()
{
	system("cls");
	printf("el uso de consonlas se cobra la hora a 12 pesos ");
	printf("\n");
	Sleep(1000);
}
