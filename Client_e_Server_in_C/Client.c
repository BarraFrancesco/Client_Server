#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BLEN 1024
#define CODA 3

int main(int argc, char *argv[]) {   
	int sd,len;
	struct sockaddr_in caddr;      //indirizzo del client
    struct hosten *hp;
    char buffer[BLEN];
    
    if((sd=socket(AF_INET, SOCK_STREAM,0))<0){
    	printf("ERROR:il socket non è stato creato\n");
    	exit(1);
	}
	caddr.sin_family =AF_INET; //domini IP 
	caddr.sin_port=5517;      //porta del server a cui connettersi
	
	hp=gethostbyname("local host"); //la funzione restituisce l'indirizzo IP del server
	
	bcopy(hp->h_addr, &caddr.sin_addr, hp->h_length);
	
	if(connect(sd, (struct soackaddr *)&caddr, sizeof(caddr))<0){
		printf("Errore nella connect\n");
		exit (1);
	}
	printf("Inserisci le stringe che vuoi inviare al server.\n(quit per terminare)\n");
	
	do{
		scanf("%s", buff);
		write(sd,buff,BLEN);
	}while (strcmp(buff,"quit"));

read (sd,buff,BLEN);
printf  ("Dal server:%s\n", buff);

close(sd);

exit(0);

return 0;
}
