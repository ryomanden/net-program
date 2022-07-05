#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1500

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
    unsigned long int average;

    /*--- CSV ---*/
    FILE *fp;
    fp = fopen("./b_result.csv", "w");
    if(fp == NULL) {
        printf( "File open ERROR Deesu" );
        return -1;
    }
    /*--- TABLE NAME ---*/
    fprintf(fp, "Number of sorts,1/%lu[s]\n",CLOCKS_PER_SEC);

    printf("%lu Clocks per sec\n", CLOCKS_PER_SEC);

    /*--- Set SEED ---*/
    printf("Seed?=");
    scanf("%d", &seed);
    srand(seed);

    for(int all = 0; all < 10; all++) {
        average = 0;
        printf("---- data size = %d\n", size);
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
            
            average += elapsed;

            free(data); /*--- 配列けす ---*/
        }

        /*--- Calc Average && Push to CSV ---*/
        average = average / 10;
        fprintf(fp, "%d,%lu\n", size, average);
        
        size += SIZE;
    }
    fclose(fp);
    return 0; 
}