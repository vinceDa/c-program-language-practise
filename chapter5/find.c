#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char *line, int max);
/**
 * find -x -n 模式
 * 假定用-x（代表“除……之外”）表示打印所有与模式不匹配的文本行，用-n（代表“行号”）表示打印行号
 * 将打印所有与模式不匹配的行，并在每个打印行的前面加上行号。
 */
int main(int argc, char * argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except, number, found = 0;

    printf("%s%s\n", *++argv[0], (argc > 1) ? " " : "");
    while (--argc > 0 && (*++argv == '-')) {
        while (c = *++argv[0]) {
            switch (c) {
                case 'x':
                    except = 1;
                case 'n':
                    number = 1;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }

        if (argc != 1) {
            printf("Usage: find -x -n pattern\n");
        } else {
            while (getLine(line, MAXLINE) > 0) {
                lineno++;
                if ((strstr(line, *argv) != NULL) != except) {
                    if (number) {
                        printf("%ld:", lineno);
                    }
                    printf("%s", line);
                    found++;
                }
            }
        }
    }
    return found;
}

int getLine(char *line, int max) {
    int c, i;
    for (i = 0; i < max - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        *line++ = c;
    }
    if (c != '\n') {
        *line++ = c;
        i++;
    }
    *line = '\0';
    return i;
}
