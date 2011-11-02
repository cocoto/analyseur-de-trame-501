#include "eth_lib.h"

typedef struct tab_stat tab_stat;
struct eth_frame * lire_trame() // procedure d'une trame
{
	char ch[50];
	int nb;
	static struct eth_frame latrame;
	fscanf(stdin, "%s", ch); // pour lire : "byte reçu :" (3 chaines)
	fscanf(stdin, "%s", ch); // pour lire : "byte reçu :" (3 chaines)
	fscanf(stdin, "%s", ch); // pour lire : "byte reçu :" (3 chaines)
	fscanf(stdin, "%d", &nb); // nb octets = taille de la trame
	get_buf((unsigned char *) &latrame, nb); // &latrame : lecture trame
	return &latrame;
}

struct tab_stat
{
	char ad[13];
	tab_stat* suivant;
};
 
int recherche(char* adr , tab_stat *stat ){
printf("recherche\n");
do
{if (!(strcmp(adr,stat->ad)))
	{return 1;}
	else {
	stat=stat->suivant;
	}	
}while (stat != NULL);
return 0;
}

tab_stat ajout (char* adr , tab_stat *stat ){
printf("ajout\n");
tab_stat nouveau;
nouveau.suivant=stat; //bordel
strcpy(nouveau.ad,adr);
return nouveau;
}

int affiche(tab_stat *stat){
do
{printf("%s" , &stat->ad);
 stat=stat->suivant;	
}while (stat != NULL);
return 1;
}

int main ()
{
	struct eth_frame *trame;
	char *ad = "000000000000";
	char *ad_source = "000000000000";
	char *ad_dest ="000000000000";
	int i=100;
	tab_stat stat;
	stat.suivant = NULL;
	char *chaine ="ffffffffffff";
	strcpy(stat.ad,chaine);
	affiche(&stat);
	while(i>0)
	{	printf("testdeb\n");
		trame = lire_trame();
		ad_dest = char_to_charhexa(trame -> adr_dest,6);
		ad_source = char_to_charhexa(trame -> adr_send,6);
		printf("test recherche\n");
		if (recherche(ad_dest, &stat))
		{
		stat = ajout(ad_dest, &stat);
		}
		if (recherche(ad_source, &stat))
		{stat = ajout(ad_source, &stat);
		}
		printf("Type : %s \n", char_to_charhexa(trame -> type,2));
		printf("Adresse dest : %s \n", char_to_charhexa(trame -> adr_dest,6));
		printf("Adresse source : %s \n", char_to_charhexa(trame -> adr_send,6));
		i--;
		printf("testfin\n");
	}
	affiche(&stat);
	return 0;
}

