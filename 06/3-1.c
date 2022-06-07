#include <stdio.h>
struct gakuseki{
    int gakuban, math, eng, phy;
    float heikin;
};

int main(void) {
    struct gakuseki ns_2nen[3];

    for(int i = 0; i < 3; i++) {
        printf("\nGakuban %d : ", i+1);
        scanf("%d", &ns_2nen[i].gakuban);

        printf("Math %d    : ", i+1);
        scanf("%d", &ns_2nen[i].math);

        printf("English %d : ", i+1);
        scanf("%d", &ns_2nen[i].eng);

        printf("Physics %d : ", i+1);
        scanf("%d", &ns_2nen[i].phy);

        ns_2nen[i].heikin = ((float)ns_2nen[i].math + (float)ns_2nen[i].eng + (float)ns_2nen[i].phy)/3;
    }

    printf("\n--- Heikin ---\n");
    for(int i = 0; i < 3; i++) {
        printf("%d : ", ns_2nen[i].gakuban);
        printf("%f\n", ns_2nen[i].heikin);
    }
    return 0;
}