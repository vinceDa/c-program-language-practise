#include <stdio.h>

#define TAB_WIDTH 4

void entab(int tabWidth);

/**
 * 练习1-23 编写一个删除C语言程序中所有的注释语句。
 * 要正确处理带引号的字符串与字符常量。在C语言中，注释不允许嵌套。
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