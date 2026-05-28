#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    
    int sum = 0;
    char str[100];
    int num;
    char extra;

    while (fscanf(fp, "%s", str) == 1) {
        if (sscanf(str, "%d%c", &num, &extra) == 1) {
            sum += num;
        }
        else {
            fprintf(stderr, "invalid input %s\n", str);
        }
    }
    
    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
