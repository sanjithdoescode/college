#include <stdio.h>

int main() {
    int n, key, index = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }
    if (index != -1)
        printf("Element %d found at index %d.\n", key, index);
    else
        printf("Element not found.\n");
    return 0;
}
