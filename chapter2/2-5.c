#include <stdio.h>
#include <limits.h>

int findFirst(char s1[], char s2[]);
int getLen(char s[]);

/**
 * 练习2-5 编写函数 any (s1,s2)，将字符串 s2 中的任一字符在字符串 s1 中第一次出现的位置作为结果返回。
 * 如果 s1中不包含s2 中的字符，则返回-1。
 * (标准库函数 strpbrk具有同样的功能，但它返回的是指向该位置的指针。）
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