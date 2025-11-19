#include <stdio.h>
#include <stdlib.h>
#include "function.c"
int main() {
    int N;
    printf("Enter string size: ");
    scanf("%d", &N);

    char *p = LoadString(N);
    int len = StringLength(p);

    char arr[100], rev[100];
    LoadArray(p, arr);
    ReverseArray(arr, rev, len);

    printf("Original: ");
    DisplayArray(arr, len);
    printf("Reversed: ");
    DisplayArray(rev, len);

    printf("ASCII Sum: %d\n", SumStringASCII(p));

    ReverseString(p, p + len - 1);
    printf("Reversed In-Place: %s\n", p);

    free(p);
    return 0;
}
