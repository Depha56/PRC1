#include <stdio.h>
#include <stdlib.h>
#include "file_element.h"
#include "animal.h"
#define FILENAME "animals.txt"

int saveAnimalsToFile(const ANIMAL *animalArray, int size)
{
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL)
    {
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%s %d %d\n", animalArray[i].Name, animalArray[i].Species, animalArray[i].Age);
    }

    fclose(file);
    return 1;
}

int readAnimalsFromFile(ANIMAL *animalArray, int maxSize, int *currentSize)
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        return 0;
    }

    *currentSize = 0;
    while (*currentSize < maxSize && fscanf(file, "%s %d %d", animalArray[*currentSize].Name,
                                            (int *)&animalArray[*currentSize].Species,
                                            &animalArray[*currentSize].Age) == 3)
    {
        (*currentSize)++;
    }

    fclose(file);
    return 1;
}
