// Limits
// Daniel Pereira, 04 November 2022.

// Use limits.h and float.h to access MIN and MIX variables.

#include <stdio.h>
#include <limits.h> // limits on integer types
#include <float.h>  // limits on floating point types

int main(int argc, char* argv[])
{

    printf("INTEGER TYPE, MIN, MAX.\n");
    printf("-----------------------\n");
    printf("char, %d, %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char, NA, %u\n", UCHAR_MAX);
    printf("short, %d, %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short,NA,%u\n", USHRT_MAX);
    printf("int, %d, %d\n", INT_MIN, INT_MAX);
    printf("unsigned int, NA, %u\n", UINT_MAX);
    printf("long, %ld, %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long, NA, %lu\n", ULONG_MAX);
    printf("long long, %lld, %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long, NA, %llu\n\n", ULLONG_MAX);

    printf("FLOATING POINT TYPE, MIN, MAX.\n");
    printf("------------------------------\n");
    printf("Float MIN: %.3e\n", FLT_MIN);
    printf("Float MAX: %.3e\n", FLT_MAX);
    printf("Double MIN: %.3e\n", DBL_MIN);
    printf("Double MAX: %.3e\n", DBL_MAX);
    printf("Long Double MIN: %.3Le\n", LDBL_MIN);
    printf("Long Double MAX: %.3Le\n", LDBL_MAX);
    printf("Number of decimal digits precision of float: %u\n", FLT_DIG);
    printf("Number of decimal digits precision of double: %u\n", DBL_DIG);
    printf("Number of decimal digits precision of long double: %u\n", LDBL_DIG);

    return 0;
}

// climits <limits.h>
// https://devdocs.io/cpp/header/climits
// This header was originally in the C standard library as <limits.h>.
// 
// This header is part of the type support library, in particular it's part of the C numeric limits interface.

// <float.h>
// https://www.tutorialspoint.com/c_standard_library/float_h.htm
//
// The float.h header file of the C Standard Library contains a set of various platform-dependent constants related to floating point values. These constants are proposed by ANSI C. They allow making more portable programs.