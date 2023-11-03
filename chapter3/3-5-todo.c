#include <stdio.h>
#include <limits.h>

void escape(char s[], char t[]);

void unescape(char s[], char t[]);

/**
 * 练习3-5 编写函数 itob(n，s，b)，将整数n转换为以b为底的数，并将转换结果以字符的形式保存到字符串s中。
 * 例如，itob(n，s,16)把整数n格式化成十六进制整数保存在s中。
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