#include <stdio.h>
int main() {
    int n;
    printf("ค่าที่ต้องการ: ");
    scanf("%d", &n);//รับค่าจำนวนเต็มเก็บไว้ในn
//กำหนดค่าเริ่มต้น; i น้อยกว่าเท่ากับ n ให้ i+1
    for (int i = 1; i <= n; i++) {
        printf("[%d] Hello World\n", i);
    }
    return 0;
}
