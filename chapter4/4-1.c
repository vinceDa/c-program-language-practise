#include <stdio.h>

int strindex(char s[], char t[]);

/**
 * 练习4-1 编写函数 strindex (s, t)， 它返回字符串t在s中最右边出现的位置。
 * 如果s中不包含t，则返回-1.
 */
int main() {
    printf("%d\n", strindex("abcedabcx", "abcx"));

}

int strindex(char s[], char t[]) {
    for (int i = 0; s[i] != '\0'; ++i) {
        int contains = 1;
        int x = i;
        for (int j = 0; t[j] != '\0'; ++j) {
            if (s[x++] != t[j]) {
                contains = 0;
                break;
            }
        }
        if (contains == 1) {
            return i;
        }
    }
    return -1;
}