#include <stdio.h> 
#include <math.h>           /*Including math.h to use sqrt funtion*/

float a,b,c,D,xr,yr,xi,yi ; /*xr,xi are for 1st root & yr,yi for the 2nd root*/

int main () { 
    printf ("ROOT FINDER 1.0\n") ;

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

  if ((a == 0)&&(b != 0) ) {                   /*For the case where the given coefficients result in a linear equation*/
    printf("This is a linear equation with the singly root = %.2f ",((-c)/b)) ;  
}

  else if ( ((a==0) && (b==0))&&(c!= 0) ) {    /*for meaning entries from users*/                 
    printf ("the entered coefficients are meaningless") ;  
}

  else if ( ((a==0) && (b==0))&&(c == 0) ) {   /*For the identity case*/
    printf ("The entered quadratic equation becomes an identity (a, b, c = 0)\ni.e having more than two roots or solutions either real or complex.") ;
}

/*for the actuall quadratic cases*/

  else if (a != 0) { 

        if (D>0)  {  /*Real distinct roots cases*/
          printf("The roots are real and distinct\n\n") ;
          xr = ((-b) + sqrt(D))/(2*a) ;
          yr = ((-b) - sqrt(D))/(2*a) ;
          printf("the roots are :\n%.2f , %.2f",xr,yr) ; 
         }

        if (D==0) {  /*Real equal roots cases*/
          printf("The roots are real and equal\n\n") ;
          xr = ((-b) + sqrt(D))/(2*a) ;
          yr = ((-b) - sqrt(D))/(2*a) ;
          printf("the roots are :\n%.2f , %.2f",xr,yr) ; 
        }

        if (D<0) {  /*imaginery roots cases*/
          printf("The roots are conjugated imaginery numbers\n\n") ;   
          xr = (-b) /(2*a) ;
          yr = (-b) /(2*a) ;
          xi = (sqrt(-D))/(2*a) ;
          yi = (-sqrt(-D))/(2*a) ;
          printf("the roots are :\n%.2f + i(%.2f) , %.2f + i(%.2f)",xr,xi,yr,yi) ; 
        }

  }  

}