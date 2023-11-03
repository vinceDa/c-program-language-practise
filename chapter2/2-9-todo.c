#include <stdio.h>
#include <limits.h>

int findFirst(char s1[], char s2[]);
int getLen(char s[]);

/**
 * 练习2-9 在求对二的补码时，表达式x&=（x— 1)可以删除x中最右边值为1的个二进制位。
 * 请解释这样做的道理。用这一方法重写 bitcount 函数，以加快其执行速度。
 *
 * 表达式 x &= (x - 1) 可以用于删除 x 中最右边值为 1 的二进制位。这一操作的原理是基于补码表示中的性质，
 * 即 x 和 x - 1 在二进制表示中有相同的最高位，但是最右边值为 1 的二进制位被清除。
 * 具体解释如下：
 *
 * 假设 x 的二进制表示为 ...1000，其中最右边值为 1 的二进制位是第 n 位（从右边开始计数）。
 * x - 1 的二进制表示将最右边的 1 变为 0，而该位右边的所有位都变为 1，即 ...0111。
 * 使用按位与操作 x &= (x - 1)，将 x 与 x - 1 进行按位与运算，结果将把第 n 位及其右边的所有位都设置为 0，即将最右边值为 1 的二进制位删除。
 */
int main() {
    printf("%d\n", findFirst( "abadeq", "h"));
}

int findFirst(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' ; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;

}