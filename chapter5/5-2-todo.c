#include <stdio.h>
#include <ctype.h>
#define SIZE 10

/**
 *
 * 练习 5-2 模仿函数 getint 的实现方法，编写一个读取浮点数的函数 getfloat。
 * getfloat 函数的返回值应该是什么类型？
 */
int main() {
    void strcat(char *s, char *t);
    char *s = "abc";
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
}
