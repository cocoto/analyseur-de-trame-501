#include "eth_lib.h"
//#include "eth_lib.o"
//#include "inet_str.h"

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
int main ()
{
	/*while(1)
	{
		eth_frame trame = lire_trame();
		dump_eth_header(struct eth_frame * f);
	}*/
	return 0;
}
