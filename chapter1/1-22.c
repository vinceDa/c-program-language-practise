#include <stdio.h>

#define NEXT_LINE_WIDTH 10

void sub(int nextLineWidth);

/**
 * 练习 1-22 编写一个程序，把较长的输入行“折”成短一些的两行或多行，折行的位置在输入行的第 n列之前的最后一个非空格之后。
 * 要保证程序能够智能地处理输入行很长以及在指定的列前没有空格或制表符时的情况。
 */
int main() {
    sub(NEXT_LINE_WIDTH);
}


void sub(int nextLineWidth) {
    int c;
    int charCount = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            putchar('\n');
            charCount = 0;
        } else if (charCount == nextLineWidth - 1) {
            putchar(c);
            putchar('\n');
            charCount = 0;
        } else{
            putchar(c);
            charCount++;
        }
    }
}