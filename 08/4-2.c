#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
void output( int data[], int size ){
    int i;
    for( i = 0; i < size ; i++ ){
       printf("%d ", data[i]);
    }
    printf("\n");
}
int main(void){
    
    int data[SIZE];
    int size = SIZE;
    int seed, i, j, tmp, min, k;
    printf("Seed?=");
    scanf("%d", &seed);
    srand(seed);
    for( i = 0; i < size ; i++ ){
        data[i] = rand()%100+1;
    }
    printf("Before: ");
    output( data, size ); /* 初期状態を表示 */

    /* select sort */
    for(i=0; i < (size-1); i++) {
        min = data[i];
        k = i;
        for(j = (i+1); j < size; j++) {
            if(min > data[j]) {
                min = data[j];
                k = j;
            }
        }
        tmp = data[i];
        data[i] = data[k];
        data[k] = tmp;
    }
    printf("\nAfter : ");
    output( data, size ); /* ソート後の状態を表示 */
    return 0; 
}