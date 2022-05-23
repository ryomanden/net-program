#include <stdio.h>
#include <string.h>

int main() {
  FILE *ascii;
  ascii = fopen("./ascii_art.txt", "r");

  /* error */
  if(ascii == NULL){
    fprintf(stderr, "Cannot open file\n");
    return -1;
  }

  /* print ascii-art */
  int ch;
  int i = 1;
  while (1) {
    ch = fgetc(ascii);
    if (ch == EOF){
      break;
    }

    printf("%c", ch);
    if (i == 64){
      printf("\n");
      i = 0;
    }
    i++;
  }
  fclose(ascii);
  return 0;
}
