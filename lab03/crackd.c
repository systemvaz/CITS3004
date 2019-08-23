#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM *a)
{
  char *number_str = BN_bn2hex(a);
  printf("%s %s\n", msg, number_str);
  OPENSSL_free(number_str);
}

int main()
{
  BN_CTX *ctx = BN_CTX_new();

  BIGNUM *n = BN_new();
  BIGNUM *e = BN_new();
  BIGNUM *d = BN_new();
  BIGNUM *c = BN_new();

  BN_hex2bn(&n, "9DD7BE17C49CA5");
  BN_hex2bn(&e, "40F");
  long nint = 44428782786092197;
  long p = 0;

  for (long i = 210781361; i > 0; i=i-2)
  {
    long r = nint % i;
    printf("Testing %ld mod %ld = %ld\n", nint, i, r);
    if(r == 0)
    {
      p = i;
      printf("Found!!!!");
      long q = nint / p;
      printf("p=%ld , q=%ld, n=%ld, p*q=%ld, n-p*q=%ld\n", p, q, nint, p*q, nint-(p*q));
      long phin = (p-1)*(q-1);
      printf("phin=%ld\n", phin);
      break;
    }
  }
}

// Found!!!!p=199149311 , q=223092827, n=44428782786092197, p*q=44428782786092197, n-p*q=0
// phin=44428782363850060
//d=55AE8531C0187F

//Python......
// e = 5
// import gmpy
// d = gmpy.invert(e, phin)
// print d, e, d*e %phin
