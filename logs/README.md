the number if digits in the mantissa

this will deviate from counts including '3.'
which we are not concerned with.


modify the function to return `3.`

```
/* Print pi as an array of n digits in base 10000 */
void print(unsigned short *pi, int n) {
  int i;

/* REF: https://en.wikipedia.org/wiki/Common_logarithm#Mantissa_and_characteristic
 * REMOVE characteristic '3.'
 * we are only concerned with mantissa
  printf("%d.", pi[1]);
*/
  for (i=2; i<n-1; ++i)
    printf("%04d", pi[i]);
  printf("\n");
}

```
