#include <stdio.h>

int main () {
    int listOfNumbers[] = {6,9,4,2,0,6,9} ; // Declare and initialize an array of integers
    int *ip  ;                              // Declare a pointer to an integer 
    ip = &listOfNumbers ;                   // Set the pointer to the address of the first element in the array
    int i ;                                 // Counter for loop

    printf("Value at location pointed to by the ptr and the following locations of it is :\n") ;
         for (i=0;i<7;i++) {
             printf("%d is the integar present at the address %p and the location of the pointer is at %p \n",*ip++,ip,&ip) ;         //Print the value stored at the current location pointed to by the pointer also the addresses
    }
}