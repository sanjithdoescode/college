#include <stdio.h>

int main() {
    printf("Numbers from 1 to 100 divisible by 2 and not divisible by 3 and 5:\n");
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0 && i % 3 != 0 && i % 5 != 0)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
