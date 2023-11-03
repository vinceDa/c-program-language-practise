#include <stdio.h>
#include <ctype.h>
#define SIZE 10

//int afree(void);
//void alloc(int);

int main() {
    void strcopy(char *s, char *t);

    char *s = "ab";
    char *t = "cd";
    strcopy(s, t);
    printf("%c\n", *s);
    printf("%c\n", *t);


}

void strcopy(char *s, char *t) {
    while (*s++ = *t++) {
        ;
    }
}

#define ALLOCSIZE 10000
// buffer
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
// next free position in buf

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        printf("alloc: not enough\n");
        return 0;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}