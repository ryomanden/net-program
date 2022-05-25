#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void myver(double data[], int end) {
    double ave, sigma = 0;

    /*--- calculate average ---*/
    for (int i = 0; i < end; i++) {
        ave += data[i];
    }
    ave = ave / end;

    /*--- calculate sigma ---*/
    for (int i = 0; i < end; i++) {
        sigma += (data[i] - ave);
        sigma = pow(sigma,2);
    }

    sigma = sigma / end;
    return sigma;
}

int main(){
    double *data;
    int end;
    FILE *fp;

    fp = fopen("./data.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file\n");
        return -1;
    }
    fclose(fp);

    fscanf(fp, "%d", &end);
    data = (double *)malloc(sizeof(double)*end);
    for(int i = 0, i < end, i++) {
        fscanf(fp, "%lf", data[i]);
    }

    /*--- output ---*/
    printf("%lf", myver(data, end));

    free(data);
    return 0;
}
