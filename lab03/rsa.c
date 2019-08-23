#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM *a)
{
  char *number_str = BN_bn2hex(a);
  printf("%s %s\n", msg, number_str);
  OPENSSL_free(number_str);
}

int main()
{
  BN_CTX *ctx = BN_CTX_new();
  BIGNUM *p = BN_new();
  BIGNUM *q = BN_new();
  BIGNUM *e = BN_new();
  BIGNUM *n = BN_new();
  BIGNUM *one = BN_new();
  BIGNUM *negone = BN_new();
  BIGNUM *pminus = BN_new();
  BIGNUM *qminus = BN_new();
  BIGNUM *on = BN_new();
  BIGNUM *d = BN_new();

  BIGNUM *msg = BN_new();
  BIGNUM *res = BN_new();

  //Initialise a, b, n
  BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
  BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
  BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
  // BN_hex2bn(&e, "0D88C3");
  BN_hex2bn(&e, "010001");
  BN_hex2bn(&msg, "4120746f702073656372657421");
  BN_dec2bn(&one, "1");
  BN_dec2bn(&negone, "-1");
  //BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

  //calculate n
  // BN_mul(n, p, q, ctx);
  // printBN("n = p * q: ", n);

  //calculate on
  BN_sub(pminus, p, one);
  BN_sub(qminus, q, one);
  BN_mul(on, pminus, qminus, ctx);
  printBN("on = p-1 * q-1: ", on);

  //calculate private key, d
  BN_mod_inverse(d, e, on, ctx);
  printBN("d = ", d);

  return 0;
}
