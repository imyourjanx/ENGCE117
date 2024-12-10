#include <stdio.h>
// ฟังก์ชัน GetSet: รับจำนวนสมาชิกและค่าของสมาชิกใน array
void GetSet(int data[], int *num) {
    printf("กรอกจำนวน: ");
    scanf("%d", num); // รับจำนวนสมาชิกในเซต
    printf("กรอกตัวเลข: ");
    for (int i = 0; i < *num; i++) {
        scanf("%d", &data[i]); // รับค่าของสมาชิกแต่ละตัว
    }
}

int main() {
    int data[100]; // กำหนด array ขนาดคงที่ (สูงสุด 100 ตัว)
    int num;       // ตัวแปรสำหรับเก็บจำนวนสมาชิกในเซต

    // เรียกใช้ฟังก์ชัน GetSet เพื่อรับข้อมูลจากผู้ใช้
    GetSet(data, &num);

    // แสดงค่าของสมาชิกในเซต
    printf("ผลลัพธ์คือ: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
