#include <stdio.h>
#define MAXLENGTH 1000 /*Change to 12 for part 1 b subdivision*/

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


int main () {

int count =0 ;
int a =0;
char inString[MAXLENGTH]  ;


                                /*Gets the string from user*/
printf("Enter a line and press enter to proceed :\n") ;
int b = getline1(inString,MAXLENGTH) ;


                                /*Prints information about 4th and 12th letters for MACLENGTH 1000 case*/
if (MAXLENGTH == 1000 ) {       
if (b<=2) {
    printf("4th and 12th letters dosent exist\nthe input entered contains %d readable letters : ",(b-1));
}
else if (b==4){
    printf("4th letter is '\\n'\n12th letter dosent exist\nthe input entered contains %d readable letters : ",(b-1));
}
else if (b==3){
    printf("4th position is occupied by '\\0'\n12th letter dosent exist\nthe input entered contains %d readable letters : ",(b-1));
}
else if (b>5 && b<11){
    printf("4th letter is '%c'\n12th letter dosent exist\nthe input entered contains %d readable letters : ",inString[3],(b-1));
}
else if (b==12){
    printf("4th letter is %c\n12th letter '\\n'\nthe input entered contains %d readable letters : ",inString[3],(b-1));
}
else if (b==11){
    printf("4th letter is %c\n12th position is occupied by '\\0'\nthe input entered contains %d readable letters : ",inString[3],(b-1));
}
else{
    printf("%c is 4th letter\n%c is 12th letter\nthe input entered contains %d readable letters : ",inString[3],inString[11],(b-1)) ;
}
}

                                /*For MAXLENGTH 12 case*/
else if (MAXLENGTH == 12) {
    if (b<=3) {
    printf("4th and 12th letters dosent exist\nthe input entered contains %d readable letters : ",(b-1));
}
else if (b==4){
    printf("4th letter is '\\n'\n12th letter dosent exist\nthe input entered contains %d readable letters : ",(b-1));
}
else if (b==5){
    printf("4th position is occupied by '\\0'\n12th letter dosent exist\nthe input entered contains %d readable letters : ",(b-1));
}
else if (b>5 && b<=10){
    printf("4th letter is '%c'\n12th letter dosent exist\nthe input entered contains %d readable letters : ",inString[3],(b-1));
}
else if (b==11){
    printf("4th letter is %c\n12th letter '\\0'\nthe input entered contains %d readable letters : ",inString[3],(b));
    /*note b>11 is not possible as MAXLENGTH determines the maximum bound for b*/
}
}

else {
     printf("Define MAXLENGTH to be either 12 or 1000") ;
    return 0 ;
}


                                /*Prints the userin String*/
for(a = 0 ;inString[a] != '\0' ;a++) {
    printf("%c",inString[a]) ;
    count++ ;
}
printf("\nstring length is %d\n",count) ;

                                /*stripping away \n*/
if (inString[b-1] == '\n') inString[b-1] = '\0' ; 


                                /*Prints the stripped String*/
printf("\nprinting the stripped string and its length\n") ;
for(a = 0 ,count =0 ;inString[a] != '\0' ;a++) {
    printf("%c",inString[a]) ;
    count++ ;
}
printf(": string length is %d\n",count) ;
if (MAXLENGTH == 12 && b ==11) {
    printf("\nFor MAXLENGTH  = 12 case , 12th position will be occupied by \\0 if the user input contains more than or equal to 11 letters. \nso if user inputs 11 or more letters there is no \\n to strip hence the string length remains same") ;
}


return 0 ;}





