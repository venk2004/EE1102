#include <stdio.h> 
#include <math.h>             /*Including math.h to use sqrt funtion*/

float a,b,c,D,xr,yr,xi,yi ;   /*xr,xi are for 1st root & yr,yi for the 2nd root*/
int status ;                  /*assigning integral values to status for switch cases*/

int main () { 
    printf ("ROOT FINDER 2.0\n") ;

/*prescribing the quadratic equation format initially so the user knows which coefficients to enter*/

    printf("\nEnter the coefficients of the quadratic equation in the format given below \n (a)(x^2) + (b)(x) + (c) \n") ;
    printf("Enter a : \n") ;
    scanf("%f",&a) ;
    printf("Enter b : \n") ;
    scanf("%f",&b) ;
    printf("Enter c : \n") ;
    scanf("%f",&c) ;
    printf("\n") ;

    D = b*b - 4*a*c ; /*Defining Discriminant*/

    if ((a == 0)&&(b != 0) ) status = 4 ;                 /*For the case where the given coefficients result in a linear equation*/
    else if ( ((a==0) && (b==0))&&(c!= 0) ) status = 3 ;  /*for meaning entries from users*/
    else if ( ((a==0) && (b==0))&&(c == 0) ) status = 2 ; /*For the identity case*/

    else if (a != 0) {       /*for the actuall quadratic cases*/
    if(D>0) status = 1 ;     /*Real distinct roots cases*/
    if(D==0) status = 0 ;    /*Real equal roots cases*/
    if(D<0) status = -1 ;    /*Imaginery roots cases*/
    }
    switch (status) {
        case 4 :   /*For the case where the given coefficients result in a linear equation*/
        printf("This is a linear equation with the singly root = %.2f ",((-c)/b)) ;
        break ;

        case 3 :   /*for meaning entries from users*/
        printf ("the entered coefficients are meaningless") ;
        break;

        case 2 :   /*For the identity case*/
        printf ("The entered quadratic equation becomes an identity (a, b, c = 0)\ni.e having more than two roots or solutions either real or complex.") ;
        break;

        case 1 :   /*Real distinct roots cases*/
        printf("The roots are real and distinct\n\n") ;
        xr = ((-b) + sqrt(D))/(2*a) ;
        yr = ((-b) - sqrt(D))/(2*a) ;
        printf("the roots are :\n%.2f , %.2f",xr,yr) ; 
        break;

        case 0 :   /*Real equal roots cases*/
        printf("The roots are real and equal\n\n") ;
        xr = ((-b) + sqrt(D))/(2*a) ;
        yr = ((-b) - sqrt(D))/(2*a) ;
        printf("the roots are :\n%.2f , %.2f",xr,yr) ;
        break;
        
        case -1 :   /*imaginery roots cases*/
        printf("The roots are conjugated imaginery numbers\n\n") ;
        xr = (-b) /(2*a) ;
        yr = (-b) /(2*a) ;
        xi = (sqrt(-D))/(2*a) ;
        yi = (-sqrt(-D))/(2*a) ;
        printf("the roots are :\n%.2f + i(%.2f) , %.2f + i(%.2f)",xr,xi,yr,yi) ; 
        break;
    }
}