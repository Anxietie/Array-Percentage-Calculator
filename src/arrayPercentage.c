#include <stdio.h>
#include <stdlib.h>

// Type of array
#define type float

// Dynamic Array struct
typedef struct {
    unsigned int size; 
    type* arr; 
} dynamicArray;

// Initialize dynamicArray variables
void dynamicInit(dynamicArray* a) { 
    a->size = 0;
    a->arr = NULL;
}

// 1 = Failure, 0 = Success
// Add a single value to dynamicArray pointer
int dynamicAddVal(dynamicArray* a, type val) {
    // Init function
    if (a->size == 0) {
        a->size = 1;
        a->arr = (type*)malloc(sizeof(*a->arr));
        if (a->arr != NULL) { *a->arr = (type)val; return 0; }
    }
    // Add Function
    else {
        a->size++;
        type* temp = (type*)realloc(a->arr, sizeof(*a->arr) * a->size);
        if (temp != NULL) {
            a->arr = temp;
            a->arr[a->size - 1] = (type)val;
            return 0;
        }
    }
    return 1;
}

// free() function with extra steps
void dynamicFree(dynamicArray* a) {
    a->size = 0;
    free(a->arr);
}

// Gets the highest occuring value and returns its index for computation at the end
int getMaxIndex(dynamicArray* a, type* array) {
    int index = 0; // Most common element at index
    int max = 0; // Biggest occurrence number
    for (int i = 0; i < 2*a->size; i++) { array[i] = 0.0f; } // Set array values to 0
    // Checks if an element from the input is in the stored section of our "stored_occurred" array,
    // then initializes and increments values accordingly
    for (int i = 0; i < a->size; i++) {
        for (int x = 0; x < a->size; x++) {
            // Checking if its stored
            if (a->arr[i] == array[x]) {
                array[x+a->size] += 1;
                break;
            }
            // Initializing
            else if (array[x] == 0) {
                array[x] = (type)a->arr[i];
                array[x+a->size] += 1;
                break;
            }
        }
    }
    // Gets max index based on the values we computed before
    for (int i = 0; i < a->size; i++) {
        // Loops through each occurence value and checks if its greater than "max"
        // (0 by default, increases if the next value is greater)
        if (array[i+a->size] > max) {
            index = i;
            max = array[i+a->size];
        }
    }
    return index;
}

int main() {
    dynamicArray arr;
    dynamicInit(&arr); // Initialize the dynamic array
    float inputBuffer; // Input
    // Takes each input and adds it to the dynamic array
    printf("type \"-1\" to stop\n");
    for (;;) {
        printf("Enter value: ");
        scanf("%f", &inputBuffer);
        if (inputBuffer==-1.0f) {
            break;
        }
        else {
            dynamicAddVal(&arr, inputBuffer);
        }
    }
    // Creates the stored_occurred array using malloc for convenience
    type* stored_occurred = (type*)malloc((2*(arr.size))*sizeof(type));
    int index = getMaxIndex(&arr, stored_occurred);
    // Calculates the percentage based on the index returned from the function above
    printf("%g has the highest chance with %%%g\n", 
        stored_occurred[index], ((stored_occurred[index+arr.size])/(float)arr.size)*100);
    dynamicFree(&arr);
    return 0;
}
