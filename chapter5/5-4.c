#include <stdio.h>
#include <ctype.h>
#define SIZE 10

/**
 * 练习5-4 编写函数 strend(s, t)。
 * 如果字符串t 出现在字符串s 的尾部，该函数返回1；否则返回0。
 * @return
 */
int main() {
    int strend(char *s, char *t);
    char *s = "abcdef";
    char *t = "def";

    printf("%d\n", strend(s, t));

}

int strend(char *s, char *t) {
    char *s_end = s;
    char *t_end = t;
    while (*s_end) {
        s_end++;
    }
    while (*t_end) {
        t_end++;
    }
    while (s_end >= s && t_end >= t) {
        if (*s_end != *t_end) {
            return 0;
        }
        s_end--;
        t_end--;
    }

    if (t_end < t) {
        return 1;
    }

    return 0;
}
