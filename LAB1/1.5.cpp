#include <stdio.h>

void GetMatrix(int value[], int *row, int *col) {
    printf("Enter the number of rows: ");
    scanf("%d", row); // รับจำนวนแถว
    printf("Enter the number of columns: ");
    scanf("%d", col); // รับจำนวนคอลัมน์

    printf("Enter the matrix elements: ");
    for (int i = 0; i < (*row) * (*col); i++) {
        scanf("%d", &value[i]); // รับค่าของแต่ละสมาชิกในเมทริกซ์
    }
}

int main() {
    int value[100]; // Static array ขนาดคงที่ (เก็บได้สูงสุด 100 ค่า)
    int m, n;       // จำนวนแถวและคอลัมน์ในเมทริกซ์

    // เรียกใช้ฟังก์ชัน GetMatrix เพื่อรับข้อมูล
    GetMatrix(value, &m, &n);

    // แสดงผลเมทริกซ์
    printf("Matrix (%dx%d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", value[i * n + j]); // คำนวณตำแหน่งในอาร์เรย์ 1 มิติ
        }
        printf("\n");
    }

    return 0;
}
