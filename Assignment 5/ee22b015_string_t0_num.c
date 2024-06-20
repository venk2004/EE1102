#include <stdio.h>
#define MAXLENGTH 1000

/*Getline given in prerequisites*/
int getline1(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') s[i++] = c;
	if (c == '\n') s[i++] = c;
	s[i] = '\0';	
	return i;
}

/*Forming the clusters from the given user input then storing it in another string seperating each one by '\n'. */
/*Works by ignoring spaces and replaces a space by '/n' when it encounters a space after a valid character      */
int ClusterMaker (char s[] , char t[]) {
    int i,j=0,k=0,l=0         ;

     for(i=0 ; s[i] != '\0' ; i++ )   {
	     if (s[i] == ' ') {
	}
	     else {
			 t[j++]=s[i]  ;
	}
	     if (s[i+1] ==' ' && s[i]!= ' ') {
             t[j++] ='\n' ;
			 l++          ;
	}
}
t[j] = '\0'               ;
return l                  ;
}

/*Collecting numbers from each cluster then storing it in an array*/
int numberInCluster (char p[],int v[] ,double q[])  {

	int i=0,j=0,k=0 ; //Variables used for internal counting
	int decimalCheck=0,numberOfClusters=0,maxDecimalPlaces=0,negativeCheck =0; //Defining necessary variables with suitable names

     for (;p[i] != '\0' ;i++,j++,q[j]=0,v[j]=0,negativeCheck =0,maxDecimalPlaces=0,decimalCheck=0) { //iterates with increasing index for double array

	     for ( ;p[i]!= '\n';i++){                                       // Iterates position of string array
			 if (p[i] == '-' && negativeCheck != 1 ) negativeCheck = 2 ;// Checks for the '-' occuring before a number
			 if ((p[i]) == '.') ++decimalCheck                         ;// Check if a decimal has occured
	         if(47<p[i] && 58>p[i]) {                                   // Uses ASCII value to identify if that character is a number
				 v[j] =1                                               ;// Registers as a valid number 
				 if (negativeCheck != 2) negativeCheck =1              ;// Checks for the '-' occuring before a number
				 if (decimalCheck != 0) maxDecimalPlaces++             ;// Increasing the numbers time we should divide by 10
		         q[j] = q[j]*10 + (p[i] -'0')                          ;// A simple way to get number using ASCII values
			     }
		 }
		 for(k=0 ;k<maxDecimalPlaces ;k++){                             // Dividing by 10's
			 (q[j])*=(.1)                                              ;
		 }
         if (negativeCheck == 2) q[j] *= -1                            ;// Multiplying -1 if the number is negative
		 if (v[j] != 0 ) numberOfClusters++                            ;// Getting number of valid numbers 
	}
return numberOfClusters                                                ;// This function return number of valid numbers.
}

int main () {

char inString[MAXLENGTH]  ;  // Input string
char parts[MAXLENGTH]     ;  // Contains clusters
double doubles[MAXLENGTH] ;  // Contains numbers from each clusters
int validCheck[MAXLENGTH] ;  // Tells if there was a number in that cluster

                                /*Gets the string from user*/
     printf("Enter a line of maximum length 1000 and press enter to proceed :\n")  ;
     int a = getline1 (inString,MAXLENGTH)                                         ;

                                /*Forms and prints clusters*/
     int b = ClusterMaker (inString,parts)                                         ;
     printf("\nThe clusters are :\n%s\n",parts)                                    ;

                                /*Gets numbers from each clusters and prints it*/
     int c = numberInCluster(parts,validCheck,doubles)                             ;
	    printf("\nNumbers in each clusters are :\n")                               ;
         for(int i=0 ;i<=b;i++) {
	         if (validCheck[i] == 0) {
				 printf("Error no number in this cluster\n")                       ;
			 }
	         else if (validCheck[i] == 1) printf("%lf\n",doubles[i])               ;
         } 
	 printf("\n\nvalid numbers are %d\n",c)                                        ;

}