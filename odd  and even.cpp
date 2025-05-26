#include <stdio.h>
int main() {
    int arr[] = {21,54,33,81,60,49,44,28,13,56};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Even numbers:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\nOdd numbers:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
	 return 0;
}
