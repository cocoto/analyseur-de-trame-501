#include "fonctions.h"
#include "eth_lib.h"
#include <stdio.h>
//Fonction lire_trame qui permet de lire l'ensemble de la trame et retourne cette dernière.
struct eth_frame* lire_trame()
{
	char ch[50];
	int nb;
	static struct eth_frame latrame;
	fscanf(stdin,"%s",ch);
	fscanf(stdin,"%s",ch);
	fscanf(stdin,"%s",ch);
	fscanf(stdin,"%d",&nb);
	get_buf((unsigned char*) &latrame,nb);
	return &latrame;
}

//Cherche un caractère dans une chaine
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

//Fonction de conversion d'une adress de type "00123f3c5e6e" en "00:12:3f:3c:5e:6e"
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

//Envois une trame sur le réseau, de type 9000
void envois_trame(char *source, char *dest, char *message)
{	
	//Génération de la trame en question
	char *type="9000";
	struct eth_frame latrame;
	int taille=make_ping_request(dest,source,type,message,&latrame);
	char *tramehexa=char_to_charhexa((unsigned char*)&latrame,taille);
	char commande[1600];
	strcpy(commande,"./write_eth_frame ");
	strcat(commande,tramehexa);
	//printf("%s\n",commande);
	system(commande);
}

