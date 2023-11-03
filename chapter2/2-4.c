#include <stdio.h>
#include <limits.h>

char delSame(char s1[], char s2[]);
int getLen(char s[]);

/**
 * 练习2-4 squeeze(s1,s2)，将字符串s1中任何与字符串s2中字符匹配的字符都删除。
 */
int main() {
    printf("%c\n", delSame("abc", "cd"));
}

char delSame(char s1[], char s2[]) {
    int len = getLen(s1);
    char c[len];

    int i;
    for (i = 0; s1[i] != '\0' ; ++i) {
        int del = 0;
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                del = 1;
                break;
            }
        }
        if (del == 0) {
            c[i] = s1[i];
        }
    }
    c[i] = '\0';
    return c[len];

}

int getLen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}