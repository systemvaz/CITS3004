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
  BIGNUM *e = BN_new();
  BIGNUM *n = BN_new();
  BIGNUM *d = BN_new();
  BIGNUM *m = BN_new();
  BIGNUM *phin = BN_new();
  BIGNUM *encrypted = BN_new();
  BIGNUM *decrypted = BN_new();

  BN_hex2bn(&n, "9DD7BE17C49CA5");
  BN_hex2bn(&e, "40F");
  BN_dec2bn(&d, "24117260108961919");
  BN_dec2bn(&phin, "44428782363850060");

  BN_mod_mul(m, d, e, phin, ctx);
  printBN("this should equal 1 = ", m);
  printBN("d=", d);
}
