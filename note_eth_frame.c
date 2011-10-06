#include “eth_lib.h”
struct eth_frame
{
	char[50];
	int nb;
	static struct eth_frame latrame
	{
		fscanf(stdio,”%s”,ch);
		fscanf(stdio,”%s”,ch);
		fscanf(stdio,”%s”,ch);
		fscanf(stdio,”%d”,&nb);
		get_buf((unsigned char*) &latrame,nb);
		return &latrame;
}
void main()
{
	struct eth_frame *trame;
	char* ad="000000000000"
	char* ad_source="000000000000";
	char* ad_dest="000000000000";
}
