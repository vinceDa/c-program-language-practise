#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000
#define TAB_WIDTH 4

void detab(int tabWidth);

/**
 * 练习2-1 编写一个程序以确定分别由 signed及 unsigned 限定的 char、short、int 与long 类型变量的取值范围。
 * 采用打印标准头文件中的相应值以及直接计算两种方式实现。
 * 后一种方法的实现较困难一些，因为要确定各种浮点类型的取值范围。
 */
int main() {
    char c = 'dsadsa';
    printf("%d ~ %d\n", CHAR_MIN, CHAR_MAX);
    printf("%d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("%d ~ %d\n", INT_MIN, INT_MAX);
    printf("%ld ~ %ld\n", LONG_MIN, LONG_MAX);

    printf("%d ~ %d\n", 0, UCHAR_MAX);
    printf("%d ~ %d\n", 0, USHRT_MAX);
    printf("%d ~ %d\n", 0, UINT_MAX);
    printf("%ld ~ %ld\n", 0L, ULONG_MAX);

    printf("%d ~ %d\n", 0, CHAR_MAX - CHAR_MIN);
    printf("%d ~ %d\n", 0, SHRT_MAX - SHRT_MIN);
    printf("%d ~ %d\n", 0, INT_MAX - INT_MIN);
    printf("%ld ~ %ld\n", 0L, LONG_MAX - LONG_MIN);


}