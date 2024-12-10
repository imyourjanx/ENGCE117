#include <stdio.h>

// ฟังก์ชัน GetSet รับข้อมูลสมาชิกในเซต และคืนค่าจำนวนสมาชิก
int GetSet(int data[]) {
    int num;
    printf("Enter the number of elements: ");
    scanf("%d", &num); // รับจำนวนสมาชิก

    printf("Enter the elements: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &data[i]); // รับค่าของสมาชิกแต่ละตัว
    }

    return num; // คืนค่าจำนวนสมาชิก
}

int main() {
    int data[100]; // อาร์เรย์ที่เก็บสมาชิกในเซต (ขนาดคงที่ 100 ตัว)
    int num;       // ตัวแปรเก็บจำนวนสมาชิกในเซต

    // เรียกใช้ฟังก์ชัน GetSet และรับจำนวนสมาชิก
    num = GetSet(data);

    // แสดงจำนวนสมาชิกและค่าของสมาชิกในเซต
    printf("Number of elements: %d\n", num);
    for (int i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
