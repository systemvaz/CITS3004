#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 4120746f702073656372657421

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
  BIGNUM *m = BN_new();

  BIGNUM *encrypted = BN_new();
  BIGNUM *decrypted = BN_new();

  // BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
  // BN_hex2bn(&e, "010001");
  // BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
  // BN_hex2bn(&m, "4120746f702073656372657421");
  //
  // printBN("original: ", m);
  // //Encrypt message using public keys
  // //BN_hex2bn(&encrypted, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
  // BN_hex2bn(&encrypted, "24C89C26F6DA860963AF6A6CC6335ED8176A71BADF4771C7726D09E66A6BE4AB");
  // //BN_mod_exp(encrypted, m, e, n, ctx);
  // printBN("encrytped: ", encrypted);
  //
  // //Decrypt message using private key
  // //BN_hex2bn(&encrypted, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
  // BN_mod_exp(decrypted, encrypted, d, n, ctx);
  // printBN("decrypted: ", decrypted);

  //Question 3
  BIGNUM *p = BN_new();
  BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
  BIGNUM *q = BN_new();
  BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
  BN_mul(n, p, q, ctx);
  printf("Question 3.......\n");
  BN_hex2bn(&e, "0D88C3");
  BN_hex2bn(&m, "4d65657420617420313630302e20436f6d6520616c6f6e652e");
  printBN("original: ", m);
  BN_mod_exp(encrypted, m, e, n, ctx);
  printBN("Encrypted: ", encrypted);
  BN_mod_exp(decrypted, encrypted, d, n, ctx);
  printBN("Decrypted: ", decrypted);
}
