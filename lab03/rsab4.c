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
  BIGNUM *m = BN_new();
  BIGNUM *sm = BN_new();
  BIGNUM *vm = BN_new();

  BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
  BN_hex2bn(&e, "010001");
  BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
  BN_hex2bn(&m, "49206f776520796f75202432303030");

  //Sign message
  BN_mod_exp(sm, m, d, n, ctx);
  printBN("signature: ", sm);
  //Verify message
  BN_mod_exp(vm, sm, e, n, ctx);
  printBN("original: ", m);
  printBN("  verify: ", vm);
  //Change Message
  BN_hex2bn(&m, "49206f776520796f75202433303030");
  BN_mod_exp(sm, m, d, n, ctx);
  BN_mod_exp(vm, sm, e, n, ctx);
  printBN("  verify: ", vm);

  //Question 10
  BN_hex2bn(&sm, "345B2AD16ED459EC90E92C4402384CF126CEE0693DB3CEAA5E1165CC02FA4F0F");
  BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
  BN_hex2bn(&e, "010001");
  BN_mod_exp(vm, sm, e, n, ctx);
  printf("Question 10....\n");
  printBN("Message: ", vm);

  printf("Exercise 1B5....\n");
  BN_hex2bn(&m, "4c61756e63682061206d697373696c652e");
  BN_hex2bn(&sm, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
  BN_hex2bn(&e, "010001");
  BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
  BN_mod_exp(vm, sm, e, n, ctx);
  printBN("original: ", m);
  printBN("  Verify: ", vm);
}
