#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000
#define TAB_WIDTH 4

void htoi();
int getLine(char s[], int limit);
void copy(char to[], char from[]);
int getPow(int base, int index);

/**
 * 练习2-3 编写函数htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀 Ox 或 0x）转换为与之等价的整型值。
 * 字符串中允许包含的数字包括：0~9、a~f以及A～F。
 */
int main() {
    int c;
    while ((c = getchar()) != EOF) {
        htoi();
    }
}


void htoi() {
    int i = 0;
    char s[100];
    int len = getLine(s, 100);
    char t[100];
//    copy(t, s);

    if (len == 2) {
        putchar(s[0]);
        return;
    }

    int res = 0;
    int index = 0;
    for (int j = len - 2; j >= 0; --j) {
        if (s[j] == 'x' || s[j] == 'X') {
            break;
        }

        int cur = 0;
        if (s[j] >= 'a' && s[j] <= 'f') {
            cur = s[j] - 'a' + 10;
        } else if (s[j] >= 'A' && s[j] <= 'F') {
            cur = s[j] - 'A' + 10;
        } else if (s[j] >= '0' && s[j] <= '9') {
            cur = s[j] - '0';
        }
        res += cur * getPow(16, index++);
    }
    printf("%d\n", res);
}

int getPow(int base, int index) {
    if (index == 0) {
        return 1;
    }

    int res = 1;
    for (int i = 0; i < index; i++) {
        res *= base;
    }
    return res;
}

int getLine(char s[], int limit) {
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char dest[]) {
    int i = 0;
    while ((to[i] = dest[i]) != '\0') {
        i++;
    }
}