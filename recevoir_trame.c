#define TEMPS_AFFICHAGE 50 //Nombre de trame avant affichage de la liste
#include <stdio.h>
#include <stdlib.h>
#include "eth_lib.h"
#include "fonctions.h"
#include "recevoir_trame.h"
int main(int argc, char *argv[])
{
	struct eth_frame *trame;
	tab_stat* stat=(tab_stat*)malloc (sizeof (tab_stat));
	int i=1;
	while(1)
	{	
		trame = lire_trame();
		//on recherche et ajoute les deux adresses dans la table "stat"
		if (!recherche(char_to_charhexa(trame -> adr_dest,6), stat))
		{
			stat = ajout(char_to_charhexa(trame -> adr_dest,6), stat);
		}
		if (!recherche(char_to_charhexa(trame -> adr_send,6), stat))
		{
			stat = ajout(char_to_charhexa(trame -> adr_send,6), stat);
		}
		if(strcmp(char_to_charhexa(trame -> type,2),"9000")==0) //Si le type est 9000
		{
			//on imprime les informations obtenues
			printf("%d --> %s : %s \n",i,char_to_charhexa(trame-> adr_send,6),trame->data);
			i++;
		}
		if(i % TEMPS_AFFICHAGE==0)
		{
			affiche(stat);
		}
	}
	
	return 0;
}

int recherche(char* adr , tab_stat* stat ){
//printf("recherche de %s dans la table..........................",adr);
do
{
	if (strcmp(adr,stat->ad)==0)
	{
		//printf("trouve !\n");
		return 1;
	}
	else {
		stat=stat->suivant;
	}
}while (stat!= NULL);
//printf("non trouvé !\n");
return 0;
}

tab_stat* ajout (char* adr , tab_stat* stat ){
	//printf("ajout de %s dans la table........................",adr);
	tab_stat* nouveau=(tab_stat*)malloc (sizeof (tab_stat));
	strcpy(nouveau->ad,adr);
	nouveau->suivant=stat;
	//printf("ok !\n");
	return nouveau;
}

int affiche(tab_stat* stat){
printf("Adresses détectées sur le réseau : \n ========================================= \n");
do
{
 printf("%s ::: " , stat->ad);
 stat=stat->suivant;
}while (stat != NULL);
printf("\n===============================================================================\n");
return 1;
}
