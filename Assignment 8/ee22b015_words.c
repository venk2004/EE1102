#include <stdio.h>
#include <string.h>     //Used only to find the length of the strings
#include <stdlib.h>     //malloc(),free()

#define MAXLENGTH 1000

/*Converts all alphabets to lowercase and then proceed to compare string*/
int tolowerdup(int c) {               
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

/*Function which compares strings case insensitively*/
int compare_strings(const char* s1, const char* s2) {
    int i;
    if (strlen(s2) > strlen(s1)) {
        return -1;
    }
    for (i = 0; ((tolowerdup(s1[i]) == tolowerdup(s2[i]))||(s2[i]=='\0')); i++) {
        if (s2[i] == '\0') {
            return 0;
        }
    }
    return -1;
}


int main (){

    int numberOfStrings           ;           
    int i,j                       ;    //Counters            
    char dummy_string[MAXLENGTH]  ;    
    int check                     ;    //Used for detecting invalid inputs 


    printf("Please type the value n: \n")                ;
    check=scanf("%d", &numberOfStrings)                  ; // return the number of successful input
    if((check!=1)||(numberOfStrings<=0)) {
        printf("Invalid input. Only positive integer allowed\n")  ; // check will be equal to 1 if and only if it is an integar
        return 0;
    }

    char *ptr_array[numberOfStrings]  ;                    // This is allowed by the present C compilers
    printf("Enter the strings :\n")   ;

    /*String storing part*/
    for(i=0;i<numberOfStrings;i++)  {
   	     scanf("%s",&dummy_string)                                                 ;
         dummy_string[(strlen(dummy_string))] = '\0'                               ;
         ptr_array[i] = (char*)malloc((1 + strlen(dummy_string)) * (sizeof(char))) ;  // Dynamically allocate memory of size dummy_string for  ptr_array[i]

         for (j=0 ;j<=strlen(dummy_string);j++) {                                     // Copy the string from dummy_string to ptr_array[i];
             *ptr_array[i] = dummy_string[j]                                       ;
             ptr_array[i]++                                                        ;
         }
         ptr_array[i] -= strlen(dummy_string)+1                                    ;  // returns the pointer to its orginal position
    }

    /*Prints dictionary*/
    printf("============\nThe dictionary contains :\n") ;                                                       ;

    for (i=0;i<numberOfStrings;i++) {
        printf("%d)%s\n",i+1,ptr_array[i]) ;
    }

    /*Clears the buffer '\n' left in the scanf earlier used*/ 
    int c;
    while((c = getchar()) != '\n' && c != EOF)                                        ;

    printf("Enter a string to compare and check : ")                                  ;
    scanf("%s",&dummy_string)                                                         ;
    printf("\n\nStrings starting with letter '%s' are given below :\n",dummy_string)  ;

    /*Compares*/
    for ( i=0 ,j=0 ; i<numberOfStrings ;i++ )  {
         if (compare_strings(ptr_array[i] , dummy_string) == 0 ){
             printf("%d)%s\n",i+1,ptr_array[i]) ;
             j = 1                              ;
         }   
     }

    if (j==0) printf("No string begins with %s",dummy_string) ; 

    /*free the allocated memory*/
    for (int i = 0; i < numberOfStrings; i++) {
        free(ptr_array[i]); 
    }
    
    return 0 ;
}