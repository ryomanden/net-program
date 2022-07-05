#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

void output( int data[], int size ){
    int i;
    for( i = 0; i < size ; i++ ){
       printf("%d ", data[i]);
    }
    printf("\n");
}
int main(void){

    unsigned long int start; /* 実行前の時間(ミリ秒)*/
    unsigned long int end; /* 実行後の時間(ミリ秒)*/
    unsigned long int elapsed; /* 実行時間(ミリ秒)*/
    
    /*--- 宣言 ---*/
    int* data;
    int size = SIZE;
    int i, j, tmp, seed;

    /*--- CSV ---*/
    FILE *fp;
    fp = fopen("./b_result.csv", "w");
    if(fp == NULL) {
        printf( "File open ERROR Deesu" );
        return -1;
    }

    fprintf(fp, "data,number,time(1/%lu[s])\n",CLOCKS_PER_SEC);

    printf("\n %lu \n", CLOCKS_PER_SEC);

    printf("Seed?=");
    scanf("%d", &seed);
    srand(seed);
    for(int all = 0; all < 10; all++) {

        for(int loop = 0; loop < 10; loop++) {

            /*--- データつくる ---*/
            data = (int*)malloc(sizeof(int) * size);    
            for( i = 0; i < size ; i++ ){
                data[i] = rand()%100+1;
            }

            start = clock(); /* 処理前の時間を取得 */

            /* bubble sort */
            for(i = 0; i < (size-1); i ++) {
                for(j = (size-1); j > i; j--) {
                    if(data[j] < data[j-1]) {
                        tmp = data[j];
                        data[j] = data[j-1];
                        data[j-1] = tmp;
                    }
                }
            }

            end = clock(); /* 処理後の時間を取得 */
            elapsed = end - start; /* 実行時間算出 */
            printf("ELAPSED TIME %d: %lu\n", (loop+1), elapsed);
            
            free(data);
        }
        fprintf(fp, "%d,%d,%lu\n", size, (loop+1), elapsed);
        free(data);
        size += SIZE;
        printf("\n--------\n");
    }
    fclose(fp);
    return 0; 
}