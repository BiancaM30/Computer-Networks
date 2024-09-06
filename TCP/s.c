#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main(int argc, char *argv[] ){
struct sockaddr_in server, client;
int c, l;
int s;
s = socket(AF_INET, SOCK_STREAM, 0);
if (s < 0) {
printf("Eroare la crearea socketului server\n");
return 1;
}
 memset(&server, 0, sizeof(server));
server.sin_port = htons(atoi(argv[1]));
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
 if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
printf("Eroare la bind\n");
return 1;
}
 listen(s, 5);
 l = sizeof(client);
 memset(&client, 0, sizeof(client));
 while (1) {
	char sir[100];
	bzero(sir, 100);
	char ch;
	c = accept(s, (struct sockaddr *) &client, &l);
	bzero(sir, 100);
	printf("S-a conectat un client.\n");
	uint16_t len=0;
	uint16_t i;
	recv(c, &len, sizeof(uint16_t), MSG_WAITALL);
	len=ntohs(len);
	printf("Am primit len=%hu\n",len);
	for(i=0; i<len; i++)
		recv(c, &sir[i], sizeof(char), MSG_WAITALL);
	recv(c,&ch,sizeof(ch),MSG_WAITALL);
	uint16_t aux;
	
	printf("Len: %d\n", len);
	for(i=0;i<len;i++)
	if(sir[i]==ch)
	{
	printf("Pozitia lui %c este %d\n", sir[i], i);
	aux=htons(i);
	send(c, &aux, sizeof(aux), 0);
	}
	i=htons(65000);
	send(c, &i, sizeof(i), 0);
	close(c);
}
return (0);
}