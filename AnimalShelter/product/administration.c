#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "administration.h"
int addAnimal(const ANIMAL *animalPtr, ANIMAL *animalArray, int position)
{
    // Check if the specified position is within valid bounds
    if (position < 0 || position >= MAXIMUM_ANIMALS)
    {
        // Invalid position, return an error code
        return -1;
    }
    else
    {
        animalArray[position] = *animalPtr;
        return 0;
    }
}

int removeAnimal(const char *name, ANIMAL *animalArray, int number)
{

    int counter = 0;
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < number; readIndex++)
    {
        // check if name in given size matches
        if (strcmp(animalArray[readIndex].Name, name) != 0)
        {
            animalArray[writeIndex++] = animalArray[readIndex];
        }
        else
        {
            counter++;
        }
    }

    return counter;
}

int sortAnimalsByAge(ANIMAL *animalArray, int animalArrayLength)
{
    // no input in the array
    if (animalArray == NULL || animalArrayLength <= 0)
    {
        return -1;
    }

    int i, j;
    for (i = 0; i < animalArrayLength - 1; i++)
    {
        for (j = 0; j < animalArrayLength - 1 - i; j++)
        {
            if (animalArray[j].Age > animalArray[j + 1].Age)
            {
                // Swap the animals
                ANIMAL temp = animalArray[j];
                animalArray[j] = animalArray[j + 1];
                animalArray[j + 1] = temp;
            }
        }
    }

    return 0; // Return 0 on success
}
int findAnimalByName(const char *name, const ANIMAL *animalArray,
                     int animalArrayLength, ANIMAL *animalPtr)
{
    for (int i = 0; i < animalArrayLength; i++)
    {
        if (strcmp(name, animalArray[i].Name) == 0)
        {
            *animalPtr = animalArray[i];
            return 1;
        }
    }
    return 0;
}
