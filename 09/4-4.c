#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
void output( int data[], int size ) {
    int i;
    for( i = 0; i < size ; i++ ) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
int main(void) {
    int data[SIZE];
    int size = SIZE;
    int seed, tmp, i, j;
    printf("Seed?=");
    scanf("%d", &seed);
    srand(seed);
    for( i = 0; i < size ; i++ ) {
        data[i] = rand()%100+1;
    }
    output( data, size ); /* 初期状態を表示 */
    
    for( i = 1; i < size; i++ ) {
        tmp = data[i];

        for( j = (i-1); j >= 0; j-- ) {

            if( data[j] > tmp ) {
                data[j+1] = data[j];
            }else{
                break;
            }
        }

        data[j+1] = tmp;
    }

    output( data, size ); /* ソート後の状態を表示 */
    return 0;
}