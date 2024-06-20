#include <stdio.h> 
 int main () { 
   char * name1 = "Tom " ;  /* Declaring student names ,eg Tom , Sam , Ram */  
   char * name2 = "Sam " ;
   char * name3 = "Ram " ;
   int student1Course1Score , student1Course2Score , student1Course3Score , student2Course1Score , student2Course2Score , student2Course3Score ,student3Course1Score , student3Course2Score , student3Course3Score ,
   student1Total ,student2Total , student3Total ;
   student1Course1Score = 80 ; /*declaring students scores*/
   student1Course2Score = 60 ;
   student1Course3Score = 70 ; 
   student2Course1Score = 80 ;
   student2Course2Score = 70 ;
   student2Course3Score = 60 ;
   student3Course1Score = 80 ;
   student3Course2Score = 75 ;
   student3Course3Score = 65 ;
   student1Total = student1Course1Score + student1Course2Score + student1Course3Score ; /*Totaling the students scores*/
   student2Total = student2Course1Score + student2Course2Score + student2Course3Score ;
   student3Total = student3Course1Score + student3Course2Score + student3Course3Score ; 
   
   printf ( "===================\n %s  \n===================\ncourse 1 :   %d\ncourse 2 :   %d\ncourse 3 :   %d\ntotal    :  %d\n===================\n\n\n",name1,student1Course1Score,student1Course2Score,student1Course3Score,student1Total ) ; /*Printing the data in the prescribed format*/
   printf ( "===================\n %s  \n===================\ncourse 1 :   %d\ncourse 2 :   %d\ncourse 3 :   %d\ntotal    :  %d\n===================\n\n\n",name2,student2Course1Score,student2Course2Score,student2Course3Score,student2Total ) ;
   printf ( "===================\n %s  \n===================\ncourse 1 :   %d\ncourse 2 :   %d\ncourse 3 :   %d\ntotal    :  %d\n===================\n\n\n",name3,student3Course1Score,student3Course2Score,student3Course3Score,student3Total ) ;
   return 0 ;
   }
   
