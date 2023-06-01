#include <stdio.h>

int pattern(char *str, char *p) {
    int i = 0, j = 0;
    while (str[i] != '\0' && p[j] != '\0')
    {
        if (str[i] == p[j])
        {
            j++;
        }
        else
        {
            j = 0;
        }
        i++;
    }
    return p[j] == '\0';
}

void find_pattern(FILE *fp, char *p) {
    char str[100];
    while (fgets(str, 100, fp) != NULL) {
        if (pattern(str, p)) {
            printf("%s", str);
        }
    }
}

int main() {
    char *filename = "poems.txt";
    char *pattern = "ine";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return 1;
    }
    find_pattern(fp, pattern);
    fclose(fp);
    return 0;
}
