#define NOMBRE_ENVOIS 10
#define TEMPS_ATTENTE 1
#define ADRESSE "e0:cb:4e:2f:fc:98"
#define MESSAGE "Bonjour de Quentin et Adrien"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eth_lib.h"
#include "fonctions.h"
int main(int argc, char * argv[])
{
	char* adresse=malloc(sizeof(char)*18);
	if(argc==2)
	{
		adresse=argv[1];	//si notre adresse est passée en paramètre
	}
	else
	{
		adresse=ADRESSE; //sinon celle par défaut
	}
	int i;
	for(i=0; i<NOMBRE_ENVOIS; i++)
	{
		printf("envois de %s no %d \n",MESSAGE,i+1);
		envois_trame(adresse,"ff:ff:ff:ff:ff:ff",MESSAGE);
		sleep(TEMPS_ATTENTE);
	}
	return 0;
}
