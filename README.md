# Transposition-Cipher
Transposition Cipher Assignment

MIT 6.S096
Assignment 1, Problem 4
Problem 4: Transposition Cipher (loop)
A very simple transposition cipher encrypt (S ) can be described by the following rules:
1. If the length of S is 1 or 2, then encrypt (S ) is S .
2. If S is a string of N characters s 1 s 2 s 3 . . . s N and k = IN /2j, then

enc (S ) = encrypt (s k s k−1 . . . s 2 s 1 ) + encrypt (s N s N −1 . . . s k+1 )

where + indicates string concatenation.
For example, encrypt("Ok") = "Ok" and encrypt("12345678") = "34127856" .
Write a program to implement this cipher, given an arbitrary text file input up to 16 MB in size. Start
with the template program found at provided in the file loop.data.zip as a basis for your program.
In this program, you will see a mostly complete function to read a file into a dynamically allocated
string as required for this problem.
size t getstr( char **str, FILE *input ) {
size t chars to read = BLOCK SIZE;
size t length = 0;
II ...snipped... see template file
size t chars = 0;
while( ( chars = fread( *str + length, 1, chars to read, input ) ) ) {
II you fill this out
}
II ...snipped... see template file
return length;
}
Read through the code carefully, make sure you understand it, and complete the inner part of the while
loop. Look up realloc and the <string.h> header. If you have any questions about the provided code
or don’t know why something is structured the way it is, please ask about it on Piazza.
You will also see an empty function “encrypt”, which you should fill out.
void encrypt( char *string, size t length ) {
II you fill this out
}
Resource Limits
For this problem you are allotted 3 seconds of runtime and up to 32 MB of RAM.
Input Format
Lines 1. . . : The whole file (can be any number of lines) should be read in as a string.
1
MIT 6.S096
Assignment 1, Problem 4
Sample Input (file loop.in)
Test
early
and often!
Output Format
Line 1: One integer: the total number of characters in the string
Lines 2. . . : The enciphered string.
21
aeyrleT
sttf!enn
aod
Output Explanation
Here’s each character in the string as we are supposed to read it in, separated with ‘.’ so we can see the
newlines and spaces:
.T.e.s.t.\n.e.a.r.l.y.\n.a.n.d. .o.f.t.e.n.!.
The string is first split in half and then each half reversed, and the function called recursively; you can
see the recursion going on here:
.y.l.r.a.e.\n.t.s.e.T.
.!.n.e.t..f.o. .d.n.a.\n.
.e.a.r.l.y.
.T.e.s.t.\n.
.f.t.e.n.!.
.\n.a.n.d. .o.
.a.e. .y.l.r .e.T. .\n.t.s. .t.f. .!.n.e .n.a.\n. .o. .d.
I \
I
\
I \
\
.y. .r.l.
.\n. .s.t.
.!. .e.n.
\
I \
I \
.n. .\n.a. .o. .d. .
This diagram makes it look a bit more complicated than it actually is. You can see that the sample is
correct by reading off the leaves of the tree from left to right–it’s the enciphered string we want.
.a.e.y.r.l.e.T.\n.s.t.t.f.!.e.n.n.\n.a.o.d. .
2
MIT OpenCourseWare
http://ocw.mit.edu
6.S096 Effective Programming in C and C++
IAP 2014
For information about citing these materials or our Terms of Use, visit: http://ocw.mit.edu/terms.
