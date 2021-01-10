/* This program calculates the key for two persons 
using the Diffie-Hellman Key exchange algorithm */

#include<stdio.h>
#include<math.h>
 
// Power function to return value of a ^ b mod P
int power(int a, int b, int P)
{ 
    if (b == 1)
        return a % P;
 
    else
    {
	float x = pow(a,b);
	return ((int)x % P);
    }
}
 
//Driver program
int main()
{
    int P, G, xa, xb, ya, yb, ka, kb; 
     
    // Both the people will agree upon the 
        // public keys G and P 
    P = 23; // A prime number P is taken
    printf("Enter value of P: ");
    scanf("%d",&P); 
 
    G = 9; // A primitive root for P, G is taken
    printf("Enter value of G: ");
    scanf("%d",&G); 
 
    // Alice will choose the private key xa, Bob will choose the private key xb 
    xa = 4; // xa is the chosen private key
    printf("Enter the private key for Alice: ");
    scanf("%d", &xa); 
    xb = 3; // xb is the chosen private key
    printf("Enter the private key for Bob: ");
    scanf("%d", &xb);
    printf("The private key xa for Alice: %d\n", xa); 
    printf("The private key xb for Bob: %d\n\n", xb);
    ya = power(G, xa, P); // gets the generated key
    yb = power(G, xb, P); // gets the generated key

    printf("The public key ya for Alice: %d\n", ya);
    printf("The public key yb for Bob: %d\n", yb);
 
    // Generating the secret key after the exchange of keys
    ka = power(yb, xa, P); // Secret key for Alice
    kb = power(ya, xb, P); // Secret key for Bob
     
    printf("Secret key for Alice is: %d\n", ka);
    printf("Secret Key for Bob is: %d\n", kb);
     
    return 0;
}
