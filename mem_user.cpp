#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

#define ARRAY_X 1000 * 15
#define ARRAY_Y 1000000

void print_mem_usage() {
    FILE* file = fopen("/proc/self/status", "r");
    char line[128];

    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            cout << line;
            break;
        }
    }

    fclose(file);
}

int main() {
    char **tmp = new char* [ARRAY_X];
    for (int i = 0; i < ARRAY_X; i++) {
        tmp[i] = new char[ARRAY_Y];
        for (int j = 0; j < ARRAY_Y; j++) {
            tmp[i][j] = (i * j) % 26 + 'A';
        }
        print_mem_usage();
    }

    getchar();
    return 0;
}
