#include <stdio.h>
int *GetSet(int *num) {
    static int data[100]; // ใช้ static array เพื่อคืนค่า pointer ไปยังอาร์เรย์
    printf("Enter the number of elements: ");
    scanf("%d", num); // รับจำนวนสมาชิก

    if (*num > 100) { // ตรวจสอบว่าเกินขนาดสูงสุดหรือไม่
        printf("Error: Maximum number of elements is 100.\n");
        *num = 0; // ตั้งค่า num เป็น 0 เพื่อป้องกันข้อผิดพลาด
        return NULL;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < *num; i++) {
        scanf("%d", &data[i]); // รับค่าของสมาชิกในเซต
    }

    return data; // คืน pointer ไปยัง static array
}

int main() {
    int *data, num;

    // เรียกใช้ฟังก์ชัน GetSet() เพื่อรับข้อมูล
    data = GetSet(&num);

    // ตรวจสอบว่า data ไม่เป็น NULL ก่อนแสดงผล
    if (data != NULL) {
        printf("Number of elements: %d\n", num);
        for (int i = 0; i < num; i++) {
            printf("%d ", data[i]); // แสดงผลค่าของสมาชิก
        }
        printf("\n");
    }

    return 0;
}
