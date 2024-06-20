#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 100

/* Struct to store the count of vowels, consonants, numbers and special characters */
typedef struct
{
    int vowels;
    int numbers;
    int consonants;
    int splchars ;
} string_data;

/* Function to convert upper case characters to lower case */
int tolowerdup(int c) {               
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

/* Function to clear the input buffer */
void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* Function to get the length of a string */
int strlen(char *s)
{
  int n = 0;
  while (*s != '\0') {
    n++;
    s++;
  }
  return n;
}

/* Function to count the number of vowels, consonants, numbers, and special characters in a string */
string_data charTypeCounter(char* ptr) 
{
    int i ;
    string_data returnstruct ;
    returnstruct.consonants = 0 ;
    returnstruct.vowels = 0     ;
    returnstruct.numbers = 0    ;
    returnstruct.splchars = 0   ;
    for (i=0 ; i<strlen(ptr);i++) {
        if ((tolowerdup(*(ptr+i)) >= 97) && (tolowerdup(*(ptr+i)) <= 122)) {
            if ((tolowerdup(*(ptr+i)) == 97)||(tolowerdup(*(ptr+i)) == 101)||(tolowerdup(*(ptr+i)) == 105)||(tolowerdup(*(ptr+i)) == 111)||(tolowerdup(*(ptr+i)) == 117)) returnstruct.vowels++ ;
            else returnstruct.consonants++ ;
        }
        else if ((*(ptr+i) >= 48) && (*(ptr+i) <= 57)) {
            returnstruct.numbers++ ;
        }
        else returnstruct.splchars++ ;
}
return returnstruct ;
}

/* Function to display a histogram based on the input string */
void histmake(string_data histdata)
{
    int i ;
    printf("The histogram is as follows \nVowels             :") ;
    for (i=0 ; i < histdata.vowels;i++) printf("*") ;
    printf("\nConsonants         :") ;
    for (i=0 ; i < histdata.consonants ;i++) printf("*") ;
    printf("\nSpecial characters :") ;
    for (i=0 ; i < histdata.splchars ;i++) printf("*") ;
    printf("\nNumbers            :") ;
    for (i=0 ; i < histdata.numbers ; i++) printf("*") ;
    printf("\n") ;
}

int main () {

    char *instringptr = (char*)malloc((1 + MAXLENGTH) * (sizeof(char))) ; //allocate sapce to the string

    printf("Enter the input String :") ;                                 
    scanf("%[^\n]s",instringptr) ;                                        //Getting input string which stops only when it encounters '\n'
    clear_stdin() ;

    string_data histogramData = charTypeCounter(instringptr) ;            //Calling the data maker function
    histmake(histogramData) ;                                             //Histogram printing function
    free (instringptr) ;                                                  //Freeing the allocated space
    return 0 ;

}