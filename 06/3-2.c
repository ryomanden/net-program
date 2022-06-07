#include <stdio.h>

int main() {
    int a, b, r;
    
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    if(a < b) {
        printf("\nERROR.");
        return -1;
    }else{
        while(1) {
            r = a % b;
            if(r == 0) {
                break;
            }
            a = b;
            b = r;
        }
        printf("\nGCD = %d", b);
        return 0;
    }
}