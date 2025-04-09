#include <stdio.h>
#define PI 3.14159

int main() {
    float radius;
    printf("Enter radius of circle: ");
    scanf("%f", &radius);
    float area = PI * radius * radius;
    printf("Area of circle = %.2f\n", area);
    return 0;
}
