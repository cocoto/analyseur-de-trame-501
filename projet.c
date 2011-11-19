#include "eth_lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	char* adresse=argv[1];
	char * message="coucou ";
	while(1)
	{
		struct eth_frame *trame = lire_trame();
		if(strcmp(char_to_charhexa(trame -> adr_dest,6),adresse)==0 && strcmp(char_to_charhexa(trame -> type,2),"9000")==0)
		//Si nous sommes le destinataire et type=9000
		{
			char *adresse_cible=char_to_charhexa(trame -> adr_send,6);
			//@TODO Vérifier le message à retourner et adapter le code
			envois_trame(adresse,adresse_cible,strcat(message,adresse_cible));
		}
	}
	return 0;
}
