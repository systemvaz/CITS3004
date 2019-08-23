//You can modify the below code to get started, or you are welcome to write from scratch

#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char wordx[16];

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

void KeyGen(char* in, char* out)
{
	int i = 0;
	char* temp = malloc(16);
  memcpy(temp,in,strlen(in));
  i = strlen(in);

  while (i < 16)
  {
      temp[i] = 0x20;
      i++;
  }
  memcpy(out,temp,16);
}

int main()
{
	FILE *f_input;
	f_input = fopen("rockyou.txt", "r");
	char plaintext[21] = "This is a top secret.";
	char cyphertext[] = {0x8d, 0x20, 0xe5, 0x05, 0x6a, 0x8d, 0x24, 0xd0,
											 0x46, 0x2c, 0xe7, 0x4e, 0x49, 0x04, 0xc1, 0xb5,
											 0x13, 0xe1, 0x0d, 0x1d, 0xf4, 0xa2, 0xef, 0x2a,
											 0xd4, 0x54, 0x0f, 0xae, 0x1c, 0xa0, 0xaa, 0xf9};

	char iv[8];
  memset(iv, 0x00, 8);
	char decrypted[200];
	char word[16];

	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	EVP_CIPHER_CTX_init(ctx);

	while (fgets(word, 16, f_input) != NULL)
	{
		int outlen, tmplen;
		strtok(word, "\n");
    KeyGen(word, wordx);
    printf("trying key: ");

    for (int i = 0; i < 16; i++)
    {
      printf("%x", wordx[i]);
    }
    printf("\n");

		EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, wordx, iv);

		if(!EVP_DecryptUpdate(ctx, decrypted, &outlen, cyphertext, 32))
		{
			printf("EVP_DecryptUpdate\n");
			handleErrors();
		}

		EVP_DecryptFinal_ex(ctx, decrypted + outlen, &tmplen);

    if(strstr(decrypted, "This") != NULL)
    {
      printf("Found!\n");
      printf("pwd: %s\n", word);
      printf("%s\n", decrypted);
      break;
    }
    memset(decrypted, 0, 200);
		EVP_CIPHER_CTX_cleanup(ctx);
	}

	return 0;
}
