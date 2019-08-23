#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM *a)
{
  char *number_str = BN_bn2dec(a);
  printf("%s %s\n", msg, number_str);
  OPENSSL_free(number_str);
}
int main()
{
  BN_CTX *ctx = BN_CTX_new();

  BIGNUM *g = BN_new();
  BIGNUM *p = BN_new();
  BIGNUM *a = BN_new();
  BIGNUM *b = BN_new();
  BIGNUM *fromalice = BN_new();
  BIGNUM *frombob = BN_new();

  BN_dec2bn(&g, "2879");
  BN_dec2bn(&p, "9929");
  BN_dec2bn(&a, "9");
  BN_dec2bn(&b, "6");

  BN_mod_exp(fromalice, g, a, p, ctx);
  BN_mod_exp(frombob, g, b, p, ctx);

  BIGNUM *s = BN_new();
  BN_mod_exp(s, frombob, a, p, ctx);
  printBN("Alice calculates from Bob: ", s);
  BN_mod_exp(s, fromalice, b, p, ctx);
  printBN("Bob calculates from Alice: ", s);

  //MITM attach with Eve
  BIGNUM *e = BN_new();
  BIGNUM *fromeve = BN_new();
  BN_dec2bn(&e, "5");
  //Between Alice...
  BN_mod_exp(fromalice, g, a, p, ctx);
  BN_mod_exp(fromeve, g, e, p, ctx);
  BN_mod_exp(s, fromeve, a, p, ctx);
  printBN("Alice caluclates from Eve: ", s);
  BN_mod_exp(s, fromalice, e, p, ctx);
  printBN("Eve calculates from Alice: ", s);
  //Between Bob
  BN_mod_exp(frombob, g, b, p, ctx);
  BN_mod_exp(s, fromeve, b, p, ctx);
  printBN("Bob calculates from Eve: ", s);
  BN_mod_exp(s, frombob, e, p, ctx);
  printBN("Eve caluclates from Bob: ", s);
}
