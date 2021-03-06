#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2000
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
    
    int data[SIZE];
    int size = SIZE;
    int i, j, tmp;
    tmp = 2000;

    printf("<--- BUBBLE SORT --->\n");
    for(int loop = 0; loop < 10; loop++) {
        /*--- DAINYU- ---*/
        for( i = 0; i < size ; i++ ){
            data[i] = tmp;
            tmp--;
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
    }
    return 0; 
}