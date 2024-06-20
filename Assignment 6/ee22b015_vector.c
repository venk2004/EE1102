#include <stdio.h> 
#include <math.h>  //Used only to find length of the vector 

/*Function to collect user input*/
void inMatrix(double s[3][3]) 
{
     printf("Enter First Vector : \n")  ;
     scanf("%lf %lf %lf",&s[0][0], &s[1][0], &s[2][0]) ;
     printf("Enter Second Vector : \n") ;
     scanf("%lf %lf %lf",&s[0][1] ,&s[1][1] ,&s[2][1]) ;
     printf("Enter Third Vector : \n")  ;
     scanf("%lf %lf %lf",&s[0][2] ,&s[1][2] ,&s[2][2]) ;
}


/*Function to display menu*/
double menu () 
{
int a ;
     printf("\n----------------------------------------------------------------------------------------------------------\n") ;
     printf("\nPlease enter the specified number shown below to perform the specified action :\n\n") ;
     printf("1 to Find length of a vector \n") ;
     printf("2 to Find unit vector of the given vector\n") ;
     printf("3 to Find dot product of 2 of the given vectors \n") ;  
     printf("4 to Find cross product of 2 of the given vectors \n") ;
     printf("5 to Find the volume subtended by the three vectors \n") ; 
     printf("0 to terminate the program \n") ;
     scanf("%d",&a) ;
     return a ;
}


/*Function to calculate length of a vector*/
double vectorLength (double s[3][3] ,int a) 
{
    return (sqrt((( s[0][a-1] )*( s[0][a-1] )) + (( s[1][a-1] )*( s[1][a-1] )) + (( s[2][a-1] )*( s[2][a-1] )))) ;
}


/*Function to return the unit vector in a matrix*/
int unitVector (double s[3][3] , double t[3],int a)
{
    int i= 0 ;
         if (vectorLength(s,a) != 0) {
             for (i=0;i<3;i++) {
                 t[i] = (s[i][a-1])/(vectorLength(s, a)) ; //also uses vector length function
            }
             return 1 ;
        }
        else { 
             printf("Since its a null vector there is no point in speaking of unit vector") ;
             return 0 ;
        }
}


/*Returns dot products of 2 user specified vectors*/
double dotProduct (double s[3][3] ,int x,int y)
{
    int a,b,i ;
    double dot ;

         for(i=0 ,dot=0 ;i<3 ;i++) {
         dot += (s[i][x-1])*(s[i][y-1]) ;
        }
        return dot ;
}


/*Returns the cross product in an 1d array*/
void crossProduct (double s[3][3] , double t[3] ,int x , int y)
{
     t[0] = ((s[1][x-1])*(s[2][y-1]) - (s[2][x-1])*(s[1][y-1])) ;
     t[1] = ((s[2][x-1])*(s[0][y-1]) - (s[0][x-1])*(s[2][y-1])) ;
     t[2] = ((s[0][x-1])*(s[1][y-1]) - (s[1][x-1])*(s[0][y-1])) ;
}


/*Simple one line command using box product to find volume*/
double boxProduct (double s[3][3])
{
  double box = 0;
  box = (s[0][0])*((s[1][1])*(s[2][2]) - (s[2][1])*(s[1][2])) + (s[1][0])*((s[2][1])*(s[0][2]) - (s[0][1])*(s[2][2])) + (s[2][0])*((s[0][1])*(s[1][2]) - (s[1][1])*(s[0][2])) ;
  if (box<0) box *= -1 ;
  return box ;
}


/*Defined few universal variables outside main to help create a looped program*/
int collectMatrix = 0;
double Matrix[3][3] ;


int main () {

double returnVector [3] ;                    //array used to return vector output functions 
int i,j ;
double action  ;

    if(collectMatrix == 0)  {                //Initially to collect the vectors
     printf("Vector operator \n\n") ;
     inMatrix (Matrix) ;
     collectMatrix = 1 ;
    }
     action = menu() ;                       //initialises menu function

         if (action <0 && action >5) {       //Displays appropriate message for inappropriate input
             printf("\nInvalid request by user") ;
             main() ;
        }
         else if (action == 0) {             //Termination code
             printf("\nProgram successfully terminated") ;
             printf("\n----------------------------------------------------------------------------------------------------------\n") ;
             return 0 ;
        }
         else if (action == 1) {             //Runs vector length function
             printf ("Please specify which Vector's length you want to find : \n") ;
             scanf ("%d",&i) ;
             if (0<i && i<4 ) {
             printf("The length of vector is : %lf",vectorLength(Matrix,i)) ;
             main() ;
             }
             else {
                printf("\nInvalid Request\n") ;
                main() ;
             }
        }     
         else if(action == 2) {              //For unit vector
             printf ("Please specify which Vector's unit vector you want to find : \n") ;
             scanf ("%d",&i) ;
             if (0<i && i<4 ) {
                 j = unitVector (Matrix,returnVector,i) ;
                 if (j==1) {
                     printf("%lf i , %lf j , %lf k",returnVector[0],returnVector[1],returnVector[2]) ;
                     main() ;
                    }
                 else main() ;
            }
                         
             else {
                printf("\nInvalid Request\n") ;
                main() ;
            }
         }   
         else if (action == 3) {             //For dot product
             printf("Specify the two vectors :\n") ;
             scanf("%d %d",&i,&j) ;
             if (0<i && i<4 && 0<j && j<4) {
                 printf("The dot product is %lf",dotProduct(Matrix,i,j)) ;
                 main() ;
            }
             else {
                printf("\nInvalid Request\n") ;
                main() ;
            }
         }
         else if (action == 4) {             //For crossproduct
             printf("Specify the two vectors in order :\n") ;
             scanf("%d %d",&i,&j) ;
             if (0<i && i<4 && 0<j && j<4) {
                 crossProduct (Matrix,returnVector,i,j) ;
                 printf("%lf i , %lf j , %lf k",returnVector[0],returnVector[1],returnVector[2]) ;   
                 main() ;
            }
             else {
                 printf("\nInvalid Request\n") ;
                 main() ;
             }
         }
         else if (action == 5) {             //For volume
             printf("\nVolume of the corresponding parallelepiped from these vectors is : %lf\n ",(boxProduct(Matrix))) ;
             main() ;
         }
         else {
             printf("\nInvalid request by user") ;
             action = 10 ;
             menu();
         }
 }






