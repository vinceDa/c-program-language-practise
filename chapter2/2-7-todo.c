#include <stdio.h>
#include <limits.h>

int findFirst(char s1[], char s2[]);
int getLen(char s[]);

/**
 * 练习2-7 编写一个函数 invert(x，p，n)，该函数返回对x执行下列操作后的结果值：
 * 将x中从第p位开始的n个（二进制）位求反（即，1变成0，0变成1)，x的其余各位保持不变。
 */
int main() {
    printf("%d\n", findFirst( "abadeq", "h"));
}

int findFirst(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' ; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;

}