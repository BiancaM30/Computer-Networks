#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main(int argc, char *argv[] ) {
int c;
struct sockaddr_in server;
uint16_t poz, len;
char buffer[100];
char caracter;

 c = socket(AF_INET, SOCK_STREAM, 0);
if (c < 0) {
printf("Eroare la crearea socketului client\n");
return 1;
}

 memset(&server, 0, sizeof(server));
server.sin_port = htons(atoi(argv[1]));
server.sin_family = AF_INET;
server.sin_addr.s_addr = inet_addr(argv[2]);

 if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
printf("Eroare la conectarea la server\n");
return 1;
}

 printf("buffer = \n");
fgets(buffer, sizeof(buffer), stdin);
printf("%s\n", buffer);
len = strlen(buffer);
printf("%d\n", len);
len=htons(len);
send(c, &len, sizeof(len), 0);
len=ntohs(len);
int i = 0;
for(i=0; i<len; i++){
	printf("Trimit %c\n",buffer[i]);
	send(c, &buffer[i], sizeof(char), 0);
}

scanf("%s", &caracter);
send(c, &caracter, sizeof(caracter), 0);

 printf("Pozitiile sunt: \n");

 while(1){
recv(c, &poz, sizeof(poz), 0);
poz = ntohs(poz);
if(poz==65000)
break;
printf("%hu\n", poz);
}
close(c);
}