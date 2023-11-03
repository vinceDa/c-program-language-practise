#include <stdio.h>
#include <string.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char  *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/**
 *练习 5-7 重写函数 readlines，将输入的文本行存储到由 main 函数提供的一个数组中，
 * 而不是存储到调用 alloc 分配的存储空间中。该函数的运行速度比改写前快多少？
 */
int main() {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }

    printf("error: input too big to sort\n");
    return 1;

}

#define MAXLEN 1000;
int getLine(char *, int);
char *alloc(int);

int readlines(char  *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[1000];
    nlines = 0;
    while ((len = getLine(line, 1000)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

int getLine(char *s, int limit) {
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
        i++;
    }
    *s = '\0';
    return i;
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
