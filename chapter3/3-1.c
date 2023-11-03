#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000
#define TAB_WIDTH 4

int binsearch(int x, int v[], int n);

/**
 * 练习3-1 在上面有关折半查找的例子中，while 循环语句内共执行了两次测试，
 * 其实只要一次就足够（代价是将更多的测试在循环外执行)。重写该函数，
 * 使得在循环内部只执行一次测试。比较两种版本函数的运行时间。
 */
int main() {

}

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (x == v[mid]) {
            return mid;
        }

        if (x > v[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

/**
 * 优化版本, 当满足v[mid] >= x时, low不会在变化
 */
int binsearch2(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (v[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (low < n && v[low] == x) {
        return low;
    }
    return -1;
}