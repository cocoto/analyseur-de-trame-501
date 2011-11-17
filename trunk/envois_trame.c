#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "eth_lib.h"
void envois_trame(char *source, char *dest, char *message)
{	
	//Génération de la trame en question
	char *type="9000";
	struct eth_frame *latrame=malloc(sizeof(struct eth_frame));
	int taille=make_ping_request(dest,source,type,message,latrame);
	char *tramehexa=char_to_charhexa((unsigned char*)&latrame,taille);
	char commande[500];
	strcpy(commande,"./write_eth_frame ");
	strcat(commande,tramehexa);
	printf("%s\n",commande);
	system(commande);
}
int main ()
{
	envois_trame("00:12:3f:3c:5e:6e","00:12:3f:3c:5e:da","coucou");
	return 0;
}
