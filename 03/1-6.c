#include <stdio.h>
#include <math.h>

void hensachi(double data[]){
  double ave, sigma, stddev, dev = 0;
  char name[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

  /*--- calculate average ---*/
  for (int i = 0; i < 10; i++) {
    ave += data[i];
  }
  ave = ave / 10;

  /*--- calculate sigma ---*/
  for (int i = 0; i < 10; i++) {
    sigma += (data[i] - ave)*(data[i] - ave);
  }

  /*--- calculate route ---*/
  stddev = sqrt(sigma/10);

  /*--- calculate dev ---*/
  for (int i = 0; i < 10; i++) {
    dev = ((data[i] - ave) / stddev) * 10 + 50;
    printf("%c = %f\n", name[i], dev);
  }
}
int main(void) {
  double data[] = {59, 72, 98, 77, 85, 86, 34, 84, 61, 45};
  hensachi(data);
  return 0;
}
