#include <stdio.h>

int main() {
    unsigned int target;
    char buff[26] = "abcdefghijklmnopqrstuvwxyz";
    size_t pos = 26;
    int i;
    target = ((int)buff[3] ^ 0x1337U) + 0x5eeded;
      for (i = 0; i < (int)pos; i++)
      {
        if (buff[i] < ' ')
          return 1;
        target += ((int)buff[i] ^ target) % 1337;
      }
      printf("%u", target);

    return 0;
}