#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ฟังก์ชัน reverse: กลับข้อความ str1 และคืนค่าผลลัพธ์เป็นสตริงใหม่
char* reverse(char str1[]) {
    int len = strlen(str1); // ความยาวของ str1
    char *reversed = (char *)malloc((len + 1) * sizeof(char)); // จองหน่วยความจำสำหรับผลลัพธ์
    if (reversed == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        reversed[i] = str1[len - i - 1]; // ก๊อปปี้ตัวอักษรจากท้ายมาหัว
    }
    reversed[len] = '\0'; // ใส่ null-terminator ที่ท้าย

    return reversed; // คืนค่าผลลัพธ์
}

int main() {
    char text[50]; // เก็บข้อความต้นฉบับ
    char *out;     // ตัวชี้สำหรับเก็บผลลัพธ์

    // รับข้อความจากผู้ใช้
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // ลบ newline character (ถ้ามี) จากการใช้ fgets
    text[strcspn(text, "\n")] = '\0';

    // เรียกใช้ฟังก์ชัน reverse
    out = reverse(text);

    // แสดงผลลัพธ์
    printf("Reversed: %s\n", out);

    // คืนหน่วยความจำ
    free(out);

    return 0;
}
