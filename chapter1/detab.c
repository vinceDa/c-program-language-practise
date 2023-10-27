#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 4

void detab(int tabWidth);

int main() {
    detab(TAB_WIDTH);
}


void detab(int tabWidth) {
    int c, i, numSpaces;
    i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            numSpaces = tabWidth - (i % tabWidth);
            for (int j = 0; j < numSpaces; j++) {
                putchar(' ');
                i++;
            }
        } else if (c == '\n') {
            putchar(c);
            i = 0;
        } else {
            putchar(c);
            i++;
        }
    }
}