#include <string.h>
#include "Unity/unity.h"
#include "administration.h"


void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_AddAnimal(void) {
    ANIMAL animal = {"Tom", Cat, 5};
    ANIMAL animalArray[MAXIMUM_ANIMALS] = {};  // Initialize array

    int result = addAnimal(&animal, animalArray, 0);

    TEST_ASSERT_EQUAL(0, result);  // Check if animal was added successfully
    TEST_ASSERT_EQUAL_STRING("Tom", animalArray[0].Name);  // Check if name matches
    TEST_ASSERT_EQUAL(Cat, animalArray[0].Species);  // Check if species matches
    TEST_ASSERT_EQUAL(5, animalArray[0].Age); 
}
void test_RemoveAnimal(void) {
    ANIMAL animalArray[MAXIMUM_ANIMALS] = {{"Tom", Cat, 5}, {"Jerry", Dog, 3}};
    int initialSize = 2;

    int result = removeAnimal("Tom", animalArray, initialSize);

    TEST_ASSERT_EQUAL(1, result);  // Check if one animal was removed
    TEST_ASSERT_EQUAL_STRING("Jerry", animalArray[0].Name);  // Ensure Jerry is still there
}
void test_SortAnimalsByAge(void) {
    ANIMAL animalArray[MAXIMUM_ANIMALS] = {{"Tom", Cat, 5}, {"Jerry", Dog, 3}, {"Spike", Dog, 7}};
    int initialSize = 3;

    int result = sortAnimalsByAge(animalArray, initialSize);
    TEST_ASSERT_EQUAL(0, result);  // Check if sorting was successful
    TEST_ASSERT_EQUAL_STRING("Jerry", animalArray[0].Name);  // Check first animal is youngest
    TEST_ASSERT_EQUAL_STRING("Tom", animalArray[1].Name);  // Check second animal
    TEST_ASSERT_EQUAL_STRING("Spike", animalArray[2].Name);  // Check oldest animal
}

void test_FindAnimalByName(void) {
    ANIMAL animalArray[MAXIMUM_ANIMALS] = {{"Tom", Cat, 5}, {"Jerry", Dog, 3}};
    ANIMAL foundAnimal;
    int initialSize = 2;

    int result = findAnimalByName("dede", animalArray, initialSize, &foundAnimal);

    TEST_ASSERT_EQUAL(1, result);  // Check if animal was found
    TEST_ASSERT_EQUAL_STRING("Tom", foundAnimal.Name);  // Check if name matches
    TEST_ASSERT_EQUAL(Cat, foundAnimal.Species);  // Check if species matches
    TEST_ASSERT_EQUAL(5, foundAnimal.Age);  // Check if age matches
}
int main (void)
{
        
    UnityBegin();


    RUN_TEST(test_AddAnimal,1);
    RUN_TEST(test_RemoveAnimal,2);
    RUN_TEST(test_SortAnimalsByAge,3);
    RUN_TEST(test_FindAnimalByName,4);
    return UnityEnd();
}
