#include <stdio.h>
#define MAXLINE 1000 

         /*Function given (getline1)*/
int getline1(char s[], int lim)  
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') s[i++] = c;
	if (c == '\n') s[i++] = c;
	s[i] = '\0';	
	return i;
}

         /*Function to strip away the '\n'*/
void stripper(char s[])         
{
    int i ;
    for( i = 0 ; s[i] != '\0' ; i++) {}
    s[(i-1)] = '\0' ;
}

         /*Function to get the string length*/
int my_strlen(char s[])         
{
    int i ;
    for( i = 0 ; s[i] != '\0' ; ++i) {}
    return i ;
}

         /*Function to catenate 2 strings into a new one*/
         /*It is of the format (string1 , string2 , string 3) which does string1 + string2 = string3 */
void my_strcat(char s[] , char t[] , char n[])
{
    int i ;
    int b ;
    for (i=0 ; s[i] != '\0';i++) {
        n[i] = s[i] ;
    }
    for (b=0 ; t[b] != '\0' ; b++ , i++) {
        n[i] = t[b] ;
    }
    n[i] = '\0' ;
}




int main () {
    char inString1[MAXLINE] ;
    char inString2[MAXLINE] ;
    char catstring[MAXLINE + MAXLINE] ;
    int i=0 ;


    printf("enter first line : ") ;
    int a = getline1(inString1,MAXLINE) ;

    printf("enter second line : ") ;
    int b = getline1(inString2,MAXLINE) ;


         /*problem 1 (stripping away the '\n' and returning the length of it)*/
    stripper(inString1) ;
    printf("the length of the first string after stripping away the '\\n' is : %d",my_strlen(inString1)) ;


         /*problem 2 (concatenating string 1 and string 2 and printing the concatenated string)*/
    my_strcat(inString1 , inString2 , catstring) ;
    printf("\nthe concatenated string is : ") ;
    for(i=0 ; catstring[i] != '\0' ; i++) {
    printf("%c",catstring[i]) ;
    }
    printf("the length of concatenated string is %d",my_strlen(catstring)) ;
 

return 0 ;}
