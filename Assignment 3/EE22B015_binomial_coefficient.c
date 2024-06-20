#include <stdio.h> 
#include <math.h> 

int n,k       ;    /*n,k are the binomial (n choose k)*/
int a,b,final ;    /*will be used later*/
int N = 1     ;    /*Will be used later for numerator*/
int D = 1     ;    /*Will be used later for denomenator*/

int main () {
  printf("nCk finder :\n") ;

  /*Getting the value of n*/
  printf("Enter n\n")      ;
  scanf("%d",&n)           ;

  /*a short code to auto change negative value to positive by alerting user*/
    if ( n < 0) {
      printf ("the entered value for n is negative \nauto assinging its absolute value for it \n" ) ;
      n =-n ;
} 

  /*Getting the value of k*/
  printf("Enter k\n")      ;
  scanf("%d",&k)           ;

  /*a short code to auto change negative value to positive by alerting user*/
    if ( k < 0) {
      printf ("the entered value for k is negative \nauto assinging its absolute value for it \n" ) ;
      k= -k ;
} 

  /*it is nonsense to have k>n hence this code to prevent such inputs*/
if (k > n) {printf("we cant choose %d objects from a sample space of %d  \ntry again",k,n);}

  /*a small optimisation to reduce the number of terms in numerator and denominator by using (n k) = (n n-k)*/
  /*this allows us to calc both 100c2 and 100c98*/
else {
  if ((n-k)>k) 
      a = (n-k)   ;
  else  a = k ; 

  /*instead of directly using the formula from the definiton we are canceling the common terms occuring in the numerator and the denominator by avoiding them in the multiplication*/ 
  /*N is for calculating the reduced numerator*/
  /*D is for calculating the reduced denominator*/
  /*reduced here means after canceling terms*/
for (b=n;b>a;b--){
      N = N*b ; 
      D = D * ((n+1)-b) ; 

}

  /*final result*/
final = N/D ;
printf ("(%d %d) or %dC%d = %d" ,n,k,n,k,final ) ;
}
}