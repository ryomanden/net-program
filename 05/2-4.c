#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[] = "Chiba Institute";
    char str2[] = "Technology";
    char str3[30];
    char str4[30];

    /*--- strcat ---*/
    strcat(str3,str1);
    strcat(str3," of ");
    strcat(str3,str2);
    printf("%s",str3);

    /*--- sprintf ---*/
    sprintf(str4, "%s of %s", str1, str2);
    printf("\n%s\n", str4);

    return 0;
}