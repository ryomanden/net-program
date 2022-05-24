#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fortune(int seed) {
    int a;
    srand(seed);
    a = rand() % 100;
    return a;
}

int main(void) {
    int seed, tmp;
    printf("seed> ");
    scanf("%d", &seed);
    
    if(fortune(seed) < 10){
        printf("Worst luck");

    }else if(fortune(seed) < 30){
        printf("Bad luck");
    
    }else if(fortune(seed) < 65){
        printf("Good luck");
    
    }else if(fortune(seed) < 90){
        printf("Better luck");
    
    }else{
        printf("Excellent luck");
    
    }

    return 0;
}