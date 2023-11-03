#include <stdio.h>

#define TAB_WIDTH 4

void entab(int tabWidth);

/**
 * 练习1-21 编写程序 entab，将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变。
 * 假设制表符终止位的位置与练习1-20 的 detab 程序的情况相同。
 * 当使用一个制表符或者一个空格都可以到达下一个制表符终止位时，选用哪一种替换字符比较好？
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