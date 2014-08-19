/*
 ====================================================================================
 Nombre      : stack_memory.c
 Autor     	 : Abdel Gadiel Martinez Lassonde
 Version     : 1.0
 Copyright   : GNU General Public License v2.0
 Descripcion : Proyecto academico de administracion de aplicaciones moviles por pilas
 ====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
   float valor;
   int id;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;

void Push(Pila *l, float v, int i);
int Pop(Pila *l);

int Pop(Pila *pila)
{
   pNodo nodo;
   int v;

   nodo = *pila;
   if(!nodo) return 0;
   *pila = nodo->siguiente;
   v = nodo->valor;
   free(nodo);
   return v;
}

void Push(Pila *pila, float v, int i)
{
   pNodo nuevo;

   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   nuevo->id = i;

   nuevo->siguiente = *pila;
   *pila = nuevo;
}

static float memoria = 200.0;
static float usada = 0.0;
static Pila pila = NULL;

int validar(float v, int i)
{
	float actual = 0.0;
	tipoNodo *abierta=pila;
	while(abierta!=NULL){
			if (i == abierta->id) {
				return 1;
			}
			abierta=abierta->siguiente;
	}
	while ((usada+v) >= 200) {
		usada = usada - pila->valor;
		memoria = memoria + pila->valor;
	    Pop(&pila);
	}
	Push(&pila, v, i);
	actual = (*pila).valor;
	memoria = memoria - actual;
	usada = usada + actual;
	//printf("Current App Memory: %.2f  \t   Memory Available: %.2f   \t   Memory Usage: %.2f", actual, memoria, usada);
	return 0;
}

void imprimir(void)
{
	tipoNodo *abierta=pila;
	char *app[100];
	if(abierta!=NULL)
	{
		printf("\nAplicaciones Abiertas:\n");
		while(abierta!=NULL)
		{
			if (abierta->id == 1) {*app = "Amazon";}
			if (abierta->id == 2) {*app = "Facebook";}
			if (abierta->id == 3) {*app = "Twitter";}
			if (abierta->id == 4) {*app = "Instagram";}
			if (abierta->id == 5) {*app = "Mail";}
			if (abierta->id == 6) {*app = "Browser";}
			if (abierta->id == 7) {*app = "Whatsapp";}
			if (abierta->id == 8) {*app = "Waze";}
			if (abierta->id == 9) {*app = "Music";}
			if (abierta->id == 10) {*app = "Camera";}
			printf("\tAplicacion: %s \tMemoria: %.2f\n", *app, abierta->valor);
			abierta=abierta->siguiente;
		}
		printf("\n");
	} else printf("\nNo hay aplicaciones abiertas.\n");
}

void cargar(void)
{

 int app = 1;
 int flag = 0;
 printf("\nElija una aplicacion:\n");
 printf("\t 1.  Amazon\t 15MB\n");
 printf("\t 2.  Facebook\t 35MB\n");
 printf("\t 3.  Twitter\t 25MB\n");
 printf("\t 4.  Instagram\t 50MB\n");
 printf("\t 5.  Mail\t 25MB\n");
 printf("\t 6.  Browser\t 75MB\n");
 printf("\t 7.  Whataspp\t 50MB\n");
 printf("\t 8.  Waze\t 150MB\n");
 printf("\t 9.  Music\t 50MB\n");
 printf("\t 10. Camera\t 100MB\n");
 printf("\n\n Introduzca su opcion (si no es valido vuelve al menu): ");
 scanf("%d", &app);
 if (app == 1) {
     flag = validar(15, app);
     if (flag == 0){
         printf("\nAbristes Amazon.\n");
     } else {
    	 printf("\nAmazon ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 2) {
	 flag = validar(35, app);
     if (flag == 0){
    	 printf("\nAbristes Facebook.\n");
     } else {
    	 printf("\nFacebook ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 3) {
	 flag = validar(25, app);
     if (flag == 0){
         printf("\nAbristes Twitter.\n");
     } else {
    	 printf("\nTwitter ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 4) {
	 flag = validar(50, app);
     if (flag == 0){
    	 printf("\nAbristes Instagram.\n");
     } else {
    	 printf("\nInstagram ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 5) {
	 flag = validar(25, app);
     if (flag == 0){
    	 printf("\nAbristes Mail.\n");
     } else {
    	 printf("\nMail ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 6) {
	 flag = validar(75, app);
     if (flag == 0){
    	 printf("\nAbristes Browser.\n");
     } else {
    	 printf("\nBrowser ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 7) {
	 flag = validar(50, app);
     if (flag == 0){
         printf("\nAbristes Whatsapp.\n");
     } else {
    	 printf("\nWhatsapp ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 8) {
	 flag = validar(150, app);
     if (flag == 0){
    	 printf("\nAbristes Waze.\n");
     } else {
    	 printf("\nWaze ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 9) {
	 flag = validar(50, app);
     if (flag == 0){
    	 printf("\nAbristes Music.\n");
     } else {
    	 printf("\nMusic ya esta abierto. Intente otra aplicacion.\n");
     }
 } else if (app == 10) {
	 flag = validar(100, app);
     if (flag == 0){
    	 printf("\nAbristes Camera.\n");
     } else {
    	 printf("\nCamera ya esta abierto. Intente otra aplicacion.\n");
     }
 } else {
     printf("\nVa a volver al menu principal.\n");
 }
}

int main(void)
{
 int choice=0;
 while(choice!=4)
 {
  printf("\nMEMORIA DE CELULAR COMO PILA");
  printf("\n------------------------------");
  printf("\n\n\t 1. Listar memoria disponible");
  printf("\n\t 2. Abrir una aplicación");
  printf("\n\t 3. Ver aplicaciones abiertas");
  printf("\n\t 4. Salir");
  printf("\n\n Introduzca su opcion: ");
  scanf("%d", &choice);
  switch(choice)
  {
   case 1:
              printf("\nLa memoria disponible es %.2fMB\n\n", memoria);
              break;
   case 2:
              cargar();
              break;
   case 3:
              imprimir();
              break;
   case 4:
              printf("\nGracias por utilizar nuestro simulador.");
              exit(0);
   default:
              printf("\nSELECCION NO VALIDA... Intente nuevamente.\n\n");
              break;
   }
 }
 return EXIT_SUCCESS;
}
