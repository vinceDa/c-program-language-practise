#include <stdio.h>
#include <limits.h>

int setbits(int x, int p, int n, int y);

/**
 * 练习 2-6  编写一个函数 setbits(x，p，n，y)，该函数返回对x执行下列操作后
 * 的结果值：将x中从第p位开始的n个（二进制）位设置为y中最右边 n位的值，x的其余
 * 各位保持不变。
 */
int main() {
    printf("%d\n", setbits(1276, 3, 5, 136));
}

int setbits(int x, int p, int n, int y) {
   return (x >> (p + 1 - n) &  (~0 | (y >> n) << n));
}