#ifndef _FILE_ELEMENT_H
#define _FILE_ELEMENT_H

#include "animal.h"

int saveAnimalsToFile(const ANIMAL* animalArray, int size);
/* 
 * Saves the animals from the array to a text file.
 * Returns 1 on success, 0 on failure.
 */

int readAnimalsFromFile(ANIMAL* animalArray, int maxSize, int* currentSize);
/* 
 * Reads animals from a text file into the array.
 * Returns 1 on success, 0 on failure.
 */

#endif
