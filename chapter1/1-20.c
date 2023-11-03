#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 4

void detab(int tabWidth);

/**
 * 练习 1-20 编写程序 detab，将输入中的制表符替换成适当数目的空格，使空格充满到 下一个制表符终止位的地方。
 * 假设制表符终止位的位置是固定的，比如每隔 n列就会出现一 个制表符终止位。n应该作为变量还是符号常量呢？
 */
int main() {
    detab(TAB_WIDTH);
}


void detab(int tabWidth) {
    int c, i, numSpaces;
    i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            numSpaces = tabWidth - (i % tabWidth);
            for (int j = 0; j < numSpaces; j++) {
                putchar(' ');
                i++;
            }
        } else if (c == '\n') {
            putchar(c);
            i = 0;
        } else {
            putchar(c);
            i++;
        }
    }
}