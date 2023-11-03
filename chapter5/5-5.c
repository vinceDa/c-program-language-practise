#include <stdio.h>
#include <ctype.h>
/**
 *  练习5-5 实现库函数 strncpy、 strncat 和 strncmp，它们最多对参数字符串中的前 n个字符进行操作。
 *  例如，函数 strncpy(s, t， n)将t中最多前n个字符复制到s中。更详细的说明请参见附录 B。
 * @return
 */
int main() {
    void strncat(char *s, char *t,int n);
    void strncopy(char *s, char *t,int n);
    int strncmp(char *s, char *t,int n);
    char s[100] = "abc";
    char *t = "def";
    strncat(s, t, 2);
    printf("%s\n", s);

    char s1[100] = "abc";
    char *t1 = "def";
    strncopy(s1, t1, 2);
    printf("%s\n", s1);

    char s2[100] = "abcdefg";
    char *t2 = "efc";
    printf("%d\n", strncmp(s2, t2, 2));

}

void strncopy(char *s, char *t,int n) {
    while (*t && n > 0) {
        *s = *t;
        s++;
        t++;
        n--;
    }
    *s = '\0';
}

void strncat(char *s, char *t,int n) {
    while (*s) {
        s++;
    }
    while (*t && n > 0) {
        *s = *t;
        s++;
        t++;
        n--;
    }
}

int strncmp(char *s, char *t,int n) {
    char *s_end = s;
    char *t_end = t;

    int tlen = 1;
    while (*s_end++) {

    }
    while (*t_end++) {
        tlen++;
    }

    while (tlen-- >= n) {
        t_end--;
        s_end--;
    }

    while (t_end >= t && s_end >= s) {
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
