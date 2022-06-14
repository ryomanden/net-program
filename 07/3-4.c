#include <stdio.h>
/* 関数のプロトタイプ宣言(ここは変更しないこと) */ 
int Lsearch( int data[], int size, int n );
void output( int n, int ans );

int main(void){
    int data[] = { 4, 2, 8, 9, 5, 3, 6, 1, 7 };
    int size = sizeof(data) / sizeof(int);
    int n;
    int ans;

    printf("Search Number?:");
    scanf("%d", &n);

    /* 線形探索を行うLsearch関数を呼び出し */
    ans = Lsearch( data, size, n );

    output( n, ans );
    return 0; 
}

/* この関数を完成させてください */
/* 第1引数:探索するデータ，第2引数:データの数，第3引数:探索対象の数字 */
int Lsearch( int data[], int size, int n ){
    for(int i = 0; i < size; i++){
        if(data[i] == n){
            return i;
            break;
        }
    }
    return -1;
}

/* 配布資料の13ページで宣言されているoutput関数をコピーしてください */
void output( int n, int ans ){
    if( ans == -1 ){ /* 見つからなかったら-1 */
        printf("%d is not found.\n", n);
    }
    else{ /* 見つかったら配列の番号 */
        printf("%d is found in data[%d].\n", n, ans);
    }
}