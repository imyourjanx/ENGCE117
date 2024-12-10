#include <stdio.h>

// ฟังก์ชัน GetMatrix: รับจำนวนแถว คอลัมน์ และค่าในเมทริกซ์
int* GetMatrix(int *row, int *col) {
    static int matrix[100][100]; // Static 2D array (ขนาดสูงสุด 100x100)
    int totalElements;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", row, col); // รับจำนวนแถวและคอลัมน์

    // ตรวจสอบเงื่อนไข: ถ้าจำนวนแถวหรือคอลัมน์เป็น 0 ให้คืนค่า NULL
    if (*row <= 0 || *col <= 0) {
        printf("Error: Invalid matrix input\n");
        return NULL;
    }

    totalElements = (*row) * (*col); // คำนวณจำนวนสมาชิกทั้งหมดในเมทริกซ์
    printf("Enter matrix elements:\n");

    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) { // ตรวจสอบความถูกต้องของอินพุต
                printf("Error: Invalid matrix input\n");
                return NULL;
            }
        }
    }

    // คืนค่า pointer ของเมทริกซ์
    return (int*)matrix;
}

int main() {
    int *data, m, n;

    // เรียกใช้ฟังก์ชัน GetMatrix เพื่อรับข้อมูลเมทริกซ์
    data = GetMatrix(&m, &n);

    // ถ้า data เป็น NULL แสดงว่าเกิดข้อผิดพลาด
    if (data == NULL) {
        return 1; // ออกจากโปรแกรม
    }

    // แสดงผลเมทริกซ์
    printf("Matrix (%dx%d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *((data + i * n) + j)); // คำนวณตำแหน่งในเมทริกซ์
        }
        printf("\n");
    }

    return 0;
}
