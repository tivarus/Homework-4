#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE* file_graph;
    char symbol;
    int ribs = 0, numbers = 0, first, second, Loop = 0, j = 1;

    file_graph = fopen("graph.txt", "r");
    while ((symbol = getc(file_graph)) != EOF) {
        if (symbol == '\n') {
            ribs++;
        }
    }
    --ribs;
    fclose(file_graph);

    numbers = ribs * 2;
    int* array;
    array = (int*)malloc(numbers * sizeof(int));
    file_graph = fopen("graph.txt", "r");
    fscanf(file_graph, "graph {");
    for (int i = 0; i < numbers; i += 2) {
        fscanf(file_graph, "    %d -- %d;", &first, &second);
        array[i] = first;
        array[i + 1] = second;
    }
    fclose(file_graph);

    for (int i = 0; i < numbers; i += 2) {
        if (array[i] == array[i + 1]) {
            if (j == 1) {
                printf("Loops:\n");
            }
            printf("Loop %d is %d -- %d;\n", j, array[i], array[i + 1]);
            Loop = 1;
            ++j;
        }
    }
    if (Loop == 0) {
        printf("Loops not found");
    }
}
