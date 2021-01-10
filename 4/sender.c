#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define HELLO_PORT 12345
#define HELLO_GROUP "225.0.0.37"
int main(int argc, char *argv[])
{
struct sockaddr_in addr;
int fd, cnt;
char *message;
struct ip_mreq mreq;
if(argc==1)
{message="RVCE_CSE";
}
else
{message=argv[1];}
//printf("%s\n", message);
/* create what looks like an ordinary UDP socket */
if ((fd=socket(AF_INET,SOCK_DGRAM,0)) < 0) {
perror("Opening datagram socket error");
exit(1);
}
else{
printf("Opening the datagram socket...OK...\n");}
/* set up destination address */
memset(&addr,0,sizeof(addr));
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=inet_addr(HELLO_GROUP);
addr.sin_port=htons(HELLO_PORT);

/* now just sendto() our destination! */
while (1) {
if (sendto(fd,message,sizeof(message),0,(struct sockaddr *)
&addr,
sizeof(addr)) < 0) {
perror("Sending datagram message error");
exit(1);
}
else
            {printf("Sending datagram message...OK\n");}//printf("%s\n", message);}
sleep(2);
}
return 0;
}

