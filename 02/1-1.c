#include <stdio.h>

int mymax(int data[]){
  int max = 0;
  int i;

  max = data[0];
  for(i = 0; i < 10; i++){
    if(data[i] > max){
      max = data[i];
    }
  }
  return max;
}

int main(void){
  int input[10] = {2,1,5,4,12,54213,22,16,9,21};
  int ans;

  ans = mymax(input);
  printf("max is %d", ans);

  return 0;
}
