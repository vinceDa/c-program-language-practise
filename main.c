#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000

void fahr2Celsius(float fahr);
void celsius2Fahr(float celsius);
void getCharEOF();
void wc();
void getChar();
int getLine(char line[], int maxline);
void copy(char to[], char from[], int i);

int main() {
//    for (int fahr = 0; fahr <= 300; fahr += 20) {
//        fahr2Celsius(fahr);
//    }
//
//    celsius2Fahr(1.0f);
//    getChar();
//    getCharEOF();
//    wc();
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 0) {
//            max = len;
//            copy(longest, line);
            printf("%s", line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }
    return 0;

}

void celsius2Fahr(float celsius) {
    printf("%f\t%f\n", celsius * 9.0 / 5.0 + 32.0, celsius);
}

void fahr2Celsius(float fahr) {
    printf("%f\t%f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}

void getChar() {
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

void getCharEOF() {
    int c;

    c = getchar();

    printf("%d\n", c != EOF);

    printf("%d", EOF);

}

void wc() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}


int getLine(char s[], int lim) {
    int c, i;

    int start = -1;
    int end = -1;
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n'; ++i) {
        if (c != ' ' && start == -1) {
            start = i;
        }
        if (c == ' ' && end == -1) {
            end = i;
        } else if (c != ' ' && c != '\n') {
            end = -1;
        }
        s[i] = c;
    }
    if (c == '\n') {
        if (end != -1) {
            int x = end + 1;
            while (x <= i) {
                s[x] = '\0';
                x++;
            }
            i = end;
            s[i] = c;
        } else {
            s[i] = c;
            ++i;
            end = i;
        }

        if (start != -1) {
            for (int j = 0; j < end - start; ++j) {
                s[j] = s[j + start];
            }
        }

    }
    s[i] = '\0';
    return i;
}
void copy(char to[], char from[], int i) {
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
