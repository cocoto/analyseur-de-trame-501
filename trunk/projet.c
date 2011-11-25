#define ADRESSE "e0:cb:4e:2f:fc:98"

#include "eth_lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main (int argc, char *argv[])
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
	char * message=" : recu par Quentin & Adrien"; //message de réponse (après message originel)
  	char * adr_hexa_dest=malloc(sizeof(char)*18); //adresse du destinataire après conversion
  	char * adr_hexa_send=malloc(sizeof(char)*18);//adresse de l'emetteur après conversion
  	struct eth_frame *trame;
	while(1)
	{	
		trame=lire_trame(); //On crée la trame issue de l'entrée standard
		if(strcmp(char_to_charhexa(trame -> type,2),"9000")==0) //Si le type est 9000
		{
			convaddr(char_to_charhexa(trame-> adr_dest,6),adr_hexa_dest);
			convaddr(char_to_charhexa(trame-> adr_send,6),adr_hexa_send);
			//On converti les adresses de type 123456789012 en 12:34:56:78:90:12
			if((strcmp(adr_hexa_dest,adresse)==0 || strcmp(adr_hexa_dest,"ff:ff:ff:ff:ff:ff")==0) && strcmp(adr_hexa_send,adresse)!=0)
			//Si nous sommes concernés (mais nous ne sommes pas l'emmeteur)
			{
				if(est_dans(trame->data,':')!=1)
				//Si le message n'est pas une réponse (format XXXXX : XXXXX)
				{
					//on envois la trame de réponse
					envois_trame(adresse,adr_hexa_send,strcat(trame->data,message));
				}
			}
		}
	}
	return 0;
}
