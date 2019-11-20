Ft_printf is a Codam curriculum project in which students have to implement the <stdio.h> function printf.
normal printf is an elaborate function with a lot of different features. This implementation of printf supports the following output formats:

-   characters (%c)
-   strings (%s)
 -   pointers (%p)
-   integers signed/unsigned (%i)
-   decimals (%d)
-   Hexadecimal notation (%xX)
-   floating point values (%f)
-   Octal notation (%oO)

-   for numeric values the following size flags are supported: hh, h, l, ll
-   for all output formats the following flags are supported: #0-+ (behavior can differ between output formats but is consistent with real printf)
-   width and precision specification is supported for all output formats.

Running the make file in the root of this repo will compile the libftprintf library and a test program that includes the testfiles located in /srcs.
If you just want to compile the library without the testsuite, run the Makefile within libftprintf. 
