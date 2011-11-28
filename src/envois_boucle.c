#include <stdlib.h>
#include <stdio.h>
#include "envois_trame.c"
int main(int charc, char * argv)
{
	int i=0;
	for(i=0; i<100; i++)
	{
		sleep(1);
		printf("coucou %d\n",i);
		envois_trame("e0:cb:4e:2f:fc:98","ff:ff:ff:ff:ff:ff","coucou ta mere");
	}
	return 0;
}
