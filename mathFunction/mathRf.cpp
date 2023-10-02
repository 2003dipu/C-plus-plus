/*
#include <iostream>
#include<cmath>

int main()
{

    std::cout << " \n\n";
    std::cout << "--------------------------------------------------------------- \n";
    double x = 23.234;
    double y = 63.4;
    double a = 3;
    double b = 4;
    double n;
    //double z = std::max(x, y);
    //double p = std::min(x, y);
    //std::cout << "The maximum number between " << x << " and " << y  << " is: " << z << " \n\n";
    //std::cout << "The minimum number between " << x << " and " << y  << " is: " << p << " \n\n";

    // power functions
    //n = pow(a, b);
    //std::cout << n << "\n";
    //n = pow(2, 5);
    //n = sqrt(169);
    //n = abs(-123.3);
    x = 19.9999;
    //n = round(x);
    //n = ceil(x);
    n = floor(x);
    std::cout << n << "\n";


    std::cout << "---------------------------------------------------------------\n\n";// beautiful design by Dipu Singha
    return 0;
}

// GENTEXT.C
// use of generic-text mappings defined in TCHAR.H

// crt_mbcsgtxt.c


 * Use of generic-text mappings defined in TCHAR.H
 * Generic-Text-Mapping example program
 * MBCS version of GENTEXT.C

// C codes to reverse a string
#include <stdio.h>
#include <stdlib.h>
#include <mbstring.h>
#include <direct.h>

int __cdecl main(int argc, char **argv, char **envp)
{
   char buff[_MAX_PATH];
   char *str = "Astring";
   char *amsg = "Reversed";
   wchar_t *wmsg = L"Is";

   printf("MBCS version\n");

   if (_getcwd(buff, _MAX_PATH) == NULL) {
       printf("Can't Get Current Directory - errno=%d\n", errno);
   }
   else {
       printf("Current Directory is '%s'\n", buff);
   }

   printf("'%s' %hs %ls:\n", str, amsg, wmsg);
   printf("'%s'\n", _mbsrev(_mbsdup((unsigned char*) str)));
   return 0;
}


// C++ Hypotenuse calculator practice program
#include<iostream>
#include<math.h>

int main()
{
    std::cout << " \n";
    std::cout << "---------------------------------------------------------------\n";
    std::cout << "Welcome to Hypotenuse calculator program\n";
    std::cout << " |\\ \n";
    std::cout << " | \\ \n";
    std::cout << " |  \\ \n";
    std::cout << "A|   \\C \n";
    std::cout << " |    \\ \n";
    std::cout << " |     \\ \n";
    std::cout << " |______\\ \n";
    std::cout << "   B \n";
    std::cout << "---------------------------------------------------------------\n";

    double a;
    double b;
    std::cout << "Enter side A: ";
    std::cin >> a;
    std::cout << "Enter side B: ";
    std::cin >> b;
    double hypotenuse = sqrt(a*a + b*b);
    std::cout << "Side C: " << hypotenuse;


    return 0;
}
*/

// C++ rectangle area calculator practice program
#include<iostream>
#include<math.h>

int main()
{
    std::cout << " \n";
    std::cout << "-------------------------------------------------------------------------------\n";
    std::cout << "Welcome to rectangle calculator program. Measure your Real Estate rantangular shape's area: \n\n";
    std::cout << "          D(Length) \n";
    std::cout << "  ____________________ \n";
    std::cout << " |                    | \n";
    std::cout << " |                    | C(Width) \n";
    std::cout << " |                    | \n";
    std::cout << " |                    | \n";
    std::cout << " |____________________| \n\n";

    std::cout << "--------------------------------------------------------------------------------\n";

    double a;
    double b;
    double c;
    double d;
    std::cout << "Enter Length in meter: ";
    std::cin >> a;
    std::cout << "Enter Width meter: ";
    std::cin >> b;
    double area = a * b;
    std::cout << "Area: " << area << " squared meter.";


    return 0;
}
