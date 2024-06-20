#include <stdio.h> 

int main () {
    printf("1+ (1/2) + (1/3) + ... + (1/n) Calculator \n") ;

    float sum=0 ; 
    int a ;
    float b ;

    printf("Enter an integer:\n") ;
    scanf("%d",&a) ;

/*a short code to auto change negative value to positive by alerting user*/
      if ( a < 0) {
      printf ("the entered integar is negative \nauto assinging its absolute value for it \n" ) ;
      a =-a ;
}

/*printing appropriate statements till 1 + 1/2 + 1/3 */
if (a==0) {
    printf ("sorry 1/0 is not defined\ntry again") ;
    }
else if (a==1) {
    printf ("1 = 1") ;
    }
else if (a==2) {
    printf("1 + 1/2 = 1.5");
    }
else if (a==3) {
     sum  = ( 1 + (1.0/2.0) + (1.0/3.0)) ;
    printf("1 + 1/2 + 1/3 = %f",sum);
    }
/*single loop for the larger cases*/
else {
    for (b=1 ; b<=a ; b++) { 
        sum += (1/(b)) ;
    }
    printf ("1/1 + 1/2 + 1/3 + ..... + 1/%d = %f",a,sum) ;
} }
