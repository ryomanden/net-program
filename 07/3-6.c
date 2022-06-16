#include <stdio.h>
struct gakuseki{
    int gakuban, math, eng, phy;
};

int Bsearch(int size, int n );

int main(){
    int a, n;
    float heikin;
    int size = 20;// <------
    struct gakuseki ns_2nen[size];

    /* open file */
    FILE *fp;
    fp = fopen("./gakusei.win.txt","r");

    /* file error */
    if(fp == NULL){
        fprintf(stderr, "File ERROR\n");
        return -1;
    }

    /* input structure from file */
    for(int i = 0; i < size; i++){
        fscanf(fp, "%d", &ns_2nen[i].gakuban);
        fscanf(fp, "%d", &ns_2nen[i].math);
        fscanf(fp, "%d", &ns_2nen[i].eng);
        fscanf(fp, "%d", &ns_2nen[i].phy);
    }
    fclose(fp);

    /* scan GAKUBAN */
    printf("Search Gakuban?:");
    scanf("%d", &n);

    /* search GAKUBAN */
    int center, start = 0;
    while(start <= size){
        center = (start + size) / 2;
        if(ns_2nen[center].gakuban == n){
            a = center;
            break;
        }else if(ns_2nen[center].gakuban > n){
            size = center - 1;
        }else{
            start = center + 1;
        }
    } 
    /* calc average */
    heikin = ((float)ns_2nen[a].math + (float)ns_2nen[a].eng + (float)ns_2nen[a].phy)/3;

    /* output result */
    if(ns_2nen[a].gakuban == n){
        printf("Heikin = %f", heikin);
    }
    else{
        printf("%d is not found.\n", n);
    }
}
    

