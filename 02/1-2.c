#include <stdio.h>

int mysum(int data[]){
  int sum = 0;
  int i;

  for(i = 0; i < 10; i++){
    sum += data[i];
  }

  return sum;
}

int main(void) {
  int ans = 0;
  int input[10] = {2,1,3,53,21,6753,42,257,32,98};

  ans = mysum(input);
  printf("sum is %d", ans);

  return 0;
}
