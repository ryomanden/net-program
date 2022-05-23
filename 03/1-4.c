#include <stdio.h>

int main(void){
  int input = 0;
  printf("Pls input: ");
  scanf("%d", &input);

  if (input % 4 == 0){
    if (input % 100 == 0) {
      if (input % 400 == 0) {
        printf("%d -> Uruu desu", input);
      }else{
        printf("%d -> Not Uruu desu", input);
      }
    }else{
      printf("%d -> Uruu desu", input);
    }
  }else{
    printf("%d -> Not Uruu desu", input);
  }
  return 0;
}
