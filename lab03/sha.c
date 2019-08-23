#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
  unsigned char msg[] = "361448504617";
  //unsigned char msg[] = "361448502791";
  unsigned char *md;
  int len = strlen(msg);

  SHA_CTX ctx;

  SHA1_Init(&ctx);
  SHA1_Update(&ctx, msg, len);
  SHA1_Final(md, &ctx);

  len = strlen(md) - 2;
  for(int i = 0; i < len; i++)
  {
    printf("%x", md[i]);
  }
  printf("\n");
}
