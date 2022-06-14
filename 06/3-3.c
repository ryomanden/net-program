#include <stdio.h>
#include <stdlib.h>

struct PLAYER {
    int ENERGY, POISON;
}p;
struct MONSTER {
    int ENERGY;
}m;

int main(void) {
    /*--- seed setting ---*/
    int seed, cmd, X;
    printf("seed? >> ");
    scanf("%d", &seed);
    srand(seed);

    /*--- (A) player status setting ---*/
    p.ENERGY = 300;
    p.POISON = 0;

    /*--- (B) enemy status setting ---*/
    m.ENERGY =  rand() % 401 + 100;
    printf("\nA monster appears!");

    while(1) {
        /*--- (C) player status PRINT ---*/
        printf("\n\n--- Your status ---\n");
        printf("ENERGY: %d\nPOISON: %d\n", p.ENERGY, p.POISON);
        printf("-------------------\n");

        /*--- (D) player's turn ---*/
        printf("\nCommand? -> 1:Attack 2:Heal 3:Cure Poison\n>> ");
        scanf("%d", &cmd);

        switch(cmd){
            case 1:
                X = (rand() % 51 + 10);
                m.ENERGY -= X;
                printf("\nYou attacked! A monster received %d damage!\n", X);
                break;

            case 2:
                X = (rand() % 21 + 30);
                p.ENERGY += X;
                printf("\nYou recovered %d energy!\n", X);
                break;

            case 3:
                p.POISON = 0;
                printf("\nYour poison was cured!\n");
                break;

            default:
                printf("\nMiss!\n");
        }

        if(m.ENERGY <= 0) { //--------------------GAME CLEAR
            printf("\n\n....GAME CLEAR!....\n\n");
            break;
        }

        /*--- (E) enemy's turn ---*/
        X = (rand() % 41 + 10);
        p.ENERGY -= X;
        printf("A monster attacked! You received %d damage!", X);

        if(p.ENERGY <= 0) { //--------------------GAME OVER
        printf("\n\n....GAME OVER....\n\n");
        break;
        }

        /*--- (F) poison ---*/
        if((p.POISON == 0) && (rand() % 100) < 5) {
            p.POISON = 1;
            printf("You were affected by the poison!\n");
            p.ENERGY = p.ENERGY * 0.95;
            printf("Your energy was decreased 5 percent by the poison!\n");

        }else if(p.POISON == 1) {
            p.ENERGY = p.ENERGY * 0.95;
            printf("Your energy was decreased 5 percent by the poison!\n");
            
        }

        if(p.ENERGY <= 0) { //--------------------GAME OVER 
            printf("\n\n....GAME OVER....\n\n");
            break;
        }
    }

}