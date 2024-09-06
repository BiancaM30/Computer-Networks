#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>


#define BUFLEN 512

int
main (int argc, char **argv)
{

  int s;
  struct sockaddr_in server, client;
  socklen_t l;
  uint16_t k;

  s = socket (AF_INET, SOCK_DGRAM, 0);
  if (s < 0)
    {
      printf ("Eroare la crearea socketului server\n");
      return 1;
    }

  memset (&server, 0, sizeof (server));
  server.sin_port = htons (atoi(argv[1]));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;

  if (bind (s, (struct sockaddr *) &server, sizeof (server)) < 0)
    {
      printf ("Eroare la bind\n");
      return 1;
    }
 
  l = sizeof(client);    
  memset(&client, 0, sizeof(client));
  
  recvfrom(s, &k, sizeof(k), MSG_WAITALL, (struct sockaddr *) &client, &l);
  
  if (fork())
  {
    while (1)
    {
      char msg[BUFLEN];
      recvfrom(s, msg, BUFLEN * sizeof(char), MSG_WAITALL, (struct sockaddr *) &client, &l);
      
      printf("\n%s: %s \n",inet_ntoa(client.sin_addr), msg);
      
      memset (msg, 0, BUFLEN);
      
    }
    exit(0);
  }
  else
  {
    while (1)
    {
      char smsg[BUFLEN];
      scanf ("%s", smsg);
      
      sendto(s, smsg, strlen(smsg) * sizeof(char), MSG_WAITALL, (struct sockaddr *) &client, l);
      
      memset (smsg, 0, BUFLEN);
    
    }
  }
    
  

  return 0;
}
