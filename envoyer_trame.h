struct tab_stat
{
	tab_stat *suivant;
	char ad[13];
};
int recherche(char* adr , tab_stat* stat ){
//printf("recherche de %s dans la table..........................",adr);
do
{
	if (strcmp(adr,stat->ad)==0)
	{
		//printf("trouve !\n");
		return 1;
	}
	else {
		stat=stat->suivant;
	}
}while (stat!= NULL);
//printf("non trouvé !\n");
return 0;
}
