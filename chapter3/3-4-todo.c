#include <stdio.h>
#include <limits.h>

void escape(char s[], char t[]);

void unescape(char s[], char t[]);

/**
 * 练习 3-4在数的对二的补码表示中，我们编写的 itoa函数不能处理最大的负数，即n等于-2^(字长-1) 的情况。请解释其原因。修改该函数，
 * 使它在任何机器上运行时都能打印出正确的值。
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