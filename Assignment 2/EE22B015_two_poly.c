#include <stdio.h>
#include <math.h> 
int main () {

float a,b,c;        /*a,b,c for the 1st quadratic*/
float p,q,r;        /*p,q,r for the 2nd quadratic*/
float A,B,C,D,E ;   /*for the final biquadratic*/

/*prescribing the quadratic equation format initially so the user knows which coefficients to enter*/
    printf("\nEnter the coefficients of the first quadratic equation in the format given below \n (a)(x^2) + (b)(x) + (c) \n") ;
    printf("Enter a : \n") ;
    scanf("%f",&a) ;
    printf("Enter b : \n") ;
    scanf("%f",&b) ;
    printf("Enter c : \n") ;
    scanf("%f",&c) ;
     printf("\n") ;

/*prescribing the quadratic equation format initially so the user knows which coefficients to enter*/
    printf("Enter the coefficients of the second quadratic equation in the format given below \n (p)(x^2) + (q)(x) + (r) \n") ;
    printf("Enter p : \n") ;
    scanf("%f",&p) ;
    printf("Enter q : \n") ;
    scanf("%f",&q) ;
    printf("Enter r : \n") ;
    scanf("%f",&r) ; 
    printf("\n") ;

/*Printing out the initial quadratic equations for user satisfaction*/
    printf("The given polynomials are :\n ((%.2f)(x^2) + (%.2f)(x) + (%.2f)) & ((%.2f)(x^2) + (%.2f)(x) + (%.2f)) \n\n",a,b,c,p,q,r) ;


/*Defining the coefficients with appropriate calculations*/
    A = a*p ;             
    B = a*q + b*p ;
    C = a*r + p*c +b*q ;
    D = q*c + b*r ;
    E = c*r ; 

/*Printing out the result*/
    printf("The product of the polynomials is :\n (%.2f)(x^4) + (%.2f)(x^3) + (%.2f)(x^2) + (%.2f)(x) + (%.2f)\n",A,B,C,D,E) ;
    return 0;

}
    