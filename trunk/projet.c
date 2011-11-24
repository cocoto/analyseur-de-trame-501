#include "eth_lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//Fonction de conversion d'une adress de type "00123f3c5e6e" en "00:12:3f:3c:5e:6e"
int est_dans(char * chaine, char car)
{
	int i;
	for(i=0;i<strlen(chaine);i++)
	{
		if(chaine[i]==car)
		{
			return 1;
		}
	}
	return 0;
}
void convaddr(char* adresse, char* adr_dest)
{
	sprintf(adr_dest,"%c%c:%c%c:%c%c:%c%c:%c%c:%c%c",
		adresse[0],
		adresse[1],
		adresse[2],
		adresse[3],
		adresse[4],
		adresse[5],
		adresse[6],
		adresse[7],
		adresse[8],
		adresse[9],
		adresse[10],
		adresse[11]);
}


//Fonction lire_trame qui permet de lire l'ensemble de la trame et retourne cette dernière.
struct eth_frame* lire_trame()
{
	char ch[50];
	int nb;
	static  struct eth_frame latrame;
	fscanf(stdin,"%s",ch);
	fscanf(stdin,"%s",ch);
	fscanf(stdin,"%s",ch);
	fscanf(stdin,"%d",&nb);
	get_buf((unsigned char*) &latrame,nb);
	return &latrame;
}
int main (int argc, char *argv[])
{
	char* adresse=argv[1];	//Notre adresse passée en paramètre
	char * message=" : recu par Quentin & Adrien";
  	char * adr_hexa=malloc(sizeof(char)*18);
  	int i=0;
	while(1)
	{	
		if(i<1000)
		{
			envois_trame(adresse,"ff:ff:ff:ff:ff:ff","Bonjour de Quentin & Adrien");
			i++;
		}
		/*==============ENVOIS EN BOUCLE DE BONJOUR !=====================*/
		
		//envois_trame("00:12:3f:3d:96:57","ff:ff:ff:ff:ff:ff","Bonjour de Quentin & Adrien");
		
		
		/*==============REPONSE AUX BONJOURS=========================*/
		struct eth_frame *trame = lire_trame();
    		convaddr(char_to_charhexa(trame-> adr_dest,6),adr_hexa);
		if((strcmp(adr_hexa,adresse)==0 || strcmp(adr_hexa,"ff:ff:ff:ff:ff:ff")==0) && strcmp(char_to_charhexa(trame -> type,2),"9000")==0)
		//Si nous sommes le destinataire et type=9000
		{
			
			if(est_dans(trame->data,':')!=1)
			//Si le message contient "Bonjour de", mais ne contient pas "reçu par" (évite les boucles)
			{
				printf("Message : %s \n",trame->data);
				char * adr_rec_hexa=malloc(sizeof(char)*18);
				convaddr(char_to_charhexa(trame-> adr_send,6),adr_rec_hexa);
				envois_trame(adresse,adr_rec_hexa,strcat(trame->data,message));
			}
		}
	}
	return 0;
}
