#include <stdio.h>
#include <limits.h>

void toLower(char s1[]);

/**
 * 练习2-10 重新编写将大写字母转换为小写字母的函数lower,
 * 并用条件表达式替代其中的if-else 结构。
 */
int main() {
    char s[] = "AISOAX";
    toLower(s);
    printf("%s\n", s);
}

void toLower(char s[]) {
    int i;
    for (i = 0; s[i] != '\0' ; ++i) {
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 'a' : s[i];
    }
}