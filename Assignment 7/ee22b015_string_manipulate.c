#include <stdio.h>

// Function definition for getline1
int getline1(char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = '\0';
  }
  return i;
}


// Function definition for strlen
int strlen(char *s) {
  int n = 0;
  while (*s != '\0') {
    n++;
    s++;
  }
  return n;
}


// Function definition for strcpyn
char *strcpyn(char *s1, char *s2, int n) {
  // Check for error condition
  if ( (strlen(s1) < n) ||(n<0)) {
    return "Error: Invalid value for n";
    n= -1 ;
  }

  // Copy first n characters from s1 to s2
  for (int i = 0; i < n; i++) {
    *(s2+i) = *(s1+i);
  }
  *(s2+n) = '\0';
  n = 1 ;
  printf("Output string : ") ;
  
  return s2;

}

// Function definition for strcmpn
int strcmpn(char *s1, char *s2, int n) {

  if ((strlen(s1) < n )||(strlen(s2) < n ) || (n<0)) return -1 ;

  // Compare the first n characters of s1 and s2
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      return 0;
    }
  }
  return 1;
}



int main() {
  
  // Declare variables
  char inString[1000] ;
  char outString[1000] ;
  char compareString[1000] ;

  
  char *input = &inString[0];
  int n1, n2, n3;
  char *output = &outString[0];
  char *compare = &compareString[0];

  // Read input string using getline1 and store it in a pointer
  printf("Enter a string: ");
  getline1(input, 100);

  // Remove newline character from the end of the input string if present
  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }

  // Get length of input string using strlen function
  printf("Length of input string: %d\n", strlen(input));

  // Get a copy of the first n2 characters of the input string using strcpyn function
  printf("Enter how many letters you wanna copy : ");
  scanf("%d", &n2);
  output = strcpyn(input, output, n2);
  if (n2 == 1) {
     printf("%s\n", output);
  }
  else {
    printf("%s\n",output) ;
  }
  
  // Clear the input buffer
  fflush(stdin);
 
  // Compare the first n3 characters of the input string with another string using strcmpn function
  printf("Enter a string to compare: ");
  getline1(compare, 100);
  printf("Enter how many letters you wanna compare: ");
  scanf("%d", &n3);
  int result = strcmpn(input, compare, n3);
  if (result == 1) {
    printf("MATCH\n");
  } 
  else if (result == 0) {
    printf("NO MATCH\n");
  }
  else if (result == -1) {
    printf("Invalid request\n") ;
  }

  return 0;
}






