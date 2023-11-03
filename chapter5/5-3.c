#include <stdio.h>
#include <ctype.h>
#define SIZE 10

/**
 * 练习 5-3 用指针方式实现第2章中的函数 strcat。
 * 函数 strcat(s,t)将t指向的字符串复制到§指向的字符串的尾部。
 * @return
 */
int main() {
    void strcat(char *s, char *t);
    char s[100] = "abc";
    char *t = "def";
    strcat(s, t);

    printf("%s\n", s);
    printf("%s\n", t);

}

void strcat(char *s, char *t) {
    while (*s) {
        s++;
    }
    while (*t) {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}
