#include <stdio.h>
#include <limits.h>

void escape(char s[], char t[]);

void unescape(char s[], char t[]);

/**
 * 练习3-2 编写一个函数 escape(s，t)，将字符串t复制到字符串s中，并在复制过程中
 * 将换行符、制表符等不可见字符分别转换为\n、\t 等相应的可见的转义字符序列。要求使用 switch 语句。
 * 再编写一个具有相反功能的函数，在复制过程中将转义字符序列转换为实际字符。
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