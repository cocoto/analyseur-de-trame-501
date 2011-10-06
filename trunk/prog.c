#include "eth_lib.c"

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
	char ad_dest[6];
	char ad_src[6];
	char type[2];
	int nb[1];
};

int main ()
{
	struct eth_frame *trame;
	char *ad = "000000000000";
	char *ad_source = "000000000000";
	char *ad_dest ="000000000000";
	
	tab_stat stat[100];

	while(1)
	{
		trame = lire_trame();
		
		
		printf("Type : %s \n", char_to_charhexa(trame -> type,2));
		printf("Adresse dest : %s \n", char_to_charhexa(trame -> adr_dest,6));
		printf("Adresse source : %s \n", char_to_charhexa(trame -> adr_send,6));
	}
	return 0;
}

