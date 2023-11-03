#include <stdio.h>
#include <ctype.h>

/**
 * 练习5-6 采用指针而非数组索引方式改写前面章节和练习中的某些程序，例如getline(第1、4章)，atoi、itoa
 * 以及它们的变体形式（第2、3、4章)，reverse（第3章)，strindex、getop（第4章）等等。
 * @return
 */
int main() {
    int getLine(char *s, int limit);
    char s[100];
    getLine(s, 100);
    printf("%s\n", s);

}

int getLine(char *s, int limit) {
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
        i++;
    }
    *s = '\0';
    return i;
}
