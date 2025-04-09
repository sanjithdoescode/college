#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char ch;
    src = fopen("source.txt", "r");
    if (src == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }
    dest = fopen("destination.txt", "w");
    if (dest == NULL) {
        printf("Error opening destination file.\n");
        fclose(src);
        return 1;
    }
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
    printf("File copied successfully.\n");
    fclose(src);
    fclose(dest);
    return 0;
}
