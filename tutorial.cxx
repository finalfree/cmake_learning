//A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MyMathFunctions.h"
#endif

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "%s Version %d.%d\n", PROJECT_NAME, Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s [number]\n", argv[0]);
        return 1;
    }

    double inputValue = atof(argv[1]);

#ifndef HAVE_TEST_WANG
    fprintf(stdout, "%s don't have my test function\n", PROJECT_NAME);
#endif

#ifdef USE_MYMATH
    double outputValue = mysqrt(inputValue);
    fprintf(stdout, "%s use my math\n", PROJECT_NAME);
#else
    double outputValue = sqrt(inputValue);
    fprintf(stdout, "%s not use my math\n", PROJECT_NAME);
#endif
    fprintf(stdout, "The square root of the number %g is %g\n", inputValue, outputValue);
    return 0;
}