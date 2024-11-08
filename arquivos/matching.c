#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

void matchNames(FILE* file1, FILE* file2, FILE* outputFile) {
    char name1[MAX_NAME_LENGTH];
    char name2[MAX_NAME_LENGTH];

    while (fread(name1, sizeof(char), sizeof(name1), file1) && fread(name2, sizeof(char), sizeof(name2), file2)) {
        // Compare the names and write to the output file if they match
        if (strcmp(name1, name2) == 0) {
            fwrite(name1, sizeof(char), strlen(name1), outputFile);
            fwrite("\n", sizeof(char), 1, outputFile);
        }
    }
}

int main() {
    FILE* file1 = fopen("arquivo1.bin", "rb");
    FILE* file2 = fopen("arquivo2.bin", "rb");
    FILE* outputFile = fopen("arquivo3.bin", "wb");

    if (file1 == NULL || file2 == NULL || outputFile == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    matchNames(file1, file2, outputFile);

    fclose(file1);
    fclose(file2);
    fclose(outputFile);

    return 0;
}
