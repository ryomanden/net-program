#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fortune(int seed) {
    int a;
    srand(seed);
    a = rand() % 100;

    if(a < 10){
        return 0;
    }else if(a < 30){
        return 1;
    
    }else if(a < 65){
        return 2;
    
    }else if(a < 90){
        return 3;
    
    }else{
        return 4;

    }
}

int main(void) {
    int seed, tmp;
    printf("seed> ");
    scanf("%d", &seed);
    
    switch(fortune(seed)){
        case 0:
            printf("Worst luck");
            break;

        case 1:
            printf("Bad luck");
            break;
    
        case 2:
            printf("Good luck");
            break;

        case 3:
            printf("Better luck");
            break;
        
        case 4:
            printf("Excellent luck");
            break;

        default:
            printf("error");
            break;
    }
    printf("\n");

    return 0;
}