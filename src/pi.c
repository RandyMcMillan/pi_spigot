/* Print pi to n decimal places (default 1000): pi n */

#define DEBUG 1
#define DEBUG2 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <unistd.h>

//#include "../include/argparse.h"

// #define M_LOG2E 1.44269504088896340736 // log2(e)
// inline long double log2(const long double x){
//     return log(x) * M_LOG2E;
// }

void help();
void help(){

	printf("gnostr-pi - deterministic entropy                     \n");
	printf("                                                      \n");
	printf("gnostr-pi   depth                                     \n");
	printf("gnostr-pi   <int>                                     \n");
	printf("                                                      \n");
	printf("gnostr-pi   0     		                                  \n");
	printf("gnostr-pi   4     		  1415                            \n");
	printf("gnostr-pi   8     		  14159265                        \n");
	printf("gnostr-pi   12    		  141592653589                    \n");
	printf("gnostr-pi   16    		  1415926535897932                \n");
	printf("gnostr-pi   20    		  14159265358979323846            \n");
	printf("gnostr-pi   24    		  141592653589793238462643        \n");
	printf("gnostr-pi   28    		  1415926535897932384626433832    \n");
	printf("gnostr-pi   32    		  14159265358979323846264338327950\n");
	printf("                  		                                  \n");
	printf("gnostr-pi   depth   offset	  default 1000 digits of pi mantissa\n");
	printf("                          	  The mantissa of π is the fractional part.\n");
	printf("                          	  (i.e. everything after the decimal place).\n");
	printf("            <int>   <int> 	                           \n");
	printf("            0       0     	  14159265...64201989      \n");
	printf("            0       1     	  offset 1*4 digits        \n");
	printf("            0       2     	  offset 2*4 digits        \n");
	printf("            0       3     	  offset 3*4 digits        \n");
	printf("            0       4     	  offset 4*4 digits        \n");
	printf("            0       n     	  offset n*4 digits        \n");

//
printf("\n");
printf("Context:\n");
printf("\n");
printf("\n");
// printf("About:\n");
// printf("\n");
// printf("Compute pi to B bits precision by the Spigot algorithm given by\n");
// printf("Rabinowitz and Wagon, Am. Math. Monthly, March 1995, 195-203.\n");
// printf("\n");
// printf("	pi = 4;\n");
// printf("	for (i = B; i>0; --i)\n");
// printf("	    pi = 2 + pi * i / (2*i+1)\n");
// printf("\n");
// printf("pi is represented by a base 10000 array of digits with 2 digits before\n");
// printf("the decimal point (pi[0], pi[1]), and one extra digit (pi[n-1]) at\n");
// printf("the end to allow for roundoff error, which is not printed.  Note that a\n");
// printf("base 10 digit is equivalent to log(10)/log(2) = 3.322 bits.\n");
//
// 3.32192809488736234787031942948939017586483139302458061205475639581593477...
// if π = log(10)/log(x) then x = 10^(1/π)

exit(0);
}

void int2bin(int n, int* bin, int* bin_size, const int bits);
void int2bin(int n, int* bin, int *bin_size, const int bits)
{
    int i = 0;
    int temp[64];
    for (int j = 0; j < 64; j++)
    {
        temp[j] = 0;
    }
    for (int l = 0; l < bits; l++)
    {
        bin[l] = 0;
    }

    while (n > 0)
    {
        temp[i] = n % 2;
        n = n / 2;
        i++;
    }
    *bin_size = i;

    //reverse modulus values
    for (int k = 0; k < *bin_size; k++)
    {
        bin[bits-*bin_size+k] = temp[*bin_size - 1 - k];
    }
}

void printbin();
void printbin(int *binary){
	if (DEBUG2){
		printf("printbin\n");
		for (int i = 0; i < 32; i++){ printf("%p=%d\n", &binary[i], binary[i]); }
	}
}
/* Print pi as an array of n digits in base 10000 */
void print(unsigned short *pi, int n, int offset) {

  int i;

  /*
   * // REMOVE characteristic '3.'
   * // we are only concerned with mantissa
   * printf("%d.", pi[1]);
   */

  if (DEBUG2){

    char buffer[256];
    char temp[256];
    int max_len = sizeof buffer;
    // int j = snprintf(buffer, max_len, "The %u %u fox jumped over the %u dog.", pi[2], pi[3], pi[4]);
    int j = snprintf(buffer, max_len, "%u",0);
    printf("1:%d\n", j);
    // puts(buffer);
    memcpy(temp,buffer,max_len);
    j += snprintf(buffer, max_len, "%u%s",0,temp);
    printf("2:%d\n", j);
    // puts(buffer);
    memcpy(temp,buffer,max_len);
    j += snprintf(buffer, max_len, "%u%s",0,temp);
    printf("3:%d\n", j);
    // puts(buffer);
    memcpy(temp,buffer,max_len);
    j += snprintf(buffer, max_len, "%u%s",0,temp);
    printf("4:%d\n", j);
    // puts(buffer);
    memcpy(temp,buffer,max_len);
    j += snprintf(buffer, max_len, "%u%u%u + %s", pi[2], pi[3], pi[4], temp);
    printf("5:%d", j);
    // puts(buffer);
    printf("\nbytes"
             "(excluding the null terminator)=%d\n",
             j);
    if (j >= max_len)
        fputs("Buffer length exceeded; string truncated", stderr);
    puts("Joined string:");
    puts(buffer);

    // exit(9999);
  }

  // printf("%04d", pi[0]);
  // printf("%04d", pi[1]);
  for (i=2+offset; i<n-1; ++i){
	  if (DEBUG2){
		  printf("DEBUG:%04d\n", pi[i]);
	  }
  }
  printf("\n");
  // exit(0);

  char pi_buffer[256];
  char pi_temp[256];
  int  pi_max_len = sizeof pi_buffer;
  int  pi_j = snprintf(pi_buffer, pi_max_len, "%s", "");
  memcpy(pi_temp, pi_buffer, pi_max_len);

  for (i=2+offset; i<n-1; ++i){
	  // printf("i=%d\n", i);
	  // printf("%04d\n", pi[i]);
	  // printf("%04d", pi[i]);
      pi_j += snprintf(pi_buffer, pi_max_len, "%s%u", pi_temp, (int)pi[i]);
      memcpy(pi_temp,pi_buffer,pi_max_len);
      //puts((char *)pi_buffer);
  }
  puts((char *)pi_buffer);
	// 4 dec digits per printf
  printf("\n");
}

/* Compute pi to B bits precision by the Spigot algorithm given by
Rabinowitz and Wagon, Am. Math. Monthly, March 1995, 195-203.

   pi = 4;
   for (i = B; i>0; --i)
     pi = 2 + pi * i / (2*i+1)

pi is represented by a base 10000 array of digits with 2 digits before
the decimal point (pi[0], pi[1]), and one extra digit (pi[n-1]) at
the end to allow for roundoff error, which is not printed.  Note that a
base 10 digit is equivalent to log(10)/log(2) = 3.322 bits.

For shorter versions, see
http://www1.physik.tu-muenchen.de/~gammel/matpack/html/Mathematics/Pi.html
http://numbers.computation.free.fr/Constants/TinyPrograms/tinycodes.html

and for an explanation of how they work, see
Unbounded Spigot Algorithms for the Digits of Pi,
Jeremy Gibbons, University of Oxford, 2004,
http://web.comlab.ox.ac.uk/oucl/work/jeremy.gibbons/publications/spigot.pdf

*/

int main(int argc, char** argv) {

/*
   input 0 4 8 12 16 20 24 28 etc...
*/
if (DEBUG2){
/*
   begin int2bin
*/

   char ch;
   ch = 'A';

   int binary[sizeof(int)*8];
   int binary_size = 0;

/*
   int2bin(int n, int* bin, int* bin_size, const int bits);
*/

   // printf("sizeof(int)=%lu\n",sizeof(int));
   // printf("sizeof(int)-1=%lu\n",sizeof(int)-1);
   // printf("sizeof(binary)=%lu\n",sizeof(binary));

   int2bin(0, binary, &binary_size, sizeof(int)-1);
   printf("case:0\n");

   printf("sizeof(binary)=%lu\n",sizeof(binary));
   printf("sizeof(binary_size)=%lu\n",sizeof(binary_size));
   printbin(binary);printf("\n");
   printf("binary=%d\n",binary[(sizeof(binary)/4-1)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-2)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-3)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-4)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-5)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-6)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-7)]);

   int2bin(ch, binary, &binary_size, 32);
   printf("case:%c\n",ch);
   printf("sizeof(binary)=%lu\n",sizeof(binary));
   printf("sizeof(binary_size)=%lu\n",sizeof(binary_size));
   printbin(binary);printf("\n");
   printf("*binary=%d\n",*binary);
   printf("binary=%d\n",binary[(sizeof(binary)/4-1)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-2)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-3)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-4)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-5)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-6)]);
   printf("binary=%d\n",binary[(sizeof(binary)/4-7)]);

   int2bin(1324, binary, &binary_size, 32);
   // printf("sizeof(binary)=%lu\n",sizeof(binary));
   // printf("*binary=%d\n",*binary);
   // printbin(binary);
   // printf("binary=%d\n",binary[(sizeof(binary)/4-1)]);
   // printf("binary=%d\n",binary[(sizeof(binary)/4-2)]);
   // printf("binary=%d\n",binary[(sizeof(binary)/4-3)]);
   // printf("binary=%d\n",binary[(sizeof(binary)/4-4)]);
   // printf("binary=%d\n",binary[(sizeof(binary)/4-5)]);
   // printf("binary=%d\n",binary[(sizeof(binary)/4-6)]);

   // static char buf[128] = {0};
   // const char *sub = argv[1];
   // if (strlen(sub) >= 1 && sub[0] != '-') {
   //     snprintf(buf, sizeof(buf)-1, "echo %s", sub);
   //     execvp(buf, (char * const *)argv+1);
   // }


   //exit(0);

/*
   end int2bin
*/
}
/*
TODO:
{A = 1, B = 0, C = 0, N!=0, x = 7/N^2, sqrt(343/N^6 + 7) = y}
*/

  if (argc == 1){

	// printf("argc=%d\n",argc);
	help();exit(0);

  }

  int n = {253};
  int offset = {0};

  // printf("argv[1]=%d\n", atoi(argv[1]));
  if (argc == 2){

	  if (DEBUG2) {
		  printf("atoi(argv[1])=%d\n", atoi(argv[1]));
	  }

	  n = argc == 2 ? (atoi(argv[1]) + 3)/4 + 3 : 253;  /* 253 -> 1000 default number of pi digits */

	  if (DEBUG2) {
		  printf("n=%d\n", n);//exit(0);
		  printf("log(n)=%f\n", log(n));// keep percision
		  printf("log2(n)=%f\n", log2(n));// keep percision
		  printf("log(2)=%f\n", log(2));// keep percision
		  printf("log2(2)=%f\n", log2(2));// keep percision
		  printf("bit/%f\n", log(10) / log(2));// keep percision
		  printf("bits/%f\n", log(n) / log(2));// keep percision
	  }
  }

  if (argc == 3){

	  if (DEBUG2) {
		  printf("argc=3\n");
		  printf("depth:atoi(argv[1])=%d\n", atoi(argv[1]));
		  printf("offset:atoi(argv[2])=%d\n", atoi(argv[2]));
	  }

	  offset = atoi(argv[2]);
	  n = argc == 2 ? (atoi(argv[1]) + offset)/4 + offset : 253;  /* 253 default number of pi digits */
	  if (DEBUG) {
		  printf("n=%d\n", n);//exit(0);
		  printf("offset=%d\n", offset);
	  }
	  n += offset;
	  if (DEBUG) {
		  printf("n += offset:%d\n", n);
		  // printf("bits/%f\n", log2(n) / log2(2));// keep percision
		  // printf("bits/%f\n", log2(atoi(argv[1])) / log2(2));// keep percision
	  }
  }

if (argc == 4){
	  printf("TODO:handle <path,salt>\n");
	  printf("%d\n", atoi(argv[3]));
	  exit(0);
	  
}
  if (argc > 4){ help(); }

  // printf("bits/%f\n", log2(n) / log2(2));// keep percision
  // printf("bits/%f\n", log2(atoi(argv[1])) / log2(2));// keep percision

  // printf("*pi = n * sizeof(unsigned short)=%lu\n", n * sizeof(unsigned short));
  unsigned short *pi = (unsigned short*) malloc(n * sizeof(unsigned short));
  div_t d;
  int i, j, t;

  /* pi = 4  */
  memset(pi, 0, n*sizeof(unsigned short));
  pi[1]=4;

  /* for i = B down to 1 */
  for (i=(int)(3.322*4*n); i>0; --i) {

    /* pi *= i; */
    t = 0;
    for (j=n-1; j>=0; --j) {  /* pi *= i; */
      t += pi[j] * i;
      pi[j] = t % 10000;
      t /= 10000;
    }

    /* pi /= (2*i+1) */
    d.quot = d.rem = 0;
    for (j=0; j<n; ++j) {  /* pi /= 2*i+1; */
      d = div(pi[j]+d.rem*10000, i+i+1);
      pi[j] = d.quot;
    }

    /* pi += 2 */
    pi[1] += 2;
  }

  print(pi, n, offset);
  return 0;
}

