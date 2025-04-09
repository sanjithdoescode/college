#include <stdio.h>
#define PI 3.14159

int main() {
    float radius, height;
    printf("Enter radius and height of the cylinder: ");
    scanf("%f %f", &radius, &height);
    float csa = 2 * PI * radius * height;
    printf("Curved Surface Area of cylinder = %.2f\n", csa);
    return 0;
}
