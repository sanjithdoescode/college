#include <stdio.h>
#define PI 3.14159

int main() {
    float radius;
    printf("Enter radius of circle: ");
    scanf("%f", &radius);
    float perimeter = 2 * PI * radius;
    printf("Perimeter of circle = %.2f\n", perimeter);
    return 0;
}
