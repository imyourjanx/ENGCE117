#include <stdio.h>

int main() {
    char fn[500];
    char ln[500];
    printf("First Name: ");
    scanf("%s", &fn);
    printf("Last Name: ");
    scanf("%s", &ln);
    printf("%s %s TC, RMUTL, Chiang Mai, Thailand\n", fn, ln);

    return 0;
}
