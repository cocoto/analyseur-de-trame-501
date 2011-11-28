//#include "eth_lib.h"

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
	tab_stat *suivant;
	char ad[13];
};
 
int recherche(char* adr , tab_stat* stat ){
printf("recherche de %s dans la table..........................",adr);
do
{
	if (strcmp(adr,stat->ad)==0)
		{printf("trouve !\n");return 1;}
	else {
		stat=stat->suivant;
	}
}while (stat!= NULL);
printf("non trouvé !\n");
return 0;
}

tab_stat* ajout (char* adr , tab_stat* stat ){
	printf("ajout de %s dans la table........................",adr);
	tab_stat* nouveau=(tab_stat*)malloc (sizeof (tab_stat));
	strcpy(nouveau->ad,adr);
	nouveau->suivant=stat;
	printf("ok !\n");
	return nouveau;
}

int affiche(tab_stat* stat){
printf("Adresses détectées sur le réseau : \n");
int cpt;
cpt=4;
do
{printf("%s\n" , stat->ad);
 stat=stat->suivant;
 cpt--;	
}while (stat != NULL && cpt!=0);
return 1;
}

int main ()
{
	struct eth_frame *trame;
	int i=100;			//LIMITE DE BOUCLE (TRAVAIL LOCAL)
	tab_stat* stat=(tab_stat*)malloc (sizeof (tab_stat));
	//affiche(stat);		//AFFICHE UN TABLEAU VIDE
	while(i>0)
	{	
		trame = lire_trame();
		//on imprime les informations obtenues
		printf("Type : %s \n", char_to_charhexa(trame -> type,2));
		printf("Adresse dest : %s \n", char_to_charhexa(trame -> adr_dest,6));
		printf("Adresse source : %s \n", char_to_charhexa(trame -> adr_send,6));

		//on recherche et ajoute les deux adresses dans la table "stat"
		printf("###########\n");
		if (!recherche(char_to_charhexa(trame -> adr_dest,6), stat))
		{
			stat = ajout(char_to_charhexa(trame -> adr_dest,6), stat);
		}
		if (!recherche(char_to_charhexa(trame -> adr_send,6), stat))
		{
			stat = ajout(char_to_charhexa(trame -> adr_send,6), stat);
		}
		printf("###########\n\n\n");


		i--;//Supprimer en cas de non-limite à la boucle
	}
	affiche(stat);			//AFFICHE LE RESULTAT
	return 0;
}

