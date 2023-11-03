#include <stdio.h>
#include <limits.h>

void escape(char s[], char t[]);

void unescape(char s[], char t[]);

/**
 * 练习3-6 修改 itoa 函数，使得该函数可以接收三个参数。其中，第三个参数为最小字段宽度。
 * 为了保证转换后所得的结果至少具有第三个参数指定的最小宽度，在必要时应在所得结果的左边填充一定的空格。
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