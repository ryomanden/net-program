#include <stdio.h>

/* Calculate minimum value */
int mymin(int data[]){
  int min = 0;
  int i;

  min = data[0];
  for(i = 0; i <10; i++){
    if(data[i] < min){
      min = data[i];
    }
  }
  return min;
}

/* Calculate max value */
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

/* Calculate Sum */
int mysum(int data[]){
  int sum = 0;
  int i;

  for(i = 0; i < 10; i++){
    sum += data[i];
  }

  return sum;
}

int main(void){
  int input[10] = {2,1,5,4,12,54213,22,16,9,21};

  printf("min is %d\n", mymin(input));
  printf("max is %d\n", mymax(input));
  printf("sum is %d\n", mysum(input));

  return 0;
}
