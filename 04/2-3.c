#include <stdio.h>
#include <string.h>

int main(void){
  char typing[32];
  char data[3][32] = {"apple","banana","orange"};

  for (int i = 0; i < 3; i++) {
    printf("--- %s ---\n", data[i]);
    while (1) {
      scanf("%s",typing);
      strcmp(data[i], typing);
      if (strcmp(data[i], typing) == 0) {
        printf(">>OK\n\n");
        break;
      }else{
        printf(">>MISS\n");
      }
    }
  }
}
