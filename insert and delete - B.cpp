#include <stdio.h>

#define SIZE 100

void displayArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *length, int element, int position) {
    if (*length >= SIZE) {
        printf("Array is full. Insertion not possible.\n");
        return;
    }

    if (position < 0 || position > *length) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *length; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*length)++;
    printf("After insertion:\n");
    displayArray(arr, *length);
}

void deleteElement(int arr[], int *length, int position) {
    if (*length == 0) {
        printf("Array is empty. Deletion not possible.\n");
        return;
    }

    if (position < 0 || position >= *length) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*length)--;
    printf("After deletion:\n");
    displayArray(arr, *length);
}

int main() {
    int arr[SIZE] = {10, 20, 30, 40, 50};
    int length = 5;

    printf("Original array:\n");
    displayArray(arr, length);

    // Insert 25 at position 2
    insertElement(arr, &length, 25, 2);

    // Delete element at position 4
    deleteElement(arr, &length, 4);

    return 0;
}
