#include <stdio.h> 

// Function definition for getline1
int getline1(char *s, int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

// Function definition for strlen
int strlen(char *s)
{
  int n = 0;
  while (*s != '\0') {
    n++;
    s++;
  }
  return n;
}

void revstringdup (char * a)
{
    int i, j;
    char temp;
  
     // Swap characters from start and end of string
    for (i = 0, j = strlen(a) - 1; i < j; i++, j--) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    

  }



int main() {
  
  // Declare variables
  char inString[1000] ;
  char *input = &inString[0] ;
  int i = 0 ;
  int n = 0 ;


  
  // Read input string using getline1 and store it in a pointer and stripping of the '\n'
  printf("Enter a string:\n");
 n =  getline1(input, 1000);
 inString[n-1] = '\0' ; 

//Reversing and storing the string
revstringdup(inString) ;

if ( n !=1) {
  printf("\nReverse string :\n%s\n",inString) ;
}
else {
  printf("The input string is emptey") ;
}
 return 0 ; 
}