#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int Bsearch( int data[], int size, int n );

void output( int data[], int size ) {
    int i;
    for( i = 0; i < size ; i++ ) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main(void){
    int data[SIZE];
    int size = SIZE;
    int seed, i, j, tmp, n, ans;

    /*--- データつくる ---*/
    printf("Seed?=");
    scanf("%d", &seed);
    srand(seed);
    for( i = 0; i < size ; i++ ){
        data[i] = rand()%100+1;
    }
    printf("Before: ");
    output( data, size ); /* 初期状態を表示 */
    
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
    
    printf("\nAfter : ");
    output( data, size ); /* ソート後の状態を表示 */
    printf("Search Number?:");
    scanf("%d", &n);
 
/* 二分探索を行うBsearch関数を呼び出し */
    ans = Bsearch( data, size, n );

    if( ans == -1 ){ /* 見つからなかったら-1 */
        printf("%d is not found.\n", n);
    }
        else{ /* 見つかったら配列の番号 */
        printf("%d is found in data[%d].\n", n, ans);
    }
    return 0; 
}

/* 第1引数:探索するデータ，第2引数:データの数，第3引数:探索対象の数字 */
int Bsearch( int data[], int size, int n ){
    int center, start = 0;
    while(start <= size){
        center = (start + size) / 2;
        if(data[center] == n){
            return center;
            break;
        }else if(data[center] > n){
            size = center - 1;
        }else{
            start = center + 1;
        }
    } 
    return -1;
}