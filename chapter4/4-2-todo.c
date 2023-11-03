#include <stdio.h>
#include <stdlib.h>

int strindex(char s[], char t[]);

/**
 * 练习 4-2 对atof 函数进行扩充，使它可以处理形如123.45e-6的科学表示法，
 * 其中，浮点数后面可能会紧跟一个e或E以及一个指数（可能有正负号)。
 */
int main() {
    printf("%f\n", atof("421.321"));

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