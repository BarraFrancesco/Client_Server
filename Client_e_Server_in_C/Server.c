#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BLEN 1024
#define CODA 3
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {     
	int sd,sda,len;              //Socket descriptor/accept,length.
	struct sockaddr_in saddr;   //indirizzo del server.
	struct sockaddr caddr;     //indirizzo del client.
	char buff[BLEN]={'\0'};
	
	if ((sd=socket(AF_INET,SOCK_STREAM,0))<0){               //indirizzi IP con TCP
		printf("ERROR:il socket non  creato.");
		exit(1);
	}   
	saddr.sin_family=AF_INET;    //domini IP 
	saddr.sin_port=5517;        //porta di accesso 
	saddr.sin_addr.s_addr=INADDR_ANY;   //qualsiasi ind. IP cliet accettato
	
	if (bind(sd, (struct sockaddr *)&saddr, sizeof(saddr))<0){    //descrittore socket 
		printf("ERROR:non recepito l'indirizzo del client.");
		exit(1);
	}
	printf("_:Il server ti dà il benvenuto:_");
	
	listen(sd,CODA);   //massimo di connessioni in sospeso 
	printef("\numero di connessioni permesse sono %d\n.",CODA);
	
	while(1)
	{
		while((sda=accept(sd, &caddr, &len)) <0); //ind. del client accettato e copiato in memoria
		if(!forck())   
	}
	
	do{
		read(sda,buff,BLEN);
		printf("Client:s%\n",buff);
	}while(strcmp(buff, "quit")){
		
	
	printf("Input terminato\n");
	write(sda, "Fatto",10);
	close(sda);
	exit(0);
}
close(sda);
	   
	return 0;
}
