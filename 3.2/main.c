#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <arpa/inet.h>

void IP4generator(int n)
{
    srand(time(NULL));
    FILE *randomIP;
    randomIP = fopen("randomIP.txt", "w"); 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fprintf(randomIP, "%d.", rand() % 255);
        }
        fprintf(randomIP, "%d\n", rand() % 255); 
    }
}

void CheckRandomIPinSubnet(int n, in_addr_t mask, in_addr_t subnet)
{
    FILE *randomIP;
    randomIP = fopen("randomIP.txt", "r"); 

    char stringBuf[15];
    in_addr_t ipBuf;

    int ipCount = 0;
    for (int i = 0; i < n; i++)
    {
        fgets(stringBuf, sizeof(stringBuf), randomIP);
        ipBuf = inet_addr(stringBuf);
        if((ipBuf & mask) == subnet)
        {
            printf("%Xx0 in \"own\" subnet\n", ipBuf);
            ipCount++;
        }
    }

    double prcoent = (double)ipCount/(double)n * 100;
    printf("Packages to the nodes of the \"own\" network\n\tTotal - %d, procent - %.1lf%%\n", ipCount, prcoent);
    printf("Packages to the nodes of the another network\n\tTotal - %d, procent - %.1lf%%\n", n-ipCount, 100-prcoent);
}

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Incorrect number of arguments\n");
        exit(1);
    }

    in_addr_t gateway_ipv4 = inet_addr(argv[1]);
    printf("Gateway: %Xx0\n", gateway_ipv4);

    in_addr_t mask_ipv4 = inet_addr(argv[2]);
    printf("Mask: %Xx0\n", mask_ipv4);

    in_addr_t subnet_ipv4 = gateway_ipv4&mask_ipv4;
    printf("Subnet: %Xx0\n", subnet_ipv4);

    int n = atoi(argv[3]);

    IP4generator(n);

    CheckRandomIPinSubnet(n, mask_ipv4, subnet_ipv4);
}