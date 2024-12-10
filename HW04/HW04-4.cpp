#include <stdio.h>

int main() {
    float h, w, area;
    printf("Enter H & W: ");
    scanf("%f %f", &h, &w);

    area = (h * w) / 2;

    printf("Triangle Area: %.1f\n", area);

    return 0;
}
