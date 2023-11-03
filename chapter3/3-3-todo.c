#include <stdio.h>
#include <limits.h>

void escape(char s[], char t[]);

void unescape(char s[], char t[]);

/**
 * 练习3-3  编写函数 expand (sl,s2)，将字符串s1 中类似于a-z一类的速记符号
 * 在字符串s2中扩展为等价的完整列表 abe..xyz。该函数可以处理大小写字母和数字，
 * 并可以处理a-b-c、a-z0-9 与-a-z 等类似的情况。作为前导和尾随的-字符原样排印。
 */
int main() {
    char s[100];
    char t[] = "Hello\\tworld\\n";
    escape(s, t);
    printf("%s\n", s);

    char m[100];
    char n[] = "Hello\\tworld\\n";
    unescape(m, n);
    printf("%s\n", m);
}

void escape(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (t[j] != '\0') {
        switch (t[j]) {
            case '\n':
                s[i++] = '\\';
                s[i] = 'n';
                break;
            case '\t':
                s[i++] = '\\';
                s[i] = 't';
                break;
            default:
                s[i] = t[j];
                break;
        }
        i++;
        j++;
    }
    t[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i = 0;
    int j = 0;

    while (t[i] != '\0') {
        if (t[i] == '\\') {
            switch (t[i+1]) {
                case 'n':
                    s[j] = '\n';
                    i++;
                    break;
                case 't':
                    s[j] = '\t';
                    i++;
                    break;
                    // 可以添加更多转义字符的处理
                default:
                    s[j] = t[i];
                    break;
            }
        } else {
            s[j] = t[i];
        }

        i++;
        j++;
    }

    s[j] = '\0';
}