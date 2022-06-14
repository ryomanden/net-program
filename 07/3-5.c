#include <stdio.h>
/* 関数のプロトタイプ宣言(ここは変更しないこと) */
int Bsearch( int data[], int size, int n );
void output( int n, int ans );
int main(void){
    int data[] = { 4, 6, 9, 10, 11, 14, 17, 19, 21, 26 };
    int size = sizeof(data) / sizeof(int);
    int n;
    int ans;
    printf("Search Number?:");
    scanf("%d", &n);
 
/* 二分探索を行うBsearch関数を呼び出し */
    ans = Bsearch( data, size, n );
    output( n, ans );
    return 0;
}
/* この関数を完成させてください */
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
/* 配布資料の13ページで宣言されているoutput関数を再利用してください */
void output( int n, int ans ){
    if( ans == -1 ){ /* 見つからなかったら-1 */
          printf("%d is not found.\n", n);
      }
    else{ /* 見つかったら配列の番号 */
        printf("%d is found in data[%d].\n", n, ans);
    }
}