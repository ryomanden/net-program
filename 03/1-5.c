#include <stdio.h>

double mymean(double data[]){
  double result = 0;
  int i;
  for (i=0; i < 10; i++){
    result += data[i];
  }
  result = result / 10;
  return result;
}

int main(void) {
  double data[] = {38.1, 14.2, 51.3, 5.4, 12.5, 39.6, 27.7, 19.8, 81.9, 62.1};
  printf("%lf", mymean(data));
  return 0;
}
