//Fonction lire_trame qui permet de lire l'ensemble de la trame et retourne cette dernière.
struct eth_frame* lire_trame();

//Cherche un caractère dans une chaine
int est_dans(char * chaine, char car);

//Fonction de conversion d'une adress de type "00123f3c5e6e" en "00:12:3f:3c:5e:6e"
void convaddr(char* adresse, char* adr_dest);

//Envois une trame sur le réseau, de type 9000
void envois_trame(char *source, char *dest, char *message);
