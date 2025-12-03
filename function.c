#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *LoadString(int N) {
    char *p = (char *)malloc((N + 1) * sizeof(char));
    if (p == NULL) return NULL;
    printf("Enter string: ");
    scanf("%s", p);
    return p;
}

int StringLength(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void LoadArray(char *p, char arr[]) {
    int i = 0;
    while (p[i] != '\0') {
        arr[i] = p[i];
        i++;
    }
    arr[i] = '\0';
}

void ReverseArray(char arr[], char rev[], int n) {
    for (int i = 0; i < n; i++)
        rev[i] = arr[n - 1 - i];
    rev[n] = '\0';
}

void DisplayArray(char arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%c", arr[i]);
    printf("\n");
}

int SumStringASCII(char *p) {
    if (*p == '\0') return 0;
    return *p + SumStringASCII(p + 1);
}

void ReverseString(char *start, char *end) {
    if (start >= end) return;
    char temp = *start;
    *start = *end;
    *end = temp;
    ReverseString(start + 1, end - 1);
}

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
