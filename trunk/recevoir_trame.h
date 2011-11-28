typedef struct tab_stat tab_stat;
struct tab_stat
{
	tab_stat *suivant;
	char ad[13];
};
int recherche(char* adr , tab_stat* stat );
tab_stat* ajout (char* adr , tab_stat* stat );
int affiche(tab_stat* stat);
