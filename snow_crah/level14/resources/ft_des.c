#include <stdio.h>
#include <string.h>
char * ft_des(char *plain)
{
  char *cypher;
  size_t i;
  size_t j;
  size_t len;
  
  j = 0;
  i = 0;
  len = strlen(plain);
  cypher = plain;
  while( 1 ){
    
    if (len <= i)
      return cypher;

    j %= 6;

    if ((i & 1) == 0) {
      for (int k = 0; k < "0123456"[j]; k++) {
        cypher[i]--;
        if (cypher[i] == 31)
          cypher[i] = 126;
      }
    }
    else {
      for (int k = 0; k < "0123456"[j]; k++) {
        cypher[i]++;
        if (cypher[i] == 127)
          cypher[i] = 32;
      }
    }
    i++;
    j++;
  }
}

int main(int argc, char* argv[])
{
    char* cypher = ft_des(argv[1]);
    printf("%s\n", cypher);
    return 0;
}

