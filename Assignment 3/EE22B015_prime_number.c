#include <stdio.h>
#include <math.h>

int main () { 

int a ;    /*User input number*/
int b =2;  /*Counter , starting from 2 as any integars when divided by 1 gives remainder as 0 which causes us problems*/
int c ;    /*sqrt of a*/
printf ("Prime checker \n" ) ;
printf("please enter the number for which you want to prime check\n") ; 
scanf ("%d",&a) ;

/*as prime is not defined for negative numbers, taking the absolute value for it after alerting the user*/
if ( a < 0) {
printf ("the entered value is negative \nauto assinging its absolute value for it \n" ) ;
      a =-a ;
}

c = sqrt(a) ; /*c will be a whole number not a fraction*/

/*for the cases prime or composite dosent make sense*/
if ((a==0)||(a==1)) {
   printf("the entered number is %d which is neither prime nor composite",a);
   }

/*Seperately written for 2 and 3 .*/
/*Including in loop will cause problems as 3%1 =0 , 2%1 = 0 and the program will consider it a non prime*/
if (a==2) {
   printf("the entered number is 2 which is the only even prime");
   }
if (a==3) {
   printf("the number is a prime");
   }

/*loop which tests remainder for the given number to be 0 or not when divided by numbers from 2 to c*/
/*c here is [sqrt(input)]*/
/*it is actually enough to check till c, which has a widely accepted proof in public forums as in why we can do that*/
else { 
   while (b <= c) {
     if (a % b == 0) {
        printf ("%d is NOT a prime ",a) ;
        break ;
     }
     else if (a % b != 0) {
        b++ ;
        } 
    if (b == c+1) {printf ("%d is a prime",a) ;
    break ;}
        }  
         }
}
         
     
     
