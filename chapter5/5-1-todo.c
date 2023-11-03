#include <stdio.h>
#include <ctype.h>
#define SIZE 10

int getch(void);
void ungetch(int);

/**
 * 练习 5-1 在上面的例子中，如果符号+或-的后面紧跟的不是数字，getint 函数将把符号视为数字◎的有效表达方式。
 * 修改该函数，将这种形式的+或-符号重新写回到输入流中。
 * @return
 */
int main() {
    int n[10] = {1, 5 , 7, 3 ,4, 6, 8, 9, 1, 9};
    int *pa = &n[0];
    printf("%d\n", *pa++);
    printf("%d\n", *(pa + 1));
    printf("%d\n", *(pa + 2));
    printf("%d\n", *(pa + 3));
    printf("%d\n", *(pa + 4));
    void getp(int *);
    getp(n);

    int strlen(char *s);
    printf("%d\n", strlen("dsa1xx"));
}

int strlen(char *s) {
    int i;
    for (i = 0; *s != '\0' ; s++) {
        i++;
    }
    return i;
}

void getp(int *p) {
    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
}

int getint(int *pn) {
    int c, sign;

    // skip space
    while (isspace(c = getch())) {
        ;
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;

}


#define BUFSIZE 100
// buffer for ungetch
char allocbuf[BUFSIZE];
// next free position in buf
int bufp = 0;
int getch(void ) {
    return (bufp > 0) ? allocbuf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        allocbuf[bufp++] = c;
    }
}