#include <stdio.h>

#define TAB_WIDTH 4

void entab(int tabWidth);

/**
 * 练习1-24 编写一个程序，查找C语言程序中的基本语法错误，如圆括号、方括号、花括号不配对等。
 * 要正确处理引号（包括单引号和双引号)、转义字符序列与注释。（如果读者想把该程序编写成完全通用的程序，难度会比较大。）
 */
int main() {
    entab(TAB_WIDTH);
}


void entab(int tabWidth) {
    int c;
    int i = 0;
    // 连续空格的计数
    int spaceCount = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaceCount++;
            i++;
        } else if (c == '\n') {
            putchar(c);
            i = 0;
        } else {
            // 根据规则选择替换字符
            if (spaceCount > 0) {
                int gap = tabWidth - ((i - spaceCount) % tabWidth);
                // 补全第一个制表符(<=tabWidth)
                if (spaceCount >= gap) {
                    putchar('\t');
                    spaceCount -= gap;
                }
                // 如果剩余的空格大于tabWidth, 说明还可以添加制表符
                while (spaceCount >= tabWidth) {
                    putchar('\t');
                    spaceCount -= tabWidth;
                }
                // 剩余不足制表符的空格用空格补全
                while (spaceCount > 0) {
                    putchar(' ');
                    spaceCount--;
                }
            }
            putchar(c);
            i++;
        }
    }
}