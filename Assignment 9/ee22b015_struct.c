#include <stdio.h>
#include <math.h>

/* Define two structs for complex numbers:
   one for rectangular representation and 
   one for polar representation */
typedef struct
{
    float real;
    float imag;
} complex_rect;

typedef struct
{
    float magn;
    float angle;
} complex_polar;

// Add two complex numbers in rectangular representation
complex_rect add_complex(complex_rect a, complex_rect b)
{
    complex_rect res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

// Subtract two complex numbers in rectangular representation
complex_rect sub_complex(complex_rect a, complex_rect b)
{
    complex_rect res;
    res.real = a.real - b.real;
    res.imag = a.imag - b.imag;
    return res;
}

// Multiply two complex numbers in polar representation
complex_polar mult_complex(complex_polar a, complex_polar b)
{
    complex_polar res;
    res.magn = a.magn * b.magn;
    res.angle = a.angle + b.angle;
    return res;
}

// Divide two complex numbers in polar representation
complex_polar div_complex(complex_polar a, complex_polar b)
{
    complex_polar res;
    if (b.magn == 0) {
        printf("Error: Division by zero is not allowed\n");
        res.magn  =0 ;
        res.angle = 0 ;
        return res ;
        
    }
    else {
    
    res.magn = a.magn / b.magn;
    res.angle = a.angle - b.angle;
    return res;
    }
}

// Convert complex number from rectangular to polar representation
complex_polar rect_to_polar(complex_rect a)
{
    complex_polar res;
    res.magn = sqrt(a.real * a.real + a.imag * a.imag);
    res.angle = atan2(a.imag, a.real);
    return res;
}

// Convert complex number from polar to rectangular representation
complex_rect polar_to_rect(complex_polar a)
{
    complex_rect res;
    res.real = a.magn * cos(a.angle);
    res.imag = a.magn * sin(a.angle);
    return res;
}

// Clear the standard input buffer
void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Display the main menu and get user's choice
int menu()
{
    int choice;
    int check;
    printf("\nMenu:\n");
    printf("1. Add two complex numbers (rectangular)\n");
    printf("2. Subtract two complex numbers (rectangular)\n");
    printf("3. Multiply two complex numbers (rectangular to polar to rectangular)\n");
    printf("4. Divide two complex numbers (rectangular to polar to rectangular)\n");
    printf("5. Convert rectangular to polar\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    check = scanf("%d", &choice);
    clear_stdin();
    if ((choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5) && (check == 1))
        return choice;
    else
    {
        printf("\nplease enter a valid input\n");
        choice = menu();
    }
}

//Function take in the 1st complex number
complex_rect in_struct1()
{
    complex_rect in_struc1;
    int check;
    
    printf("Please enter the real part of the first complex number: ");
    check = scanf("%f", &in_struc1.real);
    clear_stdin();
    if (check != 1) {
        printf("Invalid input!\n");
        return in_struct1();
    }

    printf("Please enter the imaginary part of the first complex number: ");
    check = scanf("%f", &in_struc1.imag);
    clear_stdin();
    if (check != 1) {
        printf("Invalid input!\n");
        return in_struct1();
    }

    return in_struc1;
}

//Function to take in the 2nd complex number
complex_rect in_struct2()
{
    complex_rect in_struc2;
    int check;
    
    printf("Please enter the real part of the second complex number: ");
    check = scanf("%f", &in_struc2.real);
    clear_stdin();
    if (check != 1) {
        printf("Invalid input!\n");
        return in_struct2();
    }

    printf("Please enter the imaginary part of the second complex number: ");
    check = scanf("%f", &in_struc2.imag);
    clear_stdin();
    if (check != 1) {
        printf("Invalid input!\n");
        return in_struct2();
    }

    return in_struc2;
}

//Function with performs the operation
int function_operator(int x, complex_rect in1, complex_rect in2)
{

    if (x == 1)
    {
        complex_rect addstruct = add_complex(in1, in2);
        printf("the sum of the complex numbers is :\n%f + %fi\n", addstruct.real, addstruct.imag);
    }
    if (x == 2)
    {
        complex_rect substruct = sub_complex(in1, in2);
        printf("the difference of the complex numbers is :\n%f + %fi\n", substruct.real, substruct.imag);
    }

    /*converts rect to polar then performs multiplication then converts it back into rect and displays*/
    if (x == 3)
    {
        complex_polar temppolarm1 = rect_to_polar(in1);
        complex_polar temppolarm2 = rect_to_polar(in2);
        complex_polar mulstruct = mult_complex(temppolarm1, temppolarm2); 
        complex_rect resultproduct = polar_to_rect(mulstruct);
        printf("the product of the complex number is :\n%f + %fi\n", resultproduct.real, resultproduct.imag);
    }

    /*converts rect to polar then performs division then converts it back into rect and displays*/
    if (x == 4)
    {
        complex_polar temppolard1 = rect_to_polar(in1);
        complex_polar temppolard2 = rect_to_polar(in2);
        complex_polar divstruct = div_complex(temppolard1, temppolard2);
        complex_rect resultdiv = polar_to_rect(divstruct);
        if (temppolard2.magn == 0) {
            printf("Division is not defined when divided by zero \n") ;
        }
        else {
        printf("the division of the complex number is :\n%f + %fi\n", resultdiv.real, resultdiv.imag);
        }
    }

    /*Bonus function in menu*/
    if (x == 5)
    {
        complex_polar polarstruct1 = rect_to_polar(in1) ;
        complex_polar polarstruct2 = rect_to_polar(in2) ; 
        if (polarstruct1.magn == 0) {
            printf("r = 0 , theta is undefined for this case\n") ;
        }
        else printf("r = %f , theta = %f\n",polarstruct1.magn,polarstruct1.angle) ;
        if (polarstruct2.magn == 0) {
            printf("r = 0 , theta is undefined for this case\n") ;
        }
        else printf("r = %f , theta = %f\n",polarstruct2.magn,polarstruct2.angle) ;

    }
    return 0;
}

int inputcheck = 0;
complex_rect instruct2 ;
complex_rect instruct1 ;

int main()
{
     if(inputcheck == 0) {
        instruct1 = in_struct1();       //input
        instruct2 = in_struct2();       //input
        inputcheck = 1 ;
     }

    int selection = menu();          //calls menu
        if (selection == 0)          //exiting case
        return 0;

    int i = function_operator(selection, instruct1 , instruct2); //calls the function operator

    if (i == 0) main();  //recursive
}