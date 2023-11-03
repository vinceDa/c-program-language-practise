#include <stdio.h>
#include <limits.h>

int findFirst(char s1[], char s2[]);
int getLen(char s[]);

/**
 * 练习2-8 编写一个函数 rightrot(x，n)，该函数返回将x循环右移（
 * 即从最右端移出的位将从最左端移入）n（二进制）位后所得到的值。
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