#include <stdio.h>
#include <string.h>

/**
 * 练习 5-9 用指针方式代替数组下标方式改写函数 day_of_year 和 month_day。
 */
int main() {
    int day_of_year(int, int, int);
    void month_day (int, int, int *, int *);


    printf("%d\n", day_of_year(2023, 11, 3));

    int month;
    int day;
    month_day(2023, 110, &month, &day);
    printf("month: %d, day: %d\n", month, day);
}

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {

    if (month > 12) {
        printf("error month: %d", month);
        return -1;
    }
    if (day > 31) {
        printf("error day: %d", day);
        return -1;
    }

    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++) {
        day += *(daytab + leap)[i];
    }
    return day;
}

void month_day (int year, int yearday, int *pmonth, int *pday) {
    if (yearday > 366) {
        printf("error yearday: %d", yearday);
        return;
    }

    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= *(daytab + leap)[i];
    }
    *pmonth = i;
    *pday = yearday;
}