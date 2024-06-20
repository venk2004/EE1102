#include <stdio.h>
#include<stdlib.h>


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
        else if ((*(ptr+i) != '\n')) returnstruct.splchars++ ;
        else ;
}
return returnstruct ;
}


int main( int argc, char *argv[] )  {

  int current_length = 0 ;  //length of string present in the txt file
  char c                 ;  //used for fgetc
  int i                  ;  //counter
  char *linebuffer       ;  //Storing txt text in a local string pointer
  int spacecounter = 0   ;  //countunging initial space counts


/*Printing out appropriate comments for each cases*/
   if( argc == 1 ) {
      printf("This program name is %s\nPlease enter the missing 2 arguements which should conatiain input and output file\n", argv[0]);
      return 1;
   }
   else if( argc == 2 ) {
      printf("This program name is %s\ninput filename : %s\nthe 3rd arguement is missing please fill it up with output file\n",argv[0],argv[1]);
      return 1 ;
   }
   else {
      printf("This program name is %s\ninput filename :%s\noutput filename :%s\n",argv[0],argv[1],argv[2]);
   }

/*opening file to get its length and showing a error if the file dosent exist*/
  FILE *fpin;
  fpin = fopen(argv[1],"r");
  if (fpin == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

/*getting the string length*/
  while ((c = fgetc(fpin)) != EOF) {
     current_length++;
  }
  linebuffer = (char*)malloc((1+current_length)*(sizeof(char))) ; //allocating the required length to the string pointer
  fclose (fpin) ;

/*opening again to copy it*/
  fpin = fopen(argv[1],"r");
  if (fpin == NULL) {            
    printf("Error opening file.\n"); 
    return 1;
  }
  for (i=0;(c = fgetc(fpin)) != EOF;i++) {
    linebuffer[i] = c ; 
    }
    linebuffer[i] = '\0' ;
    --i;

/*countung inital spaces*/
  for ( i=0,spacecounter=0 ; (linebuffer[i] == ' ') ; i++) {
    spacecounter++ ;
    if (linebuffer[i+1] != ' ') break; 
  }

/*Previous assignment function used*/
  string_data filedata = charTypeCounter(linebuffer) ; 

/*opening output file in a write mode to print the result*/
  FILE *fpout;
  fpout = fopen(argv[2],"w");
  if (fpout == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  if (current_length != 0){
   fprintf(fpout,"1) Vowels :%d\n2) Consonants:%d\n3) Special characters:%d\n4) Numbers :%d\n", filedata.vowels,filedata.consonants,(filedata.splchars-spacecounter),filedata.numbers);
  }
  else {
    fprintf(fpout,"There is no text to analyse in the input text file" ) ;
   printf("\nPlease give a text file with a string\n") ;
  }

  free(linebuffer) ;
  fclose (fpout) ;

return 0 ;
}