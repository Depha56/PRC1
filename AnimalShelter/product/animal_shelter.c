

#include <stdio.h>
#include <string.h>
#include "animal.h"
#include "administration.h"
#include "file_element.h"

const char *SpeciesNames[] = {"Cat", "Dog", "Guinea pig", "Parrot"};

// Function to display details of all animals in the array
void showAnimals(ANIMAL *animals, int currentSize)
{
    if (currentSize == 0)
    {
        printf("No animals in the shelter.\n");
    }
    else
    {
        printf("Animals in the shelter:\n");
        for (int i = 0; i < currentSize; i++)
        {
            printf("Name: %s, Species: %s, Age: %d\n", animals[i].Name, SpeciesNames[(animals[i].Species)], animals[i].Age);
        }
    }
}
int main(void)
{
    ANIMAL animals[MAXIMUM_ANIMALS];
    int currentSize = 0;
    if (!readAnimalsFromFile(animals, MAXIMUM_ANIMALS, &currentSize))
    {
        printf("Error loading animals from file.\n");
    }
    printf("PRC assignment 'Animal Shelter' (version april 2019)\n");

    int choice = -1;
    while (choice != 0)
    {
        printf("\nMENU\n====\n");
        printf("1: Show Animals \n");
        printf("2: Add Animal \n");
        printf("3: Remove Animal \n");
        printf("4: Sort Animal By Age \n");
        printf("5: Find Animal by name \n");
        printf("0: quit \n");

        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1)
        { // Validate input
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n')
                ; // Clear the input buffer
        }

        switch (choice)
        {
        case 1: // Show Animals
            printf("show Animals\n");
            showAnimals(animals, currentSize);
            break;
        case 2: // Add Animal
            if (currentSize >= MAXIMUM_ANIMALS)
            {
                printf("Error: Cannot add more animals, array is full.\n");
                break;
            }
            ANIMAL animal;

            printf("Enter Name: ");
            scanf("%s", animal.Name);
            printf("Enter Species (0: Cat, 1: Dog, 2: GuineaPig, 3: Parrot): ");
            int species;
            scanf("%d", &species);

            // Validate species
            if (species < 0 || species > 3)
            {
                printf("Error: Invalid species. Please enter a valid species (0: Cat, 1: Dog, 2: GuineaPig, 3: Parrot).\n");
                break;
            }
            else
            {
                animal.Species = (SPECIES)species;
            }
            printf("Enter Age: ");
            // Validate age input by checking if  number entered is negative and input of user is
            while (scanf("%d", &animal.Age) != 1 || animal.Age < 0)
            {
                printf("Invalid input. Please enter a valid age as a positive number: ");
                while (getchar() != '\n')
                    ; // Clear the input buffer
            }
            int result = addAnimal(&animal, animals, currentSize);
            if (result == -1)
            {
                printf("Error: Cannot add more animals, array is full.\n");
                break;
            }
            else
            {
                printf("Animal added successfully.\n");
                currentSize++;
            }
            saveAnimalsToFile(animals, currentSize);
            break;
        case 3: // Remove Animal
                // checks if there is no animal in the array
            if (currentSize == 0)
            {
                printf("Error: No animals to remove.\n");
            }
            else
            {
                // if there is animal in array it prompt user to input animal name
                char removeName[20];
                printf("Enter the name of the animal to remove: ");
                scanf("%s", removeName);
                // declare an integer to store number of element going to be removed
                int removedCount = removeAnimal(removeName, animals, currentSize);
                // if that inteeger is grater than zero means there element to be removes
                if (removedCount > 0)
                {
                    // so the current size of array reduced
                    currentSize -= removedCount;
                    printf("Successfully removed %d animal(s) with the name '%s'.\n", removedCount, removeName);
                }
                else
                {
                    // message when name you write does not includ in array
                    printf("No animals were removed. No animal with the name '%s' found.\n", removeName);
                }
            }
            saveAnimalsToFile(animals, currentSize);
            break;
        case 4: // Sort Animal By Age
                // sort animal by age it has two parameters first one help us to know number of element in the array and animal is pointer to that aaray that are going to be sorted
            if (sortAnimalsByAge(animals, currentSize) == 0)
            {
                printf("Animals sorted by age successfully.\n");
            }
            else
            {
                printf("Error: Could not sort animals bcz there is no animal.\n");
            }
            saveAnimalsToFile(animals, currentSize);
            break;
        case 5: // find animal by name
        {
            char findName[25];
            printf("Enter the name of the animal to find: ");
            scanf("%s", findName);

            ANIMAL foundAnimal;
            int resultAnimal = findAnimalByName(findName, animals, currentSize, &foundAnimal);

            if (resultAnimal == 1)
            {
                printf("Found animal:\n");
                printf("Name: %s, Species: %s, Age: %d\n", foundAnimal.Name, SpeciesNames[(int)foundAnimal.Species], foundAnimal.Age);
            }
            else
            //(resultAnimal == 0 && currentSize == 0);
            {
                printf("No animal found with the name '%s'.\n", findName);
            }
            
        }
        break;
        case 0:
            saveAnimalsToFile(animals, currentSize);
            break;
        default:
            printf("ERROR: invalid choice please enter positive number: %d\n", choice);
            break;
        }
    }
    return 0;
}
