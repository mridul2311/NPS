#include<stdio.h>

unsigned fields[10];

unsigned short checksum()
{
    int i;
    int sum = 0, checksum = 0;
    printf("Enter the IP header information in 16 bit words\n"); // (i.e. 16 1s and 0s, or 4 hexadecimal digits)

    for(i = 0; i < 5; i++)
    {
        printf("Field %d\n", i+1);
        scanf("%x", &fields[i]);
        //printf("%x\n", fields[i]);

        sum = sum + (unsigned short)fields[i];

        while (sum >> 16)		//If there is a carry, wrap around
        sum = (sum & 0xFFFF) + (sum >> 16);

    }
    checksum = ~sum;
    return (unsigned short)checksum;
}

int main()
{
    unsigned short result1, result2;

    result1 = checksum();
    printf("\nComputed checksum at sender %x\n", result1);

    result2 = checksum();
    printf("\nComputed checksum at reciever %x\n", result2);

    if (result1 == result2) 
    {
        printf("NO ERROR\n");
    }
    else
    {
        printf("ERROR detected\n");
    }
}