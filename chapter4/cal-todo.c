#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int getop(char []);

void push(double);

double pop(void);

int sp = 0;
double val[MAXVAL];

/**
 * 逆波兰计算器 4-x 练习题
 */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
                // - 和 / 不满足交换律, 所以需要自行处理两个pop, 避免编译器的差距导致两个pop()顺序不同导致的结果不同
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    if (op2 > 0.0) {
                        push((int)pop() % (int)op2);
                    } else {
                        push(((int)pop() % (int)op2 + (int)op2) % (int)op2);
                    }
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s \n", s);
                break;
        }
    }
    return 0;
}

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty, can't pop\n");
        return 0.0;
    }
}

double peek() {
    if (sp >= 0) {
        return val[sp - 1];
    } else {
        printf("error: stack empty, can't pop\n");
        return 0.0;
    }
}

void clear() {
    sp = 0;
}


int getch(void );
void ungetch(int );

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';

    // is not a number
    if (!isdigit(c) && c != '.') {
        return c;
    }

    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100
// buffer for ungetch
char buf[BUFSIZE];
// next free position in buf
int bufp = 0;

int getch(void ) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

